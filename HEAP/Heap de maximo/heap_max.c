#include "heap_max.h"

/*
    Funcão cria o heap.
*/
H *criar_heap(){
    H *h =(H*) malloc(sizeof(H));
    if(h != NULL){
        printf(MAG "\n***********CRIANDO UM HEAP DE MÁXIMO***********\n" RESET);
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
    Funcão craida somente para preencher o heap.
*/
int preencher_heap(H *h){
    if(h != NULL){
        printf(MAG "\n***********PREENCHENDO HEAP DE MÁXIMO***********\n" RESET);
        while (h->qtd != h->tam){
            printf("Quantos elementos deseja inserir? ");
            int qtd_inserir;
            scanf("%d", &qtd_inserir);
            if(qtd_inserir <= (h->tam - h->qtd)){
                qtd_inserir+= h->qtd;
                for(int i=h->qtd+1; i<=qtd_inserir; i++){

                    int resultado_busca = 1;
                
                    while(resultado_busca == 1){
                    
                        printf("\nDigite o %dº elemento: ", i);
                        int valor;
                        scanf("%d", &valor);
                        
                        // Busca o elemento dentro do heap
                        resultado_busca = busca(h,valor);
                        
                        if(resultado_busca == 0){
                            h->elementos[i] = valor;
                            h->qtd++;
                            subir_max(h,i);
                        }
                        if(resultado_busca == 1){
                            printf("\n\nO elemento já existe no heap.\nTENTE NOVAMENTE!\n");
                        }
                    }

                }
            }else{
                printf("\nSó é possivel inserir mais %d elementos.\n\n", (h->tam-h->qtd));
            }
        }
        return 1;
    }
}


/*
    Função criada para buscar o elemento no heap
*/
int busca(H *h, int valor){
    if (h != NULL){
        for(int i=1; i<=h->qtd; i++){
            if (h->elementos[i] == valor){
                return 1;
            }

            if( i == h->qtd){
                return 0;
            }
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
        while(id > 1 && h->elementos[id] > h->elementos[(int)id/2]){
            
            // Caso queira ver as trocas efetuadas descomente a linha abaixo
            // printf("Troca ele[%d] = %d com ele[%d] = %d\n", id, h->elementos[id], (int)id/2, h->elementos[(int)id/2]);
            
            int aux = h->elementos[(int)id/2];
            h->elementos[(int)id/2] = h->elementos[id];
            h->elementos[id] = aux;
            id = (int)id/2;
        }
        printar_heap(h);
        return 1;
    }
}

int descer(H *h, int id){
    if(h != NULL){
        int maior;
        int j = 2*id;
        //verifica se existe filho esquerda
        if(j <= h->qtd && j <= h->tam){
            maior = j;
            //verifica se existe filho direita
            if( j+1 <= h->qtd && j+1 <= h->tam){
                //verifica quem é o maior
                if ( h->elementos[j+1] > h->elementos[maior]){
                    maior = j+1;
                }
            }

            // Caso queira ver as trocas efetuadas descomente a linha abaixo
            // printf("Troca ele[%d] = %d com ele[%d] = %d\n", id, h->elementos[id], maior, h->elementos[maior]);
            
            int aux = h->elementos[maior];
            h->elementos[maior] = h->elementos[id];
            h->elementos[id] = aux;
            id = maior;
            descer_max(h,id);
            printar_heap(h);
            return 1;
        }
    }
}

/*
    Funcão criada somente para atualizar valores do heap e coloca-lo 
    na posição certa.
*/
void atualizar(H *h){
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

                int resultado_busca = busca(h, x);
                if( resultado_busca == 0){
                    if(id == 1){
                        if( x < h->elementos[1] ){
                            h->elementos[1] = x;
                            subir_max(h,id);
                        }
                    }else{
                        if(x > h->elementos[(int)id/2]){
                            h->elementos[id] = x;
                            resposta = subir_max(h,id);
                        }else{
                            h->elementos[id] = x;
                            resposta = descer_max(h,id);
                        }
                    }
                }else{
                    printf("\nO elemento já existe no heap.\n");
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
    abaixo, faça a conexão com o arquivo heap1.h e execute.

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