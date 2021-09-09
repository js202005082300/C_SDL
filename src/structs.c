#include "structs.h"

Entity *initEntity(void)
{
    Entity *entity = NULL;
    entity = malloc(sizeof(*entity));
    entity->texture = malloc(sizeof(entity->texture));

    return entity;
}

Entity *initPlayer(SDL_Renderer *renderer, SDL_Window *window)
{
    Entity *player = initEntity();

    player->x = 10;
    player->y = 10;
    player->texture = loadTexture(renderer, window, "src/gfx/ship-100.png");

    return player;
}

Entity *initBullet(SDL_Renderer *renderer, SDL_Window *window)
{
    Entity *bullet = initEntity();

    bullet->x = 10;
    bullet->y = 10;
    bullet->texture = loadTexture(renderer, window, "src/gfx/bullet-10.png");

    return bullet;
}

void freeEntity(Entity *entity)
{
    free(entity->texture);
    entity->texture = NULL;

    free(entity);
    entity = NULL;
}