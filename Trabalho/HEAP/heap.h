#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RED "\x1B[31m"
#define RESET "\x1B[0m"
#define GRN "\x1B[32m"
#define MAG "\x1B[35m"

/*
    Struct com todos os campos que cada elemento da lista terá.
*/
typedef struct heap{
    int *elementos;
    int qtd;
    int tam;
}H;

H *criar_heap();

int preencher_heap_max(H *h);

int subir_max(H *h, int id);

int descer_max(H *h, int id);

int remocao_max(H *h);

int preencher_heap_min(H *h);

int busca(H *h, int valor, int id);

int subir_min(H *h, int id);

int descer_min(H *h, int id);

int remocao_min(H *h);

void printar_heap(H *h);

void atualizar_max(H *h);

void atualizar_min(H *h);