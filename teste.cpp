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

//        fscanf(arq, "%s", p2);

   //     printf("%s ===== %s teste p\n", p1, p2);

//        printf("%d teste cont\n", cont);

		cont++;		if(cont%2 == 0){

			totalLinhas++;

		}

//            printf("%d teste totalLinhas\n", totalLinhas);

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

void removePosicao(char** vet, int pos, int ultimo);

int main(){

    char endereco[8] = "top.din";

    char endMemoria[10];

    char op[3];

    FILE* arqTop = fopen(endereco, "r");

    int totalLinhas = lerTotalDeLinhas(endereco);

    char** vetEnd = lerEnderecos(endereco);

    

    for (int i = 0; i < totalLinhas; i++){

    	printf("%s ------------- linha = %d\n", vetEnd[i], i + 1);

    }

	for(int i = 0; i < totalLinhas; i++){

		fscanf(arqTop, "%s %s", op, endMemoria);

		for(int j = 1 + i; j < totalLinhas; j++){

			if(strcmp(vetEnd[j], endMemoria) == 0){

				printf("redundante:\nlinha %d\nlinha %d\n\n", i, j);

				vetEnd[j] = "xxxxx";

			}

		}

	}

	printf("\nuAaaaaaaaa %d", lerTotalDeLinhas(endereco));

    return 0;

}
