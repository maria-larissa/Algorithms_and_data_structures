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

void printar_heap(H *h);

int preencher_heap(H *h);

int busca(H *h, int valor);

int subir(H *h, int id);

int descer(H *h, int id);

void printar_heap(H *h);

void atualizar(H *h);

int remocao(H *h);