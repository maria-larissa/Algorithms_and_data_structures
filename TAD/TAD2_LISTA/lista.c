#include <stdio.h>
#include <stdlib.h>
#include "TAD2.h"

struct lista{
    int elementos[max];
    int quant;
};

void preencher_lista(int *L, int tam){
    printf("\nPreencha a lista\n");
    for(int i =0; i<tam ; i++){
        printf("%dª posição: ", i+1);
        scanf("%d", &L[i]);
    }
}


int insere_começo(Lista *li, int elemento){
    if(li == NULL || (*li).quant == max-1 ){
        return 0;
    }
    if((*li).quant == 0){
        (*li).elementos[0]== elemento;
        return 1;
    }else{
        for(int i=(*li).quant -1; i>0 ; i--){
            (*li).elementos[i+1]= (*li).elementos[i];
            if(i==1){
                (*li).elementos[1]= (*li).elementos[0];
                (*li).elementos[0]= elemento;
                (*li).quant++;
            }
        }
        return 1;
    }
}


int insere_final(Lista *li, int elemento){
    if(li == NULL || (*li).quant == max-1){
        return 0;
    }
    (*li).elementos[(*li).quant]= elemento;
    (*li).quant++;
    return 1;
}

/*
    Função criada somente para remover elementos no começo da pilha.
*/
int remove_começo(Lista *li){
    if(li == NULL || (*li).quant == 0){
        return 0;
    }
    for(int i=0; i<(*li).quant-1; i++){
        (*li).elementos[i] = (*li).elementos[i+1];
    }
    (*li).quant--;
    return 1;
}

/*
    Função criada somente para remover elementos no final da lista.
*/
int remove_final(Lista *li){
    if(li == NULL || (*li).quant == 0){
        return 0;
    }
    (*li).quant--;
    return 1;
}

/*
    Função criada somente para buscar elementos da lista.
*/
void buscar_elemento(int num, int *L, int tam){
    L[tam+1] = num;
    int i=0;
    while(L[i] != num ){
        i++;
        if(i == tam+1){
            printf("\nO elemento não está na lista.\n");
            break;
        }
    }
    if( i != tam+1 && L[i] == num){
        printf("\nO elemento está na lista.\n");
    }

}
