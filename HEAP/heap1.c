#include <stdio.h>
#include <stdlib.h>
#include "heap1.h"
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define GRN "\x1B[32m"
#define MAG "\x1B[35m"


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

int subir(H *h, int id){
    if(h != NULL){
        // printf("\nANTES DA TROCA");
        // pri(ntar_heap(h);
        // printf("[((int)id/2)+1]", ((int)id/2)+1);
        while( h->elementos[id] > h->elementos[((int)id/2)] && id > 0){
            if ((int)id/2 ==0){
                break;
            }
            printf("[((int)id/2)+1]=%d", (((int)id/2)));
            int aux = h->elementos[((int)id/2)];
            h->elementos[((int)id/2)] = h->elementos[id];
            h->elementos[id] = aux;
            id = ((int)id/2);
        }
        // printf("\nDEPOIS DA TROCA");
        // printar_heap(h);
        return 1;
    }
}
//funcionando até aqui
int descer(H *h, int id){
    if(h != NULL){
        printf("\nANTES DA TROCA");
        printar_heap(h);
        int maior;
        int j = 2*id+1;
        //verifica se existe filho direita
        if(j <= h->qtd-1 && j < h->tam-1){
            maior = j;
            printf("\n1° - elem[maior] = %d", h->elementos[maior]);

            //verifica se existe filho esquerda
            printf("\nj = %d\n", j);
            printf("\nj+1 = %d\n", j+1);
            if( j+1 <= h->qtd-1 && j+1 < h->tam-1){
                //verifica quem é o maior
                if ( h->elementos[j+1] > h->elementos[maior]){
                    maior = j+1;
                    printf("\n2° - elem[maior] = %d", h->elementos[maior]);
                }
            }
            printf("\nelem[maior] = %d\n", h->elementos[maior]);
            int aux = h->elementos[maior];
            h->elementos[maior] = h->elementos[id];
            h->elementos[id] = aux;
            id = maior;
            printf("\nid = %d\n", id);
            printf("\nDEPOIS DA TROCA");
            printar_heap(h);
            // if((2*id+1 <= h->qtd-1) || (2*id+2 <= h->qtd-1))
            // if((h->elementos[id] < h->elementos[2*id+1]) || (h->elementos[id] < h->elementos[2*id+2]) )
            descer(h,id);
            return 1;
        }
    }
}

void atualizar(H *h){
    if(h != NULL){
        int resposta;
        if(h->tam == 0){
            printf("\nHeap vazio!\n");
        }else{
            printf(MAG "\n***********ATUALIZANDO ELEMENTO***********\n" RESET);
            //printar_heap(h);
            int id, x;
            printf("\nDigite o id do elemento: ");
            scanf("%d", &id);
            if(id >= 0 || id <= h->qtd-1){
                printf("Digite o novo valor: ");
                scanf("%d", &x);
                if(x > h->elementos[(int)id/2]){
                    h->elementos[id] = x;
                    resposta = subir(h,id);
                }else{
                    h->elementos[id] = x;
                    resposta = descer(h,id);
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
    return 0;
}