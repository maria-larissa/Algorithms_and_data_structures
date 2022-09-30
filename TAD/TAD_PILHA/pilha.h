#define MAX 100     /* Quantidade máxima de elementos */

/*
    Struct com todos os campos que cada aluno terá.
*/
typedef struct aluno{
    char nome[30];
    int mat;
}Aluno;

/*
    Struct com todos os campos que cada elemento da pilha terá.
*/
typedef struct pilha{
    int qtd;
    struct aluno dados[MAX];
}Pilha;

/*
    Definicão do tipo de ponteiro que aponta para
    primeiro elemento(nó) da lista.
*/
typedef struct pilha Pilha;

Pilha* cria_pilha();

void destruir(Pilha *pi);

int tamanho(Pilha *pi);

int inserir_Pilha(Pilha *pi);

int remover_Pilha(Pilha *pi);