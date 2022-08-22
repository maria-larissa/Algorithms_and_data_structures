#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct heap
{
    int *elementos;
    int qtd;
    int tam;
}H;

H *criar_heap(){
    H *h =(H*) malloc(sizeof(H));
    if(h != NULL){
        printf("\n***********CRIANDO UM HEAP***********\n");
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
        printf("\n***********PREENCHENDO UM HEAP***********\n");
        printf("Quantos elementos deseja inserir?\n");
        int qtd_inserir;
        scanf("%d", &qtd_inserir);
        if(qtd_inserir <= (h->tam - h->qtd)){
            qtd_inserir+= h->qtd;
            for(int i=h->qtd; i<qtd_inserir; i++){
                printf("Digite o elemento: ");
                scanf("%d", &h->elementos[i]);
                h->qtd++;
            }
            printf("\nqtd = %d\n", h->qtd);
            return 1;
        }else{
            printf("\nSó é possivel inserir mais %d elementos.\n", (h->tam-h->qtd));
        }
    }
}

void printar_heap(H *h){
    if (h != NULL){
        printf("\nELEMENTOS DO HEAP\n");
        for(int i=0; i<h->qtd ;i++){
            printf("ele[%d] = %d\n", i, h->elementos[i]);
        }
    }
}

int atualizar(H *h){
    printf("\nATUALIZANDO ELEMENTO\n");
    if(h->qtd = 0){
        printf("\nHeap vazio!\n");
    }else{
        printf("\nDigite o ID do elemento: ");
        int id, x;
        scanf("%d", &id);
        printf("\nDigite o novo valor: ");
        scanf("%d", &x);
        if(0 <= id || id <= h->tam-1){
            if(h->elementos[id] > h->elementos[(int)(id/2)]){
                subir(h,id,x);
            }else{
                descer(h,id,x);
            }
        }else{
            printf("\nO id não existe!\n");
        }
    }
}

int subir(H *h,int id, int x){
    if(h != NULL){
        while(h->elementos[id] >= h->elementos[(int)id/2]){
            int pai = (int)id/2;
            printf("\nfloor(i/2) = %d\n", (int)id/2);
            printf("\nAntes da troca\n");
            printf("h.ele[id] = %d\n", h->elementos[id]);
            printf("h.ele[pai] = %d\n", h->elementos[pai]);
            

            // troca
            int aux = h->elementos[pai];
            h->elementos[pai] = h->elementos[id];
            h->elementos[id] = aux;
            id = pai;
            //

            printf("\nDepois da troca\n");
            printf("\nh.ele[i] = %d\n", h->elementos[id]);
            printf("\nh.ele[pai] = %d\n", h->elementos[pai]);
        }
    }
}

int descer(H *h, int id, int x){
    //teste filho esquerdo existe
    if(h != NULL){

        if(h->elementos[2*id+1] != NULL){
            int filho1 = h->elementos[2*id+1];
            printf("\nfilho1 = %d\n", filho1);
            int maior = filho1;


            //teste filho direito existe
            if(h->elementos[2*id+2] != NULL){
                int filho2 = h->elementos[2*id+2];
                printf("\nfilho2 = %d\n", filho2);
                
                //teste qual é o maior
                if(filho2 > maior){
                    maior = filho2;
                }
            }    
        }
    }    
}

int main(){
    H *h = criar_heap();
    preencher_heap(h);
    preencher_heap(h);
    printar_heap(h);

    return 0;
}