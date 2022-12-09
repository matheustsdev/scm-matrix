/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */
#include <dirent.h>
#include <stdio.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./images");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);

            // Iniciar medição do tempo. 

            // Leitura da Imagem -PGM

            // Processar
            
            // Saída - Salvar matriz vetorizada no arquivo de características

            // Finalizar medição do tempo.

            // Acumular tempo medido. 
        }
        closedir(d);

        // Calcular tempo médio por imagem.
    }

    return(0);
}		