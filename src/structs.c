#include "structs.h"

Entity *initEntity(void)
{
    Entity *entity = NULL;
    entity = malloc(sizeof(*entity));

    entity->next = NULL;

    return entity;
}

/* ----------------------------------------- */

Entity *initPlayer(void)
{
    Entity *player = initEntity();

    player->x = 10;
    player->y = 10;
    player->texID = 0;

    return player;
}

/* ----------------------------------------- */

Entity *initBullet(Entity *entity, int *entity_x, int *entity_y)
{
    Entity *bullet = initEntity();

    bullet->x = *entity_x;
    bullet->y = *entity_y;
    bullet->dx = 16;
    bullet->dy = 0;
    bullet->health = 1;
    bullet->texID = 1;

    bullet->next = entity;

    return bullet;
}


/* ----------------------------------------- */

void drawListBullet(void)
{

}

/* ----------------------------------------- */

void freeEntity(Entity *entity)
{
    while(entity != NULL)
    {
        entity = popFrontList(entity);
    }
    free(entity);
    entity = NULL;
}

Entity *popFrontList(Entity *entity)
{
    Entity *tmp = initEntity();
    tmp = entity->next;
    free(entity);
    return tmp;
}