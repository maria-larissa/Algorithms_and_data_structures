#define max 100
typedef struct lista Lista;

void buscar_elemento(int num, int *L, int tam);
void preencher_lista(int *L, int tam);

int insere_começo(Lista *li, int elemento);
int insere_final(Lista *li, int elemento);

int remove_começo(Lista *li);
int remove_final(Lista *li);
