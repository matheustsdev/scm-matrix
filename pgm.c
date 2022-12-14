//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
//∗ Aluno : Matheus Teixeira, Livia Leite, Yaslly Guimarães
//∗ M a t r i c u l a : 20221045050303, 20221045050257, 20221045050591
//∗ A v a l i a c a o 0 4 : Trabalho F i n a l
//∗ 0 4 . 5 0 5 . 2 3 − 2 0 2 2 . 2 − P r o f . D a n i e l F e r r e i r a 
//∗ Compilador : gcc | v e r s a o:  11.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗

#include <stdio.h>
#include <stdlib.h>

#include "pgm.h"

void readPGMImage(struct pgm *pio, char *filename){

	FILE *fp;
	char ch;


	if (!(fp = fopen(filename,"r"))){
		perror("Erro.");
		exit(1);
	}

	if ( (ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

	while((ch=getc(fp))=='#'){
		while( (ch=getc(fp))!='\n');
	}

	fseek(fp,-1, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);
	if (ferror(fp)){ 
		perror(NULL);
		exit(3);
	}	
	fscanf(fp, "%d",&pio->mv);
	fseek(fp,1, SEEK_CUR);

	pio->pData = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));

	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;	
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	
	fclose(fp);

}

void writePGMImage(struct pgm *pio, char *filename, int level){
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", level);

	fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);

	fclose(fp);

}

void viewPGMImage(struct pgm *pio){

	for (int k=0; k < (pio->r * pio->c); k++){
		if (!( k % pio->c)) printf("\n");
		printf("%2hhu ",*(pio->pData+k));
	}	
	printf("Tipo: %d\n",pio->tipo);
	printf("Dimensões: [%d %d]\n",pio->c, pio->r);
	printf("Max: %d\n",pio->mv);
	printf("\n");
}

void quantizationMatrix(int *bufferMatrix , struct pgm pgmImg, int quantizationLevel){
    int totalOfElements = pgmImg.r * pgmImg.c;
	
	// Add one for return total number of options
    int quantizationLevelRange = pgmImg.mv+1/quantizationLevel;
    int matrixValue, pgmData;

    for(int i = 0; i < totalOfElements; i++){
		pgmData = *(pgmImg.pData+i);

        matrixValue = pgmData/quantizationLevelRange;

		*(bufferMatrix + i) = matrixValue;
    }

}