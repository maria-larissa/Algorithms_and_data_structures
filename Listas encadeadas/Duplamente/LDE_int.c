#include <stdio.h>
#include <stdlib.h>

/*
    Struct com todos os campos que cada elemento da lista terá.
*/
typedef struct no{
    int valor;
    struct no *anterior;
    struct no *sucessor;    
}No;

/*
    Definição do tipo de ponteiro que aponta para
    primeiro elemento(nó) da lista.
*/
typedef No *Lista;

/*
    Função criada o ponteiro para primeira posição da lista
    de números inteiros duplamente encadeada.
*/
Lista *criar_LDE(){
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        (*li) == NULL;
        return li;
    }
}

/*
    Função criada somente para inserir no inicio da lista.
*/
int insere_no_comeco(Lista *li,int valor){
    No *no = (No*)malloc(sizeof(no));
    if(no == NULL || li == NULL){
        return 0;
    }
    if((*li) == NULL){
        (*no).valor = valor;
        (*no).anterior = NULL;
        (*no).sucessor = NULL;
        (*li) = no;
        return 1;
    }else{
        (*no).valor = valor;
        (*no).anterior = NULL;
        (*no).sucessor = (*li);
        (*(*li)).anterior = no;
        (*li) = no;
        return 1;
    }
}

/*
    Função criada somente para inserir no final da lista.
*/
int insere_no_final(Lista *li,int valor){
    No *no = (No*)malloc(sizeof(no));
    if(no == NULL || li == NULL){
        return 0;
    }
    if((*li) == NULL){
        (*no).valor = valor;
        (*no).anterior = NULL;
        (*no).sucessor = NULL;
        (*li) = no;
        return 1;
    }else{
        No *aux = (*li);
        while((*aux).sucessor != NULL){
            aux = (*aux).sucessor;
        }
        (*no).valor = valor;
        (*no).anterior = (*li);
        (*no).sucessor = NULL;
        (*aux).sucessor = no;
        return 1;
    }
}

/*
    Função criada somente para remover o primeiro 
    elemento da lista, se não for vazia.
*/
int remover_começo(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    No *aux = (*li);
    if((*aux).sucessor == NULL){
        (*li) = NULL;
        free(aux);
        return 1;
    }else{
        (*li) = (*aux).sucessor;
        (*(*li)).anterior = NULL;
        free(aux);
        return 1;
    }
}

/*
    Função criada somente para remover o último 
    elemento da lista, se não for vazia.
*/
int remover_final(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    No *aux = (*li);
    if((*aux).sucessor == NULL){
        (*li) = NULL;
        free(aux);
        return 1;
    }else{
        /*
            Essa parte do código é responsável por chegar ao
            penultimo elemento da lista e através saber qual
            é o último elemento e remove-lo, sem ter que acessá-lo.
        */
        while((*aux).sucessor->sucessor != NULL){
            aux = (*aux).sucessor;
        }

        (*aux).sucessor = NULL;
        free((*aux).sucessor);
        return 1;
    }
}

/*
    Função criada somente para acessar os elementos da
    lista duplamente encadeada e imprimi-los.
*/
void imprimir(Lista *li){
    if(li == NULL){
        printf("\nERRO!\n");
    }
    if((*li) == NULL){
        printf("\nLista vazia!\n");
    }else{
        printf("\n**********Lista**********\n");
        No *aux = (*li);
        while((*aux).sucessor != NULL){
            printf("%3d", (*aux).valor);
            aux = (*aux).sucessor;
        }
        printf("%3d", (*aux).valor);
        printf("\n");
    }
}

/*
     Caso queira fazer um teste rápido utilize o código abaixo.
*/
int main(){
    /*
        Lista* li = criar_LDE();
        printf("\tPREENCHENDO\n");
        insere_no_comeco(li,3);
        imprimir(li);
        insere_no_comeco(li,2);
        imprimir(li);
        insere_no_comeco(li,1);
        imprimir(li);
        insere_no_final(li,4);
        imprimir(li);
        insere_no_final(li,5);
        imprimir(li);
        insere_no_final(li,6);
        imprimir(li);
        insere_no_final(li,7);
        imprimir(li);


        printf("\n\tREMOVENDO\n");
        remover_final(li);
        imprimir(li);
        remover_final(li);
        imprimir(li);
        remover_final(li);
        imprimir(li);
        remover_começo(li);
        imprimir(li);
        remover_começo(li);
        imprimir(li);
        remover_começo(li);
        imprimir(li);
        remover_começo(li);
        imprimir(li);
    */
    return 0;
}
