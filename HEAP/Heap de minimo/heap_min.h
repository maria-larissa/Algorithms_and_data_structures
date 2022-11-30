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
