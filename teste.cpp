#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerTotalDeLinhas(char* endereco){
    FILE* arq = fopen(endereco, "r");

    int totalLinhas = 0;
    int cont = 0;
    char p1[20] = "ab";
    char p2[20] = "cd";

    while(strcmp(p1, p2) != 0){
        strcpy(p2, p1);
        fscanf(arq, "%s", p1);
//      fscanf(arq, "%s", p2);
   //   printf("%s ===== %s teste p\n", p1, p2);
//      printf("%d teste cont\n", cont);
		cont++;		
        if(cont%2 == 0){
			totalLinhas++;
		}
//      printf("%d teste totalLinhas\n", totalLinhas);
    }
 //   printf("\n\n%d total final-----------------\n\n", totalLinhas);

    return totalLinhas;
}

char** lerEnderecos(char* endereco){
    FILE* arq = fopen(endereco, "r");
    char** vetEnd;
    char end[12];
    char op[3];
    int cont = 0;
	int totalLinhas = lerTotalDeLinhas(endereco);

    vetEnd = (char**)malloc(sizeof(char*) * totalLinhas);

    for(int i = 0; i < totalLinhas; i++){
    	vetEnd[i] = (char*)malloc(sizeof(char) * 100);
    }

    for(int i = 0; i < totalLinhas; i++){
        fscanf(arq, "%s", op);
        fscanf(arq, "%s", end);
        strcpy(vetEnd[i], end);
        cont++;
    }

    return vetEnd;

}

int main(){
    char endereco[100] = "";
    char result[100] = "";
    
    printf("Insira o nome do arquivo a ser lido: ");
    scanf(" %s", endereco);


    printf("Insira o nome do arquivo resultado: ");
    scanf(" %s", result);

    char endMemoria[10];
    char op[3];

    
    FILE* arqResult = fopen(result, "w");
    FILE* arqLido = fopen(endereco, "r");
    int totalLinhas = lerTotalDeLinhas(endereco);
    char** vetEnd = lerEnderecos(endereco);

    int totalRedundancias = 0;

	for(int i = 0; i < totalLinhas; i++){
		fscanf(arqLido, "%s %s", op, endMemoria);
		for(int j = 1 + i; j < totalLinhas; j++){
			if(strcmp(vetEnd[j], endMemoria) == 0){
				fprintf(arqResult, "redundante: linha %d e linha %d\nendereco: %s\n\n", i, j, endMemoria);
				vetEnd[j] = (char*)"xxxxx";
                totalRedundancias++;
			}
		}
	}

	printf("\n\n\ntotal de linhas: %d\ntotal de bytes %d\ntotal de redundancias %d\n", totalLinhas, totalLinhas*4, totalRedundancias);


	fprintf(arqResult, "\n\n\ntotal de linhas: %d\ntotal de bytes %d\ntotal de redundancias %d\n", totalLinhas, totalLinhas*4, totalRedundancias);


    return 0;
}



/*

vet[6] 

matriz[][]


*/
