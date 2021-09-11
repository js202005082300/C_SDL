#include "input.h"

void doInput(SDL_bool *program_launched, SDL_bool *b_pressed, int *player_x, int *player_y)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        moveUp(player_y);
                        continue;
                    case SDLK_DOWN:
                        moveDown(player_y);
                        continue;
                    case SDLK_LEFT:
                        moveLeft(player_x);
                        continue;
                    case SDLK_RIGHT:
                        moveRight(player_x);
                        continue;
                    case SDLK_b:
						*b_pressed = SDL_TRUE;
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

/* ----------------------------------------- */

void moveUp(int *player_y)
{    
    *player_y -= PLAYER_SPEED;
}

/* ----------------------------------------- */

void moveDown(int *player_y)
{
    *player_y += PLAYER_SPEED;
}

/* ----------------------------------------- */

void moveLeft(int *player_x)
{
    *player_x -= PLAYER_SPEED;
}

/* ----------------------------------------- */

void moveRight(int *player_x)
{
    *player_x += PLAYER_SPEED;
}

/* ----------------------------------------- */