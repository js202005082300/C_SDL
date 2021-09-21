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
    player->w = SIZE_PLAYER_SQUARE;
    player->h = SIZE_PLAYER_SQUARE;
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
    enemy->w = SIZE_ENEMY_SQUARE;
    enemy->h = SIZE_ENEMY_SQUARE;
    enemy->health = 100;
    enemy->side = SIDE_ALIEN;
    enemy->texID = 2;

    if(entityList == NULL)
        enemy->next = NULL;
    else
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
    bullet->w = SIZE_BULLET_SQUARE;
    bullet->h = SIZE_BULLET_SQUARE;
    bullet->health = 1;
    bullet->side = SIDE_PLAYER;
    bullet->texID = 1;

    //bullet->next = entityList;
    if(entityList == NULL)
        bullet->next = NULL;
    else
        bullet->next = entityList;
    
    return bullet;
}

/* ----------------------------------------- */

void freeEntity(Entity *list)
{
    Entity *tmp = initEntity();
    
    while(list != NULL)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    free(list);
    list = NULL;
}

/* ----------------------------------------- */

Entity *freeDeadEntity(Entity *list, int x)
{
	Entity *ptr = list;
    Entity *before = NULL;

    if(list == NULL)
        return initEntity();

    //for(ptr = list; ptr != NULL; ptr = ptr->next)
    while(ptr != NULL)
    {
        if(ptr->health == x)
        {
            if(list->health == x) //Reinitialiser le ptr du 1er élément.
            {
                before = list->next;
                list = before;
            }
            else
            {
                before->next = ptr->next;
                free(ptr);
            }
            ptr = before;
        }
        before = ptr;
        ptr = ptr->next;
    }

    return list;
}