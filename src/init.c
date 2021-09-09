#include "init.h"

App *initSDL(void)
{
    App *app = malloc(sizeof(*app));
    app->window = malloc(sizeof(app->window));
    app->renderer = malloc(sizeof(app->renderer));

    if(app == NULL || app->window == NULL || app->renderer == NULL)
    { exit(EXIT_FAILURE); }

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        SDL_ExitWithError("Initialisation SDL echouee");
    }

    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(IMG_Init(flags) != flags)
    {
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    app->window = SDL_CreateWindow("Jeu C/SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(app->window == NULL)
    {
        SDL_ExitWithError("Creation fenetre echouee");
    }

	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_SOFTWARE);

	if (!app->renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

    return app;
}

void freeSDL(App *app)
{
	free(app->window);
	free(app->renderer);
	free(app);

    IMG_Quit();
	SDL_Quit();
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur : %s : %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}