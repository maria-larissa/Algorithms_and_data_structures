#include <stdio.h>
#include <stdlib.h>

/*
    Struct com todos os campos que cada elemento da lista terá.
*/
typedef struct no{
    float valor;
    struct no *prox;
}No;

/*
    Definicão do tipo de ponteiro que aponta para
    primeiro elemento(nó) da lista.
*/
typedef struct no *Lista;

/*
    Funcão cria o ponteiro para primeira posicão da lista
    de números reais simples encadeada.
*/
Lista *criar_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        (*li) = NULL;
        return li;
    }
}

/*
    Funcão criada somente para inserir no inicio da lista.
*/
int insere_no_comeco(Lista *li){
    No *no = (No*)malloc(sizeof(No));

    //confere se os ponteiros foram bem declarados
    if(no == NULL || li == NULL){
        return 0;
    }

    //preenchendo o nó
    printf("Digite o valor: ");
    scanf("%f", &(*no).valor);
    
    if(*li == NULL){
        //se lista vazia passase o endereco do nó criado para a Lista
        *li = no;
    
        //proximo recebe null
        (*no).prox = NULL;
        return 1;
    }else{
        /*caso a lista já tenha alguém passamos o 1º nó como proximo do no 
        que está sendo inserido*/
        (*no).prox = (*li);

        //faz inicio da lista apontar pro nó inserido
        *li= no;
        return 1;
    }
}

/*
    Funcão criada somente para inserir no final da lista.
*/
int insere_no_final(Lista *li){
    No *no = (No*) malloc(sizeof(No));
    if(li == NULL || no == NULL){
        return 0;
    }
    if((*li) == NULL){
        printf("\nDigite o valor: ");
        //scanf("%f", &no->valor);
        scanf("%f", &(*no).valor);
        (*no).prox = NULL;    
        (*li) = no;
        return 1;
    }
    No *aux = (*li);
    while((*aux).prox != NULL){
        aux = (*aux).prox;
    }

    printf("\nDigite o valor: ");
    //scanf("%f", &no->valor);
    scanf("%f", &(*no).valor);
    (*no).prox = NULL;
    (*aux).prox = no;
    return 1;
}


/*
    Funcão criada somente para remover o primeiro 
    elemento da lista, se não for vazia.
*/
int remover_comeco(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    No *aux = (*li);
    if((*aux).prox == NULL){
        (*li) = NULL;
        free(aux);
        return 1;
    }else{
        (*li) = (*aux).prox;
        free(aux);
        return 1;
    }
}


/*
    Funcão criada somente para remover o último 
    elemento da lista, se não for vazia.
*/
int remover_final(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    No *aux = (*li);
    if((*aux).prox == NULL){
        (*li) = NULL;
        free(aux);
        return 1;
    }else{
        /*
            Essa parte do código é responsável por chegar ao
            penultimo elemento da lista e através saber qual
            é o último elemento e remove-lo, sem ter que acessá-lo.
        */
        while((*aux).prox->prox != NULL){
            aux = (*aux).prox;
        }

        (*aux).prox = NULL;
        free((*aux).prox);
        return 1;
    }
}

/*
    Funcão criada somente para analisar o tamanho da lista.
*/
int tamanho(Lista *li){
    if(li == NULL){
        return -1;
    }
    if((*li) == NULL){
        return 0;
    }

    int cont = 1;
    No *aux = (*li);
    while((*aux).prox != NULL){
        aux = (*aux).prox;
        cont++;
    }
    return cont;
}

/*
    Funcão criada somente para acessar os elementos da
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
        while((*aux).prox != NULL){
            printf("%.2f   ", (*aux).valor);
            aux = (*aux).prox;
        }
        printf("%.2f  ", (*aux).valor);
        printf("\n");
    }
}

/*
     Caso queira fazer um teste rápido utilize o código abaixo.
*/
int main(){
    /*
    Lista *li = criar_lista();
    printf("\tPREENCHENDO\n");
    insere_no_comeco(li);
    imprimir(li);
    insere_no_comeco(li);
    imprimir(li);
    insere_no_comeco(li);
    imprimir(li);
    insere_no_final(li);
    imprimir(li);
    insere_no_final(li);
    imprimir(li);
    insere_no_final(li);
    imprimir(li);
    insere_no_final(li);
    imprimir(li);
    
    printf("\nO tamanho da lista é %d.\n", tamanho(li));    

    printf("\n\tREMOVENDO\n");
    remover_final(li);
    imprimir(li);
    remover_final(li);
    imprimir(li);
    remover_final(li);
    imprimir(li);
    remover_comeco(li);
    imprimir(li);
    remover_comeco(li);
    imprimir(li);
    remover_comeco(li);
    imprimir(li);
    remover_comeco(li);
    imprimir(li);

    printf("\nO tamanho da lista é %d.\n", tamanho(li));  
    */  
    return 0;
}
