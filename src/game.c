#include "game.h"

void SDL_VersionUsed(void)
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Bienvenue sur la SDL %d.%d.%d !\n",nb.major, nb.minor, nb.patch);
}

void SDL_GameManager(void)
{
    App *app = NULL;
    Map *map = NULL;
    Player *joueur = NULL;
    int currentScore = 0, prevScore = 0;
    
    joueur = new_player("Buble Buble");
    joueur->score += 5;
    joueur->position->X += 3;
    joueur->position->Y += 6;
    // print_player(joueur);
    save_game(joueur);
    free_player(joueur);

    // Initialisation
    app = SDL_InitGame();
    map = new_map(MAP02);
    // printMapToTheConsole(map);

    // TTF_Font (initialisé dans SDL_initGame)
    TTF_Font * font = TTF_LoadFont();
    SDL_Color color = TTF_textColor();

    // Texture
    SDL_Texture *texture_background = SDL_LoadTexture("src/pics/background-scroll.png", app->renderer, app->window);
    SDL_Texture *texture_player = SDL_LoadTexture("src/pics/sprite-100.png", app->renderer, app->window);
    SDL_Texture *texture_brick = SDL_LoadTexture("src/pics/brick-10.png", app->renderer, app->window);
    SDL_Texture *text = NULL;
    if(texture_background == NULL || texture_player == NULL || texture_brick == NULL)
    { exit(1); }

    // Evenement
    SDL_bool program_launched = SDL_TRUE; 
    SDL_bool *ptr = &program_launched;
    int *X = &joueur->position->X; int prevX = joueur->position->X;
    int *Y = &joueur->position->Y; int prevY = joueur->position->Y;
    int *Xs = &map->position->xscroll;
    int *Ys = &map->position->yscroll;
    const int MapLimitX = map->size->columns * SQUARE_SIZE - PLAYER_SIZE;
    const int MapLimitY = map->size->rows * SQUARE_SIZE - PLAYER_SIZE;
  
    char buffer[50];
    //char *cBuf = buffer;

    while(*ptr)
    {
        // Entrée au clavier
        SDL_DoInput(ptr, X, Y, MapLimitX, MapLimitY);

        /* ------ RECHERCHE A PROPOS DU SCROLL -------- */
        *Xs = *X + 50 - WINDOW_WIDTH/2;     if(*Xs<0){ *Xs=0; } if(*Xs>map->size->columns*SQUARE_SIZE - WINDOW_WIDTH){ *Xs=map->size->columns*SQUARE_SIZE - WINDOW_WIDTH; }
        *Ys = *Y + 50 - WINDOW_HEIGHT/2;    if(*Ys<0){ *Ys=0; } if(*Ys>map->size->rows*SQUARE_SIZE - WINDOW_HEIGHT){ *Ys=map->size->rows*SQUARE_SIZE - WINDOW_HEIGHT; }

        map->position->minX=*Xs / SQUARE_SIZE;
        map->position->minY=*Ys / SQUARE_SIZE;
        map->position->maxX=(*Xs + WINDOW_WIDTH) / SQUARE_SIZE;
        map->position->maxY=(*Ys + WINDOW_HEIGHT) / SQUARE_SIZE;
        /* -------------------------------------------- */

        /* -------- AFFICHER L'ESPACE DE JEU ---------- */
        SDL_RenderTexture(texture_background, app->renderer, app->window, 0 - *Xs, 0 - *Ys); //scroll à appliquer
        SDL_RenderTexture(texture_player, app->renderer, app->window, *X - *Xs, *Y - *Ys); //scroll à appliquer
        for(int i=map->position->minY ; i < map->position->maxY ; i++)
            for(int j=map->position->minX ; j < map->position->maxX ; j++)
                if(map->matrix[i][j] == '1')
                    SDL_RenderTexture(texture_brick, app->renderer, app->window, j*SQUARE_SIZE - *Xs, i*SQUARE_SIZE - *Ys); //scroll à appliquer
        /* -------------------------------------------- */

        /* ------ RECHERCHE A PROPOS DE TTF SDL ------- */
        currentScore = 100;
        if(currentScore != prevScore)
        {
            sprintf(buffer, "SCORE: %d", currentScore);
            text = TTF_LoadTexture(buffer, font, color, app->renderer, app->window);
            prevScore = currentScore;
        }
        TTF_RenderTexture(text, app->renderer, app->window, 0, 50);
        /* -------------------------------------------- */

        /* ----- INFORMATIONS POUR LE DÉVELOPPEUR ----- */
        if(*X != prevX || *Y != prevY){printDatasToTheConsole(map, joueur);prevX = *X;prevY = *Y;}
        /* -------------------------------------------- */

        /* ---- RECHERCHE A PROPOS DE LA COLLISION ---- */
        //if(*X <= 0){*X = 0;} if(*X >= map->size->columns*SQUARE_SIZE - PLAYER_SIZE){*X = map->size->columns*SQUARE_SIZE - PLAYER_SIZE;}
        //if(*Y <= 0){*Y = 0;} if(*Y >= map->size->rows*SQUARE_SIZE - PLAYER_SIZE){*Y = map->size->rows*SQUARE_SIZE - PLAYER_SIZE;}

        //if(map->matrix[*Y/10][*X/10] == '1'){*Y-=SPEED_PLAYER; *X-=SPEED_PLAYER;}
        //if(map->matrix[*Y/10 + PLAYER_SIZE][*X/10 + PLAYER_SIZE] == '1'){*Y-=SPEED_PLAYER + PLAYER_SIZE; *X-=SPEED_PLAYER + PLAYER_SIZE;}
        /* -------------------------------------------- */


        // Gestion rendus
        SDL_RenderPresent(app->renderer);
    }

    // Clean up
    TTF_CleanTextRessources(text, font);
    SDL_CleanRessources(NULL, NULL, texture_brick);
    SDL_CleanRessources(NULL, NULL, texture_player);
    SDL_CleanRessources(app->window, app->renderer, texture_background);
    free_map(map);
}

void printDatasToTheConsole(Map *map, Player *joueur)
{
    system("CLS");
    //  Informations de développemen
    printf("Position joueur : (%d,%d)\n", joueur->position->X, joueur->position->Y);
    //  Macros pour la taille de l'espace de jeu (modifiables)
    printf("WINDOW_WIDTH : %d\nWINDOW_HEIGHT : %d\nSQUARE_SIZE : %d\n", WINDOW_WIDTH, WINDOW_HEIGHT, SQUARE_SIZE);
    //  Données de matrice
    printf("Nombre colonnes : %d | Nombre lignes : %d\n", map->size->columns, map->size->rows);
    printf("Decallage xscroll : %d | yscroll : %d\n", map->position->xscroll, map->position->yscroll);
    printf("min X : %d | min Y : %d | max X : %d | max Y : %d\n", map->position->minX, map->position->minY, map->position->maxX, map->position->maxY);
    printf("Position tableau : (%d,%d)\n", joueur->position->X/10, joueur->position->Y/10);
    printf("Valeur matrice : %c\n", map->matrix[joueur->position->Y/10][joueur->position->X/10]);
}