#include <string.h>
#include "heap.h"


int main(){
    char tipo_heap[3];
    printf("\n\t\tHEAPS\n");
    printf("Heap de máximo - max\nHeap de mínimo - min\n\nDigite opção correspondente ao que deseja: ");
    scanf("%s", tipo_heap);

    H *h = criar_heap();
    if (strcmp("max", tipo_heap) == 0){
        preencher_heap_max(h);
        atualizar_max(h);
        atualizar_max(h);
        remocao_max(h);
    }else{
        preencher_heap_min(h);
        // atualizar_min(h);
        // atualizar_min(h);
        // atualizar_min(h);
        // atualizar_min(h);
        remocao_min(h);
    }
    return 0;
}