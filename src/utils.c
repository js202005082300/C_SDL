#include <SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

void arg(int c, char **v)
{
	printf("%d argument(s) | Premier argument : %s\n", c, v[0]);
}

void versionSDL(void)
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Bienvenue sur la SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
}