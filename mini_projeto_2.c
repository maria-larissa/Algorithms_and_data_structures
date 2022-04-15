 #include <stdio.h>
//Estrutura cliente para guarda cpf e valor total de compras de cada cliente.
typedef struct cliente{
  int cpf;
  float total_compras;
}Cliente;

//Função para analisar os dados dos clientes, caso haja CPF's iguais é feito o somatóriodo valor de todas as compras feitas por esse.
Cliente* clientes(FILE *p, Cliente *vetor, int tam, int* cont){
  int i=0, cont2=0;
 
 //Verificando se o arquivo não está vazio.
  if(p == NULL){
    printf("\nErro na leitura!\n");
  }else{
    int cpf_cliente=0;
    float valor_compra=0;
    //Testando se lê o dado de cada linha arquivo.
    while((fscanf(p,"%d %f", &cpf_cliente, &valor_compra)==2 && i<100)){
      //Assegurando que não terá lixo no vetor.
      vetor[i].cpf = 0;
      vetor[i].total_compras = 0;
      if(i==0){
        vetor[i].cpf = cpf_cliente;
        vetor[i].total_compras = valor_compra;
        cont2++;     //Contador para quantidades de posições ocupadas no vetor;
       *(cont)+=1;   //Alterando o valor da variável "cont" do main. "cont2" é igual á "cont".
      }else{
        int j=0;
        while(j<=cont2){
        //Teste se o CPF do cliente já está no arquivo. Caso esteja e somado o valor da compra feita ao total já existente que esta relacionado aquele cpf.
         if(cpf_cliente == vetor[j].cpf){
            vetor[j].total_compras += valor_compra;
            i -= 1;
            break;
          }else if(j==cont2){
            //Caso seja um novo cliente, então é adicionado ao vetor de clientes.
            vetor[i].cpf = cpf_cliente;
            vetor[i].total_compras = valor_compra;
            cont2++;
            *(cont)+=1;
            break;
          }  
          j++;
        }
      }
      i++;
    }
  }
  return vetor;
}

//Função para analizar qual o cliente que possue o maior valor de compra na loja.
Cliente melhor_cliente(Cliente* vetor, int tam_preenchido){
  Cliente melhorCliente;
   for(int i=0; i<tam_preenchido; i++){
     //Comparação para saber qual é o maior valor de compra e qual o CPF do cliente.
     if(i==0){
       melhorCliente.total_compras = vetor[i].total_compras;
       melhorCliente.cpf= vetor[i].cpf;
     }else if(vetor[i].total_compras > melhorCliente.total_compras){
       melhorCliente.total_compras = vetor[i].total_compras;
       melhorCliente.cpf = vetor[i].cpf;
       break;
     }
  }
  return melhorCliente;
}

int main(){
 //vetor struct cliente
 //Altere o tamanho do vetor se necessário ou incremente código para o usuário inserir o tamanho do vetor.
  Cliente vetor[101];
  int cpf=0, cont=0;
  float compra=0;
 
 // O arquivo corresponde aos dados das vendas da loja e cada linha contém o cpf do comprador e o valor da respectiva compra.
 //Troque "venda.txt" pelo nome do arquivo a ser analizado. O arquivo deve ser no formato ".txt"
  FILE *p = fopen("venda.txt","r"); 
  
 clientes(p, vetor, 101, &cont);
 
 //Imprimindo na tela os dados de todos clientes.
 printf("\n\tVetor dados dos clientes\n");
  for(int i=0;  i<cont ; i++){
    printf("posição[%d]:\tCPF = %d\t\tValor compras = %.2f\n", i+1, vetor[i].cpf, vetor[i].total_compras);
  }

  //Imprimindo na tela as informações do cliente mais fiel.
  printf("\n\n\tDados do cliente ganhador\n");
  printf("CPF : %d\n", (melhor_cliente(vetor, cont)).cpf);
  printf("Valor total de compras : %.2f\n", (melhor_cliente(vetor,cont)).total_compras);
  printf("Parabéns você ganhou um vale compra de R$1.000,00!\n");
  return 0;
}
