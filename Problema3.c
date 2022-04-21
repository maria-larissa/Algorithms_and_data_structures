#include <stdio.h>
#include <stdlib.h>
#define max 100
//Implemente uma funcao que receba uma fila e a inverta.
typedef struct fila
{
    int elementos[max];
    int quant;    
}Fila;

Fila* criar_fila(int tam);
int inverte_fila(Fila *fi);

int main(){
    int tam;
    printf("\nDigite o tamanho da fila: ");
    scanf("%d",&tam);
    Fila *fi = criar_fila(tam);

    //Caso queira conferir elementos da lista
    // printf("\n   ***Fila***\n");
    // for(int i=0 ; i<(*fi).quant; i++){
    //     printf("Elemento[%d] = %d\n",i,(*fi).elementos[i]);
    // }

    int resultado = inverte_fila(fi);
    if(resultado == 1){
        printf("\nFila invertida com sucesso!\n");
        printf("\n***Fila invertida***\n");
        for(int i=0 ; i < (*fi).quant ; i++){
            printf("Elemento[%d] = %d\n",i,(*fi).elementos[i]);
        }

    } 
    return 0;
}

Fila* criar_fila(int tam){
    Fila *fi = (Fila*)malloc(tam * sizeof(int));
    printf("\nPreencha a fila\n");
    for(int i=0 ; i < tam ; i++){
        printf("Elemento[%d] = ",i);
        scanf("%d", &(*fi).elementos[i]);
        (*fi).quant++;
    }
    return fi;
}

int inverte_fila(Fila *fi){
    if(fi == NULL){
        return 0;
    }
    int tam_aux = (*fi).quant, i=0, j=tam_aux;
    int *lista = (int*)malloc(tam_aux*sizeof(int));
    while(i<tam_aux){
        lista[i]= (*fi).elementos[i];
        (*fi).quant--;
        i++;
    }
    if((*fi).quant == 0){
        i=0;
        j=tam_aux;
        while(j>0){
            (*fi).elementos[i] = lista[j-1];
            (*fi).quant++;
            j--;
            i++;
        }
        return 1;
    }
}