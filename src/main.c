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
	player = initPlayer();

	SDL_Texture **textures = initTextures(app->renderer, app->window);

	SDL_bool prog_launched = SDL_TRUE, *ptr = &prog_launched;
	SDL_bool b_pressed = SDL_FALSE, *ptr_b = &b_pressed;

	while (*ptr)
	{
		prepareScene(app);

		doInput(ptr, ptr_b, &player->x, &player->y);

		blit(app->renderer, textures[player->texID], &player->x, &player->y);

		if(b_pressed)
		{
			bullet = initBullet(bullet, &player->x, &player->y);
			b_pressed = SDL_FALSE;
		}
		drawBullet(bullet, app->renderer, textures);

		presentScene(app->renderer);

		SDL_Delay(16);
	}

	freeTextures(textures);
	freeEntity(player);
	freeEntity(bullet);
	freeSDL(app);

	printf("Fin programme\n");

	return 0;
}
