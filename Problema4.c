#include <stdio.h>
#include <stdlib.h>
#define max 100     //Tamanho máximo de elementos

/*  
    Struct que define os campos de cada elemento da pilha.
*/
typedef struct elemento{
    int valor;
    int pos;
}Elemento;

/*  
    Struct que define os da pilha.
*/
typedef struct pilha
{
    Elemento vetor[max];
    int quant;    
}Pilha;

/*  
    Função para cria uma pilha dinâmicamente.
*/
Pilha *criar_pilha(int tam){
    Pilha *pi = (Pilha*)malloc(tam*sizeof(Elemento));
    printf("\nPreencha a pilha");
    int i=tam;
    while(i>0){
        printf("\nposição[%d]: ", i);
        scanf("%d", &(*pi).vetor[i]);
        (*pi).quant++;
        i--;
    }
    return pi;
}

/*
    Caso queira testar, basta decomentar o código a seguir
    e executar o arquivo.
*/
int main(){
    int i=1, tam;
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tam);
    Pilha *pi = criar_pilha(tam);
    printf("\n\tPILHA");
    while(i<=tam){
        printf("\nposição[%d]= %d ", i, (*pi).vetor[i]);
        i++;
    }
    printf("\n");
    return 0;
}
// */