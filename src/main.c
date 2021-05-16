#include "utils.h"
#include "player.h"
#include "save.h"

int main(int argc, char *argv[])
{

    SDL_Surface *background = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect dstrect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    /*---------------------------*/

    SDL_V();
    Player *p = NULL;

    p = new_player("Buble Buble");
    print_player(p);

    p->score += 5;
    p->position->X += 3;
    p->position->Y += 6;
    print_player(p);
    free_player(p);
    print_player(p);
    save_game(p);

    /*---------------------------*/

    App *app = SDL_initGame();

    /*---------------------------*/

    //Chargement background
    background = IMG_Load("src/background.png");
    if(background == NULL)
    {
        SDL_CleanRessources(app->window, app->renderer, NULL);
        SDL_ExitWithError("Chargement background echouee");
    }
    //Création texture
    texture = SDL_CreateTextureFromSurface(app->renderer, background);
    SDL_FreeSurface(background);
    if(texture == NULL)
    {
        SDL_CleanRessources(app->window, app->renderer, NULL);
        SDL_ExitWithError("Creation texture echouee");
    }
    //Chargement texture
    if(SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h) != 0)
    {
        SDL_CleanRessources(app->window, app->renderer, texture);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    // dstrect.x = (WINDOW_WIDTH - dstrect.w) / 2;
    // dstrect.y = (WINDOW_HEIGHT - dstrect.h) / 2;
    //Afficher texture
    if(SDL_RenderCopy(app->renderer, texture, NULL, &dstrect) != 0)
    {
        SDL_CleanRessources(app->window, app->renderer, texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    SDL_RenderPresent(app->renderer);

    /*----------------------------------------------*/
    SDL_bool program_launched = SDL_TRUE;

    while(program_launched)
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
                        case SDLK_RIGHT:
                        case SDLK_UP:
                        case SDLK_DOWN:
                            printf("Gauche-Droite-Haut-Bas\n");
                            continue;
                        case SDLK_b:
                            printf("Vous avez appuye sur B\n");
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
                    program_launched = SDL_FALSE;
                    break;
                
                default:
                    break;
            }
        }
    }
    /*----------------------------------------------*/
    SDL_CleanRessources(app->window, app->renderer, texture);
    return EXIT_SUCCESS;
}