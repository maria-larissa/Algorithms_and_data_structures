#include "heap_min.h"

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
        h->elementos = malloc((n+1)*sizeof(int));
        h->qtd = 0;
        h->tam = n;
        return h;
    }
}

/*
    Funcão craida somente para preencher o heap de mínimo.
*/
int preencher_heap_min(H *h){
    if(h != NULL){
        printf(MAG "\n***********PREENCHENDO HEAP DE MÍNIMO***********\n" RESET);
        printf("Quantos elementos deseja inserir? ");
        int qtd_inserir;
        scanf("%d", &qtd_inserir);
        if(qtd_inserir <= (h->tam - h->qtd)){
            qtd_inserir+= h->qtd;
            for(int i=h->qtd+1; i<=qtd_inserir; i++){
                printf("\n%d\n",i);
                printf("Digite o elemento: ");
                scanf("%d", &h->elementos[i]);
                h->qtd++;
                if (h->qtd >= 2 ){
                    printf("\nelem[%d]= %d\nelem[%d] = %d\n", (int)i/2, h->elementos[(int)i/2], i, h->elementos[i]);
                    descer_min(h, i);
                }
            }
            return 1;
        }else{
            printf("\nSó é possivel inserir mais %d elementos.\n", (h->tam-h->qtd));
        }
    }
}

/*
    As funções subir e descer foram criadas para manter a estrutura do
    heap de mínimo mesmo que um valor seja atualizado.
*/
int descer_min(H *h, int id){
    if (h != NULL){
        int j = 2*id;
        int menor;
        // verifica se filho a esquerda existe
        if (j <= h->qtd && j <= h->tam){
            menor = j;
            
            // Verifica se filho da direita existe
            if(j+1 <= h->qtd && j+1 <= h->tam){
                if(h->elementos[j + 1] < h->elementos[j]){
                    menor = j + 1; 
                }
            }
        
            if(h->elementos[id] > h->elementos[menor]){
                printf("\nmenor -> elem[%d] = %d", menor, h->elementos[menor]);
                printf("\nTroca elem[%d] = %d com elem[%d] = %d\n", id, h->elementos[id], menor, h->elementos[menor] );
                int aux = h->elementos[menor];
                h->elementos[menor] = h->elementos[id];
                h->elementos[id] = aux;
                id = menor;
                descer_min(h, id);
            }
        }
        return 1;
    }
}

int subir_min(H *h, int id){
    if( h != NULL){
        int j = (int)id/2;      //pai
        int k = id;             //atual
            
        //Compara com todos os elementos até chegar na raiz
        while(j >= 1){
            printf("\nj(pai) = %d\n", j);
            printf("\nk(atual) = %d\n", k);
            if(h->elementos[j] > h->elementos[k]){    
                printf("\nTroca elem[%d] = %d com elem[%d] = %d\n", k, h->elementos[k], j, h->elementos[j] );
                int aux = h->elementos[k];
                h->elementos[k] = h->elementos[j];
                h->elementos[j] = aux;
            }

            // j recebe posição do pai
            k = j;
            j = (int)j/2;
            // descer_min(h,j);
        }
        printar_heap(h);
        return 1;
    }
}


/*
    Funcão criada somente para atualizar valores do heap de mínimo e coloca-lo 
    na posição certa.
*/
void atualizar_min(H *h){
    if(h != NULL){
        int resposta=0;
        if(h->tam == 0){
            printf("\nHeap vazio!\n");
        }else{
            printf(MAG "\n***********ATUALIZANDO ELEMENTO***********\n" RESET);
            //printar_heap(h);
            int id, x;
            printf("\nDigite o id do elemento: ");
            scanf("%d", &id);
            if(id >= 1 && id <= h->qtd){
                printf("Digite o novo valor: ");
                scanf("%d", &x);
                if(id == 1){

                    // Se for maior que o valor que estava precisa descer
                    if(x > h->elementos[1] ){
                        h->elementos[1] = x;
                        descer_min(h, id);
                    }

                    // Se for meno só atualiza
                    if(x < h->elementos[1]){
                        h->elementos[1] = x;
                    }
                }else{
                    
                    // Se for maior do que o valor que existia desce
                    if( x > h->elementos[id]){
                        h->elementos[id] = x;
                        descer_min(h,id);

                    // se for menor que o valor que existia sobe 
                    }else{
                        h->elementos[id]= x;
                        subir_min(h,id);
                    }

                }
                printar_heap(h);
            }
        }
    }
}
