#include "map.h"

void map_init(const char *fileLvl, const char *fileBin)
{
	//initialisation map	
	Map *m = NULL;

	if((m = malloc(sizeof(Map*))) == NULL){
		fprintf(stderr, "Error : dynamic allocation problem.\n");
		exit(EXIT_FAILURE);
	}

	/*----------------------------------------------------*/

	//lecture données	
	FILE *lvl = NULL;
	FILE *bin = NULL;
	if((lvl = fopen(fileLvl, "r")) == NULL || (bin = fopen(fileBin, "wba")) == NULL){
		fprintf(stderr,"Error : No such file or directory : %s\n",fileLvl);
		exit(EXIT_FAILURE);
	}

	int lettre = 0, rows = 1, columns=0, nb_block = 0;
    while((lettre = fgetc(lvl)) != EOF)
    {
        //printf("%c", lettre);
		fwrite(&lettre, sizeof(int), 1, bin);
		if(lettre == '\n')
		{ 
			++rows;
			columns = 0;
		}
		else
		{
			++columns;
			++nb_block;
		}
    }
	printf("\n");
	fwrite(&rows, sizeof(int), 1, bin);
	fwrite(&rows, sizeof(int), 1, bin);
	fwrite(&columns, sizeof(int), 1, bin);
	fwrite(&nb_block, sizeof(int), 1, bin);
	//printf("r : %d | c : %d | nb bl : %d | c test : %d\n",rows, columns, nb_block, nb_block/rows);
	//m->rows=rows;
	//m->columns=columns;
	//m->nb_block=nb_block;
	//m->xscroll=0, m->yscroll=0;
	/*----------------------------------------------------*/
	printf("Position : %ld\n", ftell(lvl));
	rewind(lvl);
	printf("Position : %ld\n", ftell(lvl));
	/*----------------------------------------------------*/

	int **matrix = NULL;
	matrix=malloc(rows * sizeof(int*));
	if(matrix == NULL){ 
		fprintf(stderr, "Error : dynamic allocation problem.\n");
		//fclose(fic);
		exit(EXIT_FAILURE);
	}

	for(int i=0; i < rows; i++)
	{
		matrix[i]=malloc((columns+1)*sizeof(int));
		if(matrix[i] == NULL){
			fprintf(stderr, "Error : dynamic allocation problem.\n");
			//fclose(fic);
			exit(EXIT_FAILURE);
		}
	}
	//remplissage
	int tmp = 0;
	for(int i=0 ; i < rows ; i++)
		for(int j=0 ; j < (columns+1) ; j++)
			if((tmp =fgetc(lvl)) != '\n')
				matrix[i][j] = tmp;

	//affichage
	for(int i=0 ; i < rows ; i++)
		for(int j=0 ; j < columns ; j++)
			printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, matrix[i][j]);

	fwrite(&matrix, sizeof(int), 1, bin);
	
	fclose(lvl);
	fclose(bin);

	/*----------------------------------------------------*/

	for(int i = 0 ; i < rows ; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	/*----------------------------------------------------*/

	return;
}

void test(const char *filename)
{
	FILE *fic = NULL;
	fic = fopen(filename, "rb");
	int **matrix = NULL;
	int rows = 1, columns=0, nb_block = 0;
	fread(&rows, sizeof(int), 1, fic);
	fread(&columns, sizeof(int), 1, fic);
	printf("lignes = %d | colonnes = %d | nb_block = %d\n", rows, columns, nb_block);
	fread(&matrix, sizeof(int**), 1, fic);
	//affichage
	for(int i=0 ; i < rows ; i++)
		for(int j=0 ; j < columns ; j++)
			printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, matrix[i][j]);

    fclose(fic);
}

void printMapToTheConsole(Map *m)
{
	for(int i=0 ; i < m->rows ; i++)
		for(int j=0 ; j < m->columns ; j++)
			printf("Valeur tab[%d][%d] = %d\n", i, j, m->matrix[i][j]);
}