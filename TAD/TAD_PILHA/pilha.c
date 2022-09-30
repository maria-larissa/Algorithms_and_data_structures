#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/*
    Funcão cria o ponteiro para primeira posicão da pilha.
*/
Pilha* cria_pilha(){
    Pilha* ptr = (Pilha*)malloc(sizeof(Pilha));
    if(ptr == NULL){
        return 0;
    }
    return ptr;
}

/*
    Função criada somente para destruir a pilha.
*/
void destruir(Pilha *p1){
    free(p1);
}

/*
    Função criada somente para analisar o tamanho da pilha.
*/
int tamanho(Pilha *pi){
    if(pi == NULL)
        return -1;
    return pi->qtd;
}

/*
    Função criada somente para criar structs aluno.
*/
Aluno *cria_aluno(){
    Aluno *al=(Aluno*)malloc(sizeof(Aluno));
    printf("\nDigite o nome: ");
    scanf(" %29[^\n]",&al->nome);
    printf("Digite o matricula: ");
    scanf("%d",&al->mat);
    if( al->nome != NULL){
        return al;
    }
}

/*
    Função criada somente para inserir elementos na pilha
*/
int inserir_Pilha(Pilha *pi){
    if(pi == NULL || pi->qtd == MAX){
        return 0;
    }else{
        Aluno *al=cria_aluno();
        if(al != NULL){
            pi->dados[pi->qtd] = *al;
            pi->qtd++;
            return 1;
        }
    }
}

/*
    Função criada somente para remover elementos da pilha
*/
int remover_Pilha(Pilha *pi){
    if(pi== NULL || pi->qtd==0){
        return 0;
    }
     pi->qtd--;
     return 1;
}

void imprimir_pilha(Pilha *Pi){
    int tam= tamanho(Pi);
    if(Pi != NULL && tam>0){
        for(int i=tam-1; i>=0; i--){
            Aluno al_aux=Pi->dados[i];
            printf("Nome: %s\t\tMatricula: %d\n", al_aux.nome, al_aux.mat);
        }
        printf("\n");
    }
}

/*
    Caso deseje fazer um teste cria um arquivo main.c cole o código 
    abaixo, faça a conexão com o arquivo pilha.h e execute.

int main(){
    Pilha *Pi=cria_pilha();
    printf("\tPREENCHENDO\n");
    inserir_Pilha(Pi);
    inserir_Pilha(Pi);
    inserir_Pilha(Pi);
    inserir_Pilha(Pi);
    inserir_Pilha(Pi);
    int tam=tamanho(Pi);
    printf("\nO tamanho da pilha é %d.\n", tam);
    imprimir_pilha(Pi);

    printf("\n\tREMOVENDO\n");
    remover_Pilha(Pi);
    imprimir_pilha(Pi);
    remover_Pilha(Pi);
    imprimir_pilha(Pi);
    remover_Pilha(Pi);
    imprimir_pilha(Pi);
    remover_Pilha(Pi);
    imprimir_pilha(Pi);
    remover_Pilha(Pi);
    imprimir_pilha(Pi);
    return 0;
}
*/