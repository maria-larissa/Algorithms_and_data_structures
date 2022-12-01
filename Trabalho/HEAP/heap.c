#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
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
        printf(MAG "\n\n***********CRIANDO UM HEAP***********\n" RESET);
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
    Funcão craida somente para preencher o heap de máximo.
*/
int preencher_heap_max(H *h){
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
                        int id_aux;
                        resultado_busca = busca(h,valor, id_aux);
                        
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
    As funções subir e descer foram criadas para manter a estrutura do
    heap de máximo mesmo que um valor seja atualizado.
*/
int subir_max(H *h, int id){
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

int descer_max(H *h, int id){
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
            printf("Troca ele[%d] = %d com ele[%d] = %d\n", id, h->elementos[id], maior, h->elementos[maior]);
            if(h->elementos[id] < h->elementos[maior]){
                int aux = h->elementos[maior];
                h->elementos[maior] = h->elementos[id];
                h->elementos[id] = aux;
                id = maior;
                descer_max(h,id);
            }
            printar_heap(h);
            return 1;
        }
    }
}


/*
    Funcão craida somente para preencher o heap de mínimo.
*/
int preencher_heap_min(H *h){
    if(h != NULL){
        printf(MAG "\n***********PREENCHENDO HEAP DE MÍNIMO***********\n" RESET);
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
                        int id_aux;
                        resultado_busca = busca(h,valor, id_aux);
                        
                        if(resultado_busca == 0){
                            h->elementos[i]= valor;
                            h->qtd++;
                            if (h->qtd >= 2 ){
                                subir_min(h, i);
                            }
                            printar_heap(h);
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
int busca(H *h, int valor, int id){
    if (h != NULL){
        for(int i=1; i<=h->qtd; i++){
            if (h->elementos[i] == valor){
                id = i;
                return 1;
            }

            if( i == h->qtd){
                return 0;
            }
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

                // Caso queira ver as trocas efetuadas descomente a linha abaixo
                // printf("\nTroca elem[%d] = %d com elem[%d] = %d\n", id, h->elementos[id], menor, h->elementos[menor] );
        
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
            if(h->elementos[j] > h->elementos[k]){    
                
                // Caso queira ver as trocas efetuadas descomente a linha abaixo  
                // printf("\nTroca elem[%d] = %d com elem[%d] = %d\n", k, h->elementos[k], j, h->elementos[j] );
                
                int aux = h->elementos[k];
                h->elementos[k] = h->elementos[j];
                h->elementos[j] = aux;
            }

            // j recebe posição do pai
            k = j;
            j = (int)j/2;
        }

        return 1;
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
        printf("\n");
    }else{
        printf(RED "\nErro!\n" RESET);
    }
}


/*
    Funcão criada somente para atualizar valores do heap de máximo e coloca-lo 
    na posição certa.
*/
void atualizar_max(H *h){
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

                int id_aux;
                int resultado_busca = busca(h, x, id_aux);
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

                int id_aux;
                int resultado_busca = busca(h, x, id_aux);
                if( resultado_busca == 0){
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

int remocao_max(H *h){
    if(h != NULL){
        if(h->qtd != 0){
            printf(MAG "\n***********REMOVENDO ELEMENTO***********\n" RESET);
            // Troca o 1º elemento com o último para poder remover
            int aux = h->elementos[h->qtd];
            h->elementos[h->qtd] = h->elementos[1];
            h->elementos[1] = aux;
            h->qtd--;
            int resultado = descer_max(h, 1);
            if(resultado == 1){
                printf(GRN "\nElemento removido com sucesso!\n\n" RESET);
            }
            return 1;

        }else{
            printf("\nHeap vazio!\n\n");
            free(h);
        }
    }
}

int remocao_min(H *h){
    if(h != NULL){
        if(h->qtd != 0){
            printf(MAG "\n***********REMOVENDO ELEMENTO***********\n" RESET);
           
            int aux = h->elementos[h->qtd];
            h->elementos[h->qtd] = h->elementos[1];
            h->elementos[1] = aux;
            h->qtd--;
            int resultado = descer_max(h, 1);
            if(resultado == 1){
                printf(GRN "\nElemento removido com sucesso!\n\n" RESET);
            }
            return 1;
           
        }else{
            printf("\nHeap vazio!\n\n");
            free(h);
        }
    }
}
