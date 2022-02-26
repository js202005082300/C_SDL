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
    player->w = SIZE_SQUARE;
    player->h = SIZE_SQUARE;
    player->health = 100;
    player->score = 0;
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
    enemy->w = SIZE_SQUARE;
    enemy->h = SIZE_SQUARE;
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
    bullet->dx = BULLET_SPEED;
    bullet->dy = 0;
    bullet->w = SIZE_BULLET;
    bullet->h = SIZE_BULLET;
    bullet->health = 1;
    bullet->side = SIDE_PLAYER;
    bullet->texID = 1;

    if(entityList == NULL)
        bullet->next = NULL;
    else
        bullet->next = entityList;
    
    return bullet;
}

Entity *initAlienBullet(Entity *entityList, int *entity_x, int *entity_y)
{
    Entity *bullet = initEntity();

    bullet->x = *entity_x + 20;
    bullet->y = *entity_y + 16;
    bullet->health = 1;
	bullet->dx = BULLET_SPEED;
	bullet->dy = 0;
    bullet->side = SIDE_ALIEN;
    bullet->texID = 3;

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
        return NULL;

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

/* ----------------------------------------- */
/*
* @return Le score actuel.
*/
int bulletHitEnnemy(Entity *bullet, Entity *enemy, int score)
{    
    for(Entity *e = enemy; e != NULL; e = e->next)
    {
        for(Entity *b = bullet; b != NULL; b = b->next)
        {
            if(b->health != 0 && e->health != 0 && e->side != b->side && collision(b->x, b->y, b->w, b->h, e->x, e->y, e->w, e->h))
            {
                b->health = 0;
                e->health = 0;

                return score + 1;
            }
        }
    }

    return score;
}

/*
* @return La santé actuel.
*/
int bulletHitPlayer(Entity *bullet, Entity *player)
{
    for(Entity *b = bullet; b != NULL; b = b->next)
    {
        if(b->health != 0 && player->side != b->side && collision(b->x, b->y, b->w, b->h, player->x, player->y, player->w, player->h))
        {
            b->health = 0;

            return player->health - 1;
        }
    }

    return player->health;
}