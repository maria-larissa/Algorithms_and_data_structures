#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct pilha
{
    int vetor[max];
    int topo;    
}Pilha;

Pilha *criar_pilha(int tam);
int inverte_pilha(Pilha *pi);

int main(){
    int i=0, tam;
    printf("\nDigite o tamanho da pilha: ");
    scanf("%d", &tam);
    Pilha *pi = criar_pilha(tam);

    int resultado = inverte_pilha(pi);
    if(resultado == 1){
        printf("\nA pilha foi invertida com sucesso!\n");
        
        printf("\n  ***Pilha invertida***\n");
        while(i<tam){
            printf("posição[%d]= %d \n", i, (*pi).vetor[i]);
            i++;
        }

    }else{
        printf("\nErro ao inverter a pilha!");
    }

    return 0;
}
Pilha *criar_pilha(int tam){
    Pilha *pi = (Pilha*)malloc(tam*sizeof(int));
    printf("\nPreencha a pilha\n");
    int i=0;
    while(i<tam){
        printf("posição[%d]: ", i);
        scanf("%d", &(*pi).vetor[i]);
        (*pi).topo++;
        i++;
    }
    return pi;
}
int inverte_pilha(Pilha *pi){
    int tam_aux = (*pi).topo, i = 0, j=tam_aux;
    int *lista = (int*)malloc( tam_aux*sizeof(int));
    while(i<tam_aux){
        lista[i] = (*pi).vetor[j-1];
        (*pi).topo--;
        i++;
        j--;
    }
    
    if((*pi).topo == 0){     //confere se retirou todos os elementos da pliha original
        i=0;
        while(i<tam_aux){       //Passa da pilha auxiliar pra original
            (*pi).vetor[i] = lista[i];
            (*pi).topo++;
            i++;
        }
        if((*pi).topo == tam_aux){
            return 1;
        }
    }else{
        return 0;
    }
}