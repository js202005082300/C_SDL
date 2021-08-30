#include "game.h"
#include "map.h"

void SDL_versionUsed(void)
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Bienvenue sur la SDL %d.%d.%d !\n",nb.major, nb.minor, nb.patch);
}

void SDL_gameManager(void)
{
    App *app = NULL;
    Map *map = NULL;
    Player *joueur = NULL;
    
    joueur = new_player("Buble Buble");
    joueur->score += 5;
    joueur->position->X += 3;
    joueur->position->Y += 6;
    // print_player(joueur);
    save_game(joueur);
    free_player(joueur);

    // Initialisation
    app = SDL_initGame();
    //
    // Ici TTF_init()
    //
    map = new_map(MAP02);
    // printMapToTheConsole(map);

    // Texture
    SDL_Texture *texture_background = SDL_loadTexture("src/pics/background-scroll.png", app);
    SDL_Texture *texture_player = SDL_loadTexture("src/pics/sprite-100.png", app);
    SDL_Texture *texture_brick = SDL_loadTexture("src/pics/brick-10.png", app);
    if(texture_background == NULL || texture_player == NULL || texture_brick == NULL)
    { exit(1); }

    // Evenement
    SDL_bool program_launched = SDL_TRUE; 
    SDL_bool *ptr = &program_launched;
    int *X = &joueur->position->X;
    int *Y = &joueur->position->Y;
    int *Xs = &map->position->xscroll;
    int *Ys = &map->position->yscroll;
    int minX, minY, maxX, maxY;

    while(*ptr)
    {
        // Entrée au clavier
        SDL_doInput(ptr, X, Y);

        /* ------ RECHERCHE A PROPOS DU SCROLL -------- */
        *Xs = *X + 50 - WINDOW_WIDTH/2;     if(*Xs<0){ *Xs=0; } if(*Xs>map->size->columns*SQUARE_SIZE - WINDOW_WIDTH){ *Xs=map->size->columns*SQUARE_SIZE - WINDOW_WIDTH; }
        *Ys = *Y + 50 - WINDOW_HEIGHT/2;    if(*Ys<0){ *Ys=0; } if(*Ys>map->size->rows*SQUARE_SIZE - WINDOW_HEIGHT){ *Ys=map->size->rows*SQUARE_SIZE - WINDOW_HEIGHT; }

        minX=*Xs / SQUARE_SIZE;
        minY=*Ys / SQUARE_SIZE;
        maxX=(*Xs + WINDOW_WIDTH) / SQUARE_SIZE;
        maxY=(*Ys + WINDOW_HEIGHT) / SQUARE_SIZE;
        /* -------------------------------------------- */

        // Affichage
        SDL_renderTexture(texture_background, app, 0 - *Xs, 0 - *Ys); //scroll à appliquer
        SDL_renderTexture(texture_player, app, *X - *Xs, *Y - *Ys); //scroll à appliquer
        for(int i=minY ; i < maxY ; i++)
            for(int j=minX ; j < maxX ; j++)
                if(map->matrix[i][j] == '1')
                    SDL_renderTexture(texture_brick, app, j*SQUARE_SIZE - *Xs, i*SQUARE_SIZE - *Ys); //scroll à appliquer

        // Gestion rendus
        SDL_RenderPresent(app->renderer);
    }

    //
    // ----------------------- TEST ---------------------------------------
    //
    printf("X : %d | Y : %d\n", *X, *Y);
    printf("WINDOW_WIDTH : %d | WINDOW_HEIGHT : %d | SQUARE_SIZE : %d\n", WINDOW_WIDTH, WINDOW_HEIGHT, SQUARE_SIZE);
    printf("columns : %d | rows : %d\n", map->size->columns, map->size->rows);
    printf("xscroll : %d | yscroll : %d\n", map->position->xscroll, map->position->yscroll);
    printf("Limite X : %d | Limite Y : %d\n", map->size->columns*SQUARE_SIZE - WINDOW_WIDTH, map->size->rows*SQUARE_SIZE - WINDOW_HEIGHT);
    printf("min X : %d | min Y : %d | max X : %d | max Y : %d\n", minX, minY, maxX, maxY);
    // --------------------------------------------------------------------

    // Clean up
    SDL_CleanRessources(NULL, NULL, texture_brick);
    SDL_CleanRessources(NULL, NULL, texture_player);
    SDL_CleanRessources(app->window, app->renderer, texture_background);
    free_map(map);

    TTF_Quit();
    SDL_Quit();
}

App *SDL_initGame(void)
{
    App *app = malloc(sizeof(*app));
    app->window = malloc(sizeof(app->window));
    app->renderer = malloc(sizeof(app->renderer));

    if(app == NULL || app->window == NULL || app->renderer == NULL)
        exit(EXIT_FAILURE);

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
        SDL_ExitWithError("Initialisation SDL echouee");

    //Creation fenetre
    app->window = SDL_CreateWindow("Jeu C/SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(app->window == NULL)
        SDL_ExitWithError("Creation fenetre echouee");

    //Creation rendu
    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_SOFTWARE);
    if(app->renderer == NULL)
    {
        SDL_CleanRessources(app->window, NULL, NULL);
        SDL_ExitWithError("Creation rendu echouee");
    }

    return app;
}

//load texture
SDL_Texture *SDL_loadTexture(char *filename, App *app)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = NULL;
    //Chargement surface
    surface = IMG_Load(filename);
    if(surface == NULL)
    {
        SDL_CleanRessources(app->window, app->renderer, NULL);
        SDL_ExitWithError("Chargement image echouee");
    }
    //Creation texture
    texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == NULL)
    {
        SDL_CleanRessources(app->window, app->renderer, NULL);
        SDL_ExitWithError("Creation texture echouee");
    }

    return texture;
}

//blit
void SDL_renderTexture(SDL_Texture *texture, App *app, int x, int y)
{
    SDL_Rect rectangle = {x, y};

    //Chargement texture
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0)
    {
        SDL_CleanRessources(app->window, app->renderer, texture);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    //Afficher texture
    if(SDL_RenderCopy(app->renderer, texture, NULL, &rectangle) != 0)
    {
        SDL_CleanRessources(app->window, app->renderer, texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    return;
}

void SDL_doInput(SDL_bool *program_launched, int *x, int *y)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {               
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        *x -= SQUARE_SIZE;
                        //printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_RIGHT:
                        *x += SQUARE_SIZE;
                        //printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_UP:
                        *y -= SQUARE_SIZE;
                        //printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_DOWN:
                        *y += SQUARE_SIZE;
                        //printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_b:
                        continue;
                    
                    default:
                        continue;
                }
    
            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_b:
                        printf("Vous avez relache la touche B\n");
                        continue;
                    
                    default:
                        continue;
                }
    
            case SDL_QUIT:
                *program_launched = SDL_FALSE;
                break;
            
            default:
                break;
        }
    }
    
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_freeGame(App *app)
{
    if(app != NULL)
        free(app);
}

void SDL_CleanRessources(SDL_Window *w, SDL_Renderer *r, SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);

    if(r != NULL)
        SDL_DestroyRenderer(r);

    if(w != NULL)
        SDL_DestroyWindow(w);
}