#include "player.h"

Player *new_player(const char *name)
{
    Player *p = malloc(sizeof(Player*));
    p->name = malloc(sizeof(char*));
    p->position = malloc(sizeof(Position*));

    if(p == NULL || p->name == NULL || p->position == NULL)
        { fprintf(stderr, "Error : dynamic allocation problem.\n"); exit(EXIT_FAILURE); }

    p->score = 0;
    strcpy(p->name, name);
    p->position->X = 0;
    p->position->Y = 0;
    
    return p;
}

void print_player(Player *p)
{
    if(p == NULL)
        return;
    
    printf("Le joueur %s | score %d | position (%d,%d)\n", p->name, p->score, p->position->X, p->position->Y);
}

void free_player(Player *p)
{
    if(p != NULL)
        free(p);
}