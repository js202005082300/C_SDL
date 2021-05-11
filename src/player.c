#include "player.h"

Player *new_player(char *name)
{
    Player *p = malloc(sizeof(*p));
    p->name = malloc(sizeof(p->name));
    if(p == NULL || p->name == NULL)
        exit(EXIT_FAILURE);
    p->level = 0;
    strcpy(p->name, name);
    return p;
}

void print_player(Player *p)
{
    printf("Le joueur %s est au niveau %d.\n", p->name, p->level);
    return;
}

void kill_player(Player *p)
{
    free(p);
    free(p->name);
    return;
}