#include <stdio.h>
#include <time.h>

#define QTDIMG 100

int main(){
	int k;
	clock_t begin, end;
	double time_per_img, time_total=0;
	long long int a = 999999999;

	for (k=0; k<QTDIMG; k++){

		begin = clock();
		
		// Leitura da Imagem -PGM
		
		// Processar - Sera a computacao da SCM.
		
		// Apenas uma simulação para ilustrar esse exemplo. 
		while(a){
			a--;
		}

		// Saída - Salvar matriz vetorizada no arquivo de características

		end = clock();

		time_per_img = (double)(end - begin) / CLOCKS_PER_SEC;

		time_total += time_per_img;

	}


	printf("Tempo médio: %lf\n",time_total/QTDIMG);
	printf("Tempo Total: %lf\n",time_total);
	return 0;

}