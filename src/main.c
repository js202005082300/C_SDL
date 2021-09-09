#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"

int main(int argc, char *argv[])
{
	App *app = NULL;
	Entity *player = NULL;
	Entity *bullet = NULL;

	app = initSDL();
	player = initPlayer(app->renderer, app->window);
	bullet = initBullet(app->renderer, app->window);

	while (1)
	{
		prepareScene(app);

		doInput(&player->x, &player->y, bullet);

		if (bullet->health > 0)
		{
			blit(app->renderer, bullet->texture, &bullet->x, &bullet->y);
		}
		moveBullet(bullet);

		blit(app->renderer, player->texture, &player->x, &player->y);

		presentScene(app->renderer);

		SDL_Delay(16);
		//SDL_RenderPresent(app->renderer);
	}

	freeEntity(player);
	freeSDL(app);

	return 0;
}
