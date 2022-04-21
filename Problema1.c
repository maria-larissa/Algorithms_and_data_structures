#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pi{
    char elemento[5];
    int quant;
}Pilha;

int main(){
    char palavra[11];
    printf("\nDigite uma palavra: ");
    scanf("%10[^\n]", &palavra);
    //como saber quantas letras tem a palavra
    int cont = strlen(palavra);
    //printf("cont = %d\n", cont);

    if(cont%2 == 0){
        int tam = (cont/2)-1;
        int j=tam, k=tam+1;
        Pilha pilha;
        for(int i=0; i<=tam ; i++){
            pilha.elemento[i] = palavra[i];
            pilha.quant++;
         //   printf("pilha.elemento[%d] = %c\n", i,pilha.elemento[i]);
        }
        while(k < cont){
            if(pilha.elemento[j] == palavra[k]){
                pilha.quant--;
                if(pilha.quant == 0){
                    printf("A palavra '%s' é palindroma.\n", palavra);
                    break;
                }
                j--;
                k++;
                continue;
            }else{
                printf("A palavra '%s' não é palindroma.\n", palavra);
                break;
            }
        }
    }else{
        int tam2 = (cont+1)/2;
        int j=tam2-2, k=tam2;
        Pilha pilha2;
        for(int i=0;i<tam2-1;i++){
            pilha2.elemento[i]=palavra[i];
            pilha2.quant++;
           // printf("pilha2.elemento[%d] = %c\n", i,pilha2.elemento[i]);
        }
        while(k < cont){
            if(pilha2.elemento[j] == palavra[k]){
                pilha2.quant--;
                if(pilha2.quant == 0){
                    printf("A palavra '%s' é palindroma.\n", palavra);
                    break;    
                }
                j--;
                k++;
                continue;
            }else{
                printf("A palavra '%s' não é palindroma.\n", palavra);
                break;
            }
        }
    }
    return 0;
}