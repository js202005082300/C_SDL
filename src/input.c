#include "input.h"

void doInput(int *player_x, int *player_y, Entity *bullet)
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
						loadBullet(player_x, player_y, bullet);
                        continue;
                    
                    default:
                        continue;
                }
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

/* ------------------------------------------------------------ */

void moveUp(int *player_y)
{    
    *player_y -= PLAYER_SPEED;
}

/* ------------------------------------------------------------ */

void moveDown(int *player_y)
{
    *player_y += PLAYER_SPEED;
}

/* ------------------------------------------------------------ */

void moveLeft(int *player_x)
{
    *player_x -= PLAYER_SPEED;
}

/* ------------------------------------------------------------ */

void moveRight(int *player_x)
{
    *player_x += PLAYER_SPEED;
}

/* ------------------------------------------------------------ */

void loadBullet(int *player_x, int *player_y, Entity *bullet)
{
	if (bullet->health == 0)
	{
		bullet->x = *player_x;
		bullet->y = *player_y;
		bullet->dx = 16;
		bullet->dy = 0;
		bullet->health = 1;
	}
}

void moveBullet(Entity *bullet)
{
	bullet->x += bullet->dx;
	bullet->y += bullet->dy;

	if (bullet->x > SCREEN_WIDTH)
	{
		bullet->health = 0;
	}
}