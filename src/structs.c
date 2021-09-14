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
    player->side = SIDE_PLAYER;
    player->texID = 0;

    return player;
}

/* ----------------------------------------- */

Entity *initEnemy(Entity *entityList)
{
    Entity *enemy = initEntity();

    enemy->x = SCREEN_WIDTH;
    enemy->y = rand() % SCREEN_HEIGHT;
    enemy->dx = -(2 + (rand() % 4));
    enemy->health = 100;
    enemy->side = SIDE_ALIEN;
    enemy->texID = 2;


    enemy->next = entityList;

    return enemy;
}

/* ----------------------------------------- */

Entity *initBullet(Entity *entityList, int *entity_x, int *entity_y)
{
    Entity *bullet = initEntity();

    bullet->x = *entity_x + 20;
    bullet->y = *entity_y + 16;
    bullet->dx = 16;
    bullet->dy = 0;
    bullet->health = 1;
    bullet->side = SIDE_PLAYER;
    bullet->texID = 1;

    bullet->next = entityList;

    return bullet;
}

/* ----------------------------------------- */

void freeEntity(Entity *entityList)
{
    while(entityList != NULL)
    {
        entityList = popFrontList(entityList);
    }
    free(entityList);
    entityList = NULL;
}

Entity *popFrontList(Entity *entityList)
{
    Entity *tmp = initEntity();
    tmp = entityList->next;
    free(entityList);
    return tmp;
}