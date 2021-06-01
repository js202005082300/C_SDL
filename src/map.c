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

	//Lecture fichier matrix	
	FILE *lvl = NULL;
	if((lvl = fopen(fileLvl, "r")) == NULL){
		fprintf(stderr,"Error : No such file or directory : %s\n",fileLvl);
		exit(EXIT_FAILURE);
	}

	int lettre = 0, rows = 1, columns=0, nb_block = 0;
    while((lettre = fgetc(lvl)) != EOF)
    {
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

	/*----------------------------------------------------*/
	//La Matrice

	rewind(lvl);

	char **matrix = NULL;
	matrix=malloc(rows * sizeof(char*));
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
			//printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, matrix[i][j]);
			break;

	printf("r : %d | c : %d | nb bl : %d\n",rows, columns, nb_block);
	fclose(lvl);

	/*----------------------------------------------------*/

	//creation binaire
	FILE *bin = NULL;
	if((bin = fopen(fileBin, "wba")) == NULL){
		fprintf(stderr,"Error : No such file or directory : %s\n",fileBin);
		exit(EXIT_FAILURE);
	}

	//m->rows = rows;
	//m->columns = columns;
	//m->nb_block = nb_block;
	//m->xscroll = 0;
	//m->yscroll = 0;
	//m->matrix = matrix;
	//fwrite(m, sizeof(Map), sizeof(m), bin); // OK

	Map ma;
	ma.rows = rows;
	ma.columns = columns;
	ma.nb_block = nb_block;
	ma.xscroll = 0;
	ma.yscroll = 0;
	ma.matrix = matrix;

	//affichage
	for(int i=0 ; i < rows ; i++)
		for(int j=0 ; j < columns ; j++)
			printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, ma.matrix[i][j]);

	fwrite(&ma, sizeof(ma), 1, bin); //ok cours
	//fwrite(&ma.rows, sizeof(ma.rows), 1, bin);
	//fwrite(&ma.columns, sizeof(ma.columns), 1, bin);
	//fwrite(&ma.nb_block, sizeof(ma.nb_block), 1, bin);
	//fwrite(&ma.xscroll, sizeof(ma.xscroll), 1, bin);
	//fwrite(&ma.yscroll, sizeof(ma.yscroll), 1, bin);

	fclose(bin);

	/*----------------------------------------------------*/

	//free
	for(int i = 0 ; i < rows ; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}

void GetStruct(const char *filename)
{
	FILE *fic = NULL;
	long ficSize = 0;
	size_t result;
	Map *Buf = NULL;
	if((fic = fopen(filename, "rb")) == NULL){
		fprintf(stderr,"Error : No such file or directory : %s\n",filename);
		exit(EXIT_FAILURE);
	}

	fseek(fic , 0 , SEEK_END);
	ficSize = ftell(fic);
	rewind(fic);

	//alloc
	Buf = (Map*) malloc(sizeof(Map)*ficSize);
	if(Buf == NULL) {fputs("Memory error",stderr); exit (2);}
	//Buf->matrix = (int**) malloc(sizeof(int*)*1000);

	result = fread(Buf,1,ficSize,fic);
	if(result != ficSize) {fputs("Reading error",stderr); exit (3);}
	printf("%d - %d - %d - %d - %d\n", Buf->rows, Buf->columns,Buf->nb_block,Buf->xscroll, Buf->yscroll);
	//printf("1e valeur : %d\n", Buf->matrix[5][4]); //--> problem
	//printf("Tab en octets : %lld\n", sizeof(Buf->matrix[0][0]));
	//affichage
	for(int i=0 ; i < Buf->rows ; i++)
		for(int j=0 ; j < Buf->columns ; j++)
			//printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, Buf->matrix[i][j]); --> problem

	//fseek(fic, 0, SEEK_SET);
	//Map b;
	//fread(&b, sizeof(b), 1, fic);
	//printf("%d - %d - %d - %d - %d\n", b.rows, b.columns,b.nb_block,b.xscroll, b.yscroll);
	//printf("1e valeur : %d\n", b.matrix[5][4]); //--> problem 

	/*----------------------PROBLEME Allocation------------------------------*/
	//printf("Recuperation : %d | %d | %d | %d | %d\n",Buf->rows,Buf->columns,Buf->nb_block,Buf->xscroll,Buf->yscroll);
	//for(int i=0 ; i < Buf->rows ; i++)
		//for(int j=0 ; j < Buf->columns ; j++)
			//printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, Buf->matrix[i][j]);
	/*----------------------------------------------------*/

	fclose(fic);
	free(Buf);
	return;
}

//il me faut un pointeur pour récupérer le tableau.
void OUPS(const char *filename)
{
	FILE *fic = NULL;
	Map mBuf;
	if((fic = fopen(filename, "rb")) == NULL){
		fprintf(stderr,"Error : No such file or directory : %s\n",filename);
		exit(EXIT_FAILURE);
	}
	fread(&mBuf, sizeof(mBuf), 1, fic); // Pas ok
	printf("Recuperation : %d | %d | %d | %d | %d\n",mBuf.rows,mBuf.columns,mBuf.nb_block,mBuf.xscroll,mBuf.yscroll);
	for(int i=0 ; i < mBuf.rows ; i++)
		for(int j=0 ; j < mBuf.columns ; j++)
			printf("Valeur tab[%d][%d] = %c\n", i+1, j+1, mBuf.matrix[i][j]);
	fclose(fic);
	return;

}

void printMapToTheConsole(Map *m)
{
	for(int i=0 ; i < m->rows ; i++)
		for(int j=0 ; j < m->columns ; j++)
			printf("Valeur tab[%d][%d] = %d\n", i, j, m->matrix[i][j]);
}