#include "save.h"

void save_game(Player *p)
{
    FILE *fic = fopen("player.save", "w");
    if(fic == NULL)
        exit(1);
    fprintf(fic, "%s %d %d %d", p->name, p->score, p->position->X, p->position->Y);
    fclose(fic);
    return;
}

void save_score(Player *p)
{
    FILE *fic = fopen("score.save", "w");
    if(fic == NULL)
        exit(1);
    fprintf(fic, "%s %d", p->name, p->score);
    fclose(fic);
    return;
}

/* todo : fonction de tri avec lecture sécurisé du meilleur score. */