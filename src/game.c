#include "game.h"

void SDL_versionUsed(void)
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Bienvenue sur la SDL %d.%d.%d !\n",nb.major, nb.minor, nb.patch);
}

void SDL_gameManager(void)
{
    map_init("src/matrix/niveau1.lvl", "src/matrix/data1.bin");
    GetStruct("src/matrix/data1.bin");
    //return;
    Player *joueur = NULL;
    joueur = new_player("Buble Buble");
    print_player(joueur);

    joueur->score += 5;
    joueur->position->X += 3;
    joueur->position->Y += 6;
    print_player(joueur);
    save_game(joueur);
    free_player(joueur);

    // Initialisation
    App *app = SDL_initGame();

    // Texture
    SDL_Texture *texture_background = SDL_loadTexture("src/background.png", app);
    SDL_Texture *texture_player = SDL_loadTexture("src/sprite-100.png", app);

    // Evenement
    SDL_bool program_launched = SDL_TRUE;
    SDL_bool *ptr = &program_launched;
    unsigned int *X = &joueur->position->X;
    unsigned int *Y = &joueur->position->Y;
    while(*ptr)
    {
        SDL_doInput(ptr, X, Y);

        SDL_renderTexture(texture_background, app, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        SDL_renderTexture(texture_player, app, joueur->position->X, joueur->position->Y, SQUARE_SIZE, SQUARE_SIZE);   
        SDL_RenderPresent(app->renderer);
    }

    // Clean up
    SDL_CleanRessources(app->window, app->renderer, texture_background);
    SDL_CleanRessources(app->window, app->renderer, texture_player);
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

    //Cr�ation fen�tre
    app->window = SDL_CreateWindow("Jeu C/SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(app->window == NULL)
        SDL_ExitWithError("Creation fenetre echouee");

    //Cr�ation rendu
    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_SOFTWARE);
    if(app->renderer == NULL)
    {
        SDL_CleanRessources(app->window, NULL, NULL);
        SDL_ExitWithError("Creation rendu echouee");
    }

    return app;
}

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
    //Cr�ation texture
    texture = SDL_CreateTextureFromSurface(app->renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == NULL)
    {
        SDL_CleanRessources(app->window, app->renderer, NULL);
        SDL_ExitWithError("Creation texture echouee");
    }

    return texture;
}

void SDL_renderTexture(SDL_Texture *texture, App *app, int x, int y, int w, int h)
{
    SDL_Rect rectangle = {x, y, w, h};

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

void SDL_doInput(SDL_bool *program_launched, unsigned int *x, unsigned int *y)
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
                        *x -= 10;
                        printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_RIGHT:
                        *x += 10;
                        printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_UP:
                        *y -=10;
                        printf("(%d,%d)\n", *x, *y);
                        continue;
                    case SDLK_DOWN:
                        *y +=10;
                        printf("(%d,%d)\n", *x, *y);
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
    
    SDL_Quit();
}