#include "map.h"


void MapManager(void)
{
	/*
	Map *mapLevel01 = new_map(MAP01);
	printMapToTheConsole(mapLevel01);
	test_ecriture(mapLevel01->size, BIN);
	MapSize *test = test_lecture(BIN);
	PrintSize(test);
	free_map(mapLevel01);
	*/
	return;
}
// ----------------------------------------------------
//  Memory allocation and affectation.
// ----------------------------------------------------

Map *new_map(const char *fileLevel)
{
	Map *m = NULL;
	FILE *fic = NULL;

	if((fic = fopen(fileLevel, "r")) == NULL)
		{ fprintf(stderr,"Error : No such file or directory : %s\n",fileLevel); exit(EXIT_FAILURE); }

	m = InitMap();
	m->size = GetSizeMatrix(fic);
	m->matrix = GetMatrix(fic, m->size->rows, m->size->columns);
	m->position = InitMapPos();

	fclose(fic);
	return m;
}

Map *InitMap(void)
{
	Map *map = NULL;

	map = malloc(sizeof(Map*));
	if(map == NULL)
		{ fprintf(stderr, "Error : dynamic allocation problem.\n"); exit(EXIT_FAILURE); }

	return map;
}

MapSize *GetSizeMatrix(FILE *fic)
{
	MapSize *mapS = NULL;

	mapS = malloc(sizeof(MapSize*));
	if(mapS == NULL)
		{ fprintf(stderr, "Error : dynamic allocation problem.\n"); fclose(fic); exit(EXIT_FAILURE); }

	int lettre = 0; mapS->rows = 0, mapS->columns = 0, mapS->nb_block = 0;

    while(1)
    {
		lettre = fgetc(fic);
		if(lettre != EOF)
		{
			if(lettre == '\n'){ mapS->rows++; mapS->columns = 0; }
			else{ mapS->columns++; mapS->nb_block++; }
		}
		else { mapS->rows += 1; break; }
    }
	return mapS;
}

int **GetMatrix(FILE *fic, int rows, int columns)
{
	int **matrix = NULL;
	matrix=malloc(rows * sizeof(int*));
	if(matrix == NULL)
		{ fprintf(stderr, "Error : dynamic allocation problem.\n"); fclose(fic); exit(EXIT_FAILURE); }

	for(int i=0; i < rows; i++)
	{
		matrix[i]=malloc((columns+1)*sizeof(int));
		if(matrix[i] == NULL)
			{ fprintf(stderr, "Error : dynamic allocation problem.\n"); fclose(fic); exit(EXIT_FAILURE); }
	}

	rewind(fic);

	//remplissage
	int tmp = 0;
	for(int i=0 ; i < rows ; i++)
		for(int j=0 ; j < (columns+1) ; j++)
			if((tmp = fgetc(fic)) != '\n')
				matrix[i][j] = tmp;

	return matrix;
}

MapPos *InitMapPos(void)
{
	MapPos *mapP = NULL;

	mapP = malloc(sizeof(MapPos*));
	if(mapP == NULL)
		{ fprintf(stderr, "Error : dynamic allocation problem.\n"); exit(EXIT_FAILURE); }

	mapP->xscroll = 0;
	mapP->yscroll = 0;
	return mapP;
}

// ----------------------------------------------------
//  File bin manager.
// ----------------------------------------------------

void test_ecriture(MapSize *mSize, const char *filename)
{
   	FILE *fic = NULL;
    fic = fopen(filename, "wba");
	if(fic == NULL)
        { fprintf(stderr,"Error : No such file or directory : %s\n",filename); exit(EXIT_FAILURE); }
    fwrite(&mSize, sizeof(mSize), 1, fic); //ok cours
    
	fclose(fic);
	return;
}

MapSize *test_lecture(const char *filename)
{
	MapSize *mSize = NULL;
	FILE *fic = NULL;

	mSize = malloc(sizeof(MapSize*));
	if(mSize == NULL)
		{ fprintf(stderr, "Error : dynamic allocation problem.\n"); exit(EXIT_FAILURE); }

    fic = fopen(filename, "rb");
	if(fic == NULL)
        { fprintf(stderr,"Error : No such file or directory : %s\n",filename); exit(EXIT_FAILURE); }

	fread(&mSize, sizeof(mSize), 1, fic);

    fclose(fic);
    return mSize;
}

// ----------------------------------------------------
//  Display map.
// ----------------------------------------------------

void printMapToTheConsole(Map *m)
{
	printf("=========== Map ============\n");
	printf("Lignes : %d\nColonnes : %d\nNombre de blocs : %d\nXscroll : %d\nYscroll : %d\n", m->size->rows, m->size->columns, m->size->nb_block, m->position->xscroll, m->position->yscroll);

	for(int i=0 ; i < m->size->rows ; i++){
		printf("\n");
		for(int j=0 ; j < m->size->columns ; j++)
				printf("%c", m->matrix[i][j]);
	}
	printf("\n");
	printf("============================\n");
}

void PrintSize(MapSize *mSize)
{
	printf("PrintSize : %d | %d | %d\n", mSize->rows, mSize->columns, mSize->nb_block);
	return;
}

void drawMap(Map *m)
{
	/*
	for(int i=0 ; i < m->size->rows ; i++){
		for(int j=0 ; j < m->size->columns ; j++)
			printf("%c", m->matrix[i][j]);
	}
	*/
}

// ----------------------------------------------------
//  Free map.
// ----------------------------------------------------

void free_map(Map *map)
{
	for(int i = 0 ; i < map->size->rows ; i++)
	{
		free(map->matrix[i]);
	}
	free(map->matrix);
	free(map->position);
	free(map->size);

	free(map);

	return;
}

/*==========================================================*/
