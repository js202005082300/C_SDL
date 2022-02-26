#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"

// https://www.parallelrealities.co.uk/tutorials/shooter/shooter8.php

static void capFrameRate(long *then, float *remainder);
void printList(Entity *list);

int main(int argc, char *argv[])
{	
	App *app = NULL;
	Entity *player = NULL;
	Entity *bullet = NULL;
	Entity *enemy = NULL;
	Entity *bulletAlien = NULL;

	app = initSDL();
	player = initPlayer();
	int enemySpawnTimer = 0;
	long then = 0;
	float remainder = 0;
	int prevPositionX = player->x;
	int prevPositionY = player->y;
	int score = 0;

	SDL_Texture **textures = initTextures(app->renderer, app->window);
	SDL_bool prog_launched = SDL_TRUE, *ptr = &prog_launched;
	SDL_bool b_pressed = SDL_FALSE, *ptr_b = &b_pressed;

	while (*ptr)
	{
		prepareScene(app);
		doInput(ptr, ptr_b, &player->x, &player->y);

		/* DRAW */

		drawPlayer(player, app->renderer, textures);

		if(b_pressed)
		{
			bullet = initBullet(bullet, &player->x, &player->y);
			bullet = freeDeadEntity(bullet, 0);
			b_pressed = SDL_FALSE;
		}
		drawBullet(bullet, app->renderer, textures);

		if(--enemySpawnTimer <= 0)
		{
			enemy = initEnemy(enemy);
			enemy = freeDeadEntity(enemy, 0);
			enemySpawnTimer = 30 + (rand() % 60);
		}
		drawEnemy(enemy, app->renderer, textures);

		if(prevPositionX != player->x || prevPositionY != player->y)
		{		
			for(Entity *e = enemy; e != NULL; e = e->next)
				if(e->y >= (player->y - 10) && e->y <= (player->y + 10))
				{
					bulletAlien = initAlienBullet(bulletAlien, &e->x, &e->y);
					bulletAlien = freeDeadEntity(bulletAlien, 0);
				}
			
			prevPositionX = player->x;
			prevPositionY = player->y;
		}
		drawAlienBullet(bulletAlien, app->renderer, textures);

		score = bulletHitEnnemy(bullet, enemy, score);
		player->health = bulletHitPlayer(bulletAlien, player);
		
		presentScene(app->renderer);
		capFrameRate(&then, &remainder);//SDL_Delay(16);
	}

	printf("Score : %d\n", score);
	printf("Sante : %d\n", player->health);
	freeTextures(textures);
	freeEntity(player);
	freeEntity(bullet);
	freeSDL(app);

	printf("Fin programme\n");

	return 0;
}

static void capFrameRate(long *then, float *remainder)
{
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}

void printList(Entity *list)
{
	Entity *tmp = list;
	
	printf("> ");
	while(tmp != NULL)
	{
		printf("%d.", tmp->health);
		tmp = tmp->next;
	}
	printf("\n");
}