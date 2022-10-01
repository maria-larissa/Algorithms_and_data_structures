#include <stdio.h>
#include <stdlib.h>
#include "heap1.h"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define GRN "\x1B[32m"
#define MAG "\x1B[35m"

/*
    Funcão cria o heap.
*/
H *criar_heap(){
    H *h =(H*) malloc(sizeof(H));
    if(h != NULL){
        printf(MAG "\n***********CRIANDO UM HEAP***********\n" RESET);
        printf("Digite o tamanho: ");
        int n;
        scanf("%d", &n);
        h->elementos = malloc(n*sizeof(int));
        h->qtd = 0;
        h->tam = n;
        return h;
    }
}

/*
    Funcão craida somente para preencher o heap.
*/
int preencher_heap(H *h){
    if(h != NULL){
        printf(MAG "\n***********PREENCHENDO UM HEAP***********\n" RESET);
        printf("Quantos elementos deseja inserir? ");
        int qtd_inserir;
        scanf("%d", &qtd_inserir);
        if(qtd_inserir <= (h->tam - h->qtd)){
            for(int i=1; i<=qtd_inserir; i++){
                printf("\nh.qtd=%d\n", h->qtd);
                printf("Digite o elemento: ");
                scanf("%d", &h->elementos[(h->qtd+1)]);
                h->qtd++;
                subir(h,i);
                printar_heap(h);
            }
            //printf("\nqtd = %d\n", h->qtd);
            return 1;
        }else{
            printf("\nSó é possivel inserir mais %d elementos.\n", (h->tam-h->qtd));
        }
    }
}

/*
    Funcão criada somente para printar os elementos existentes no heap.
*/
void printar_heap(H *h){
    if (h != NULL){
        printf(MAG "\n***********ELEMENTOS DO HEAP***********\n" RESET);
        for(int i=1; i<= (h->qtd) ;i++){
            printf("ele[%d] = %d\n", i, h->elementos[i]);
        }
    }else{
        printf(RED "\nErro!\n" RESET);
    }
}

/*
    As funções subir e descer foram criadas para manter a estrutura do
    heap mesmo que um valor seja atualizado.
*/
int subir(H *h, int id){
    if(h != NULL){
        while( h->elementos[id] > h->elementos[((int)id/2)] && id > 0){
            if ((int)id/2 ==0){
                break;
            }
            int aux = h->elementos[((int)id/2)];
            h->elementos[((int)id/2)] = h->elementos[id];
            h->elementos[id] = aux;
            id = ((int)id/2);
        }
        return 1;
    }
}

int descer(H *h, int id){
    if(h != NULL){
        int maior;
        int j = 2*id;
        //verifica se existe filho direita
        if(j <= h->qtd && j <= h->tam){
            maior = j;

            //verifica se existe filho esquerda
            if( j+1 <= h->qtd && j+1 <= h->tam){
                //verifica quem é o maior
                if ( h->elementos[j+1] > h->elementos[maior]){
                    maior = j+1;
                }
            }
            if( h->elementos[id] < h->elementos[maior]){
                int aux = h->elementos[maior];
                h->elementos[maior] = h->elementos[id];
                h->elementos[id] = aux;
                id = maior;
                descer(h,id);
                return 1;
            }
        }
    }
}

/*
    Funcão criada somente para atualizar valores do heap e coloca-lo 
    na posição certa.
*/
void atualizar(H *h){
    if(h != NULL){
        int resposta;
        if(h->tam == 0){
            printf("\nHeap vazio!\n");
        }else{
            printf(MAG "\n***********ATUALIZANDO ELEMENTO***********\n" RESET);
            int id, x;
            printf("\nDigite o id do elemento: ");
            scanf("%d", &id);
            if(id >= 1 || id <= h->qtd){
                printf("Digite o novo valor: ");
                scanf("%d", &x);
                printf("pai = %d", ((int)id/2));
                if(id == 1){
                    h->elementos[id] = x;
                    resposta = descer(h,id);
                }else{
                    if(x > h->elementos[(int)id/2]){
                        h->elementos[id] = x;
                        resposta = subir(h,id);
                    }
                    if (x < h->elementos[(int)id/2]){
                            h->elementos[id] = x;
                            resposta = descer(h,id);
                    }
                }
                
            }else{
                printf(RED "\nId inválido!\n" RESET);
            }
            if(resposta == 1){
                printf(GRN "\nElemento ATUALIZADO com sucesso!\n" RESET);
            }
        }
    }
}

/*
     Caso deseje fazer um teste cria um arquivo main.c cole o código 
    abaixo, faça a conexão com o arquivo pilha.h e execute.

int main(){
    H *h = criar_heap();
    preencher_heap(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    atualizar(h);
    printar_heap(h);
    return 0;
}
*/