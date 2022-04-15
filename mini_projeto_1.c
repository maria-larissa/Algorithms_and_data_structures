#include <stdio.h>

int main(){
    int resposta1, resposta2;
    int total_pessoas=0;
    int cod_acao=0;
    int pessoas_b=0,total_pessoas_b=0, pessoas_c=0,total_pessoas_c=0, pessoas_j=0,total_pessoas_j=0;
    int cont_acao=0, total_acao_b=0, total_acao_c=0, total_acao_j=0;
    float media=0;
    do{
        do{
            do{
                /*  Menu principal do programa
                * Esse é o menu que o usuário vai interagir cadatrando novas ações ou imprimindo o relatório das ações cadastradas até agora.
                */
                printf("\n\t\t   Menu Principal");
                printf("\nDigite 1 para cadastrar dados de uma ação\n"
                       "Digite 2 para encerrar o cadastro e imprimir o relatório\n");
                scanf("%d", &resposta1);
                
                //Caso o usuário digite um valor inválido retorna-se ao menu principal, para repetir o precesso.
                if(resposta1<1 || resposta1 >2){
                    printf("\nValor digitado inválido. Tente novamente!\n");
                    
                //Caso o usuário digite 1 então é pedido as informações acerca da ação realizada.
                }else if(resposta1 == 1){
                        //O código da ação é um número inteiro.
                        printf("\nDigite o código da ação.\n");
                        scanf("%d", &cod_acao);
                        cont_acao++;  // Contabiliza cada ação nova cadastrada.
                    
                        char cidade;
                        printf("\nEm qual cidade foi realizada?\n");
                        printf("\nBarbalha - digite 'b'\nCrato    - digite 'c'\nJuazeiro do Norte - digite 'j'\n");
                        scanf(" %c",&cidade);
                        
                        //Para cada cidade há uma contabilização das ações realizadas e das pessoas beneficiadas.
                        if(cidade == 'b'){
                            printf("\nQuantas pessoas foram beneficiadas?\n");
                            scanf("%d", &pessoas_b);
                            total_pessoas_b+=pessoas_b;
                            total_acao_b++;
                        }
                        if(cidade == 'c'){
                            printf("\nQuantas pessoas foram beneficiadas?\n");
                            scanf("%d", &pessoas_c);
                            total_pessoas_c+=pessoas_c;
                            total_acao_c++;
                        }
                        if(cidade == 'j'){
                            printf("\nQuantas pessoas foram beneficiadas?\n");
                            scanf("%d", &pessoas_j);
                            total_pessoas_j+=pessoas_j;
                            total_acao_j++;
                        }
                    
                        //Contabilização total de pessoas beneficiadas por todas as ações.
                        total_pessoas = total_pessoas_b + total_pessoas_c + total_pessoas_j;
                    }
                
                    //Calculo da média de pessoas beneficiadas por cada ação.
                    media = (float)total_pessoas/(float)cont_acao;
                   
                    //Visualização do relatório pelo usuário.
                    if( resposta1 == 2){
                        printf("\n\t\t\t      Relatório \n");
                        printf("\nForam realizadas %d ações com %d pessoas beneficiadas em Barbalha.", total_acao_b,total_pessoas_b);
                        printf("\nForam realizadas %d ações com %d pessoas beneficiadas em Crato.", total_acao_c,total_pessoas_c);
                        printf("\nForam realizadas %d ações com %d pessoas beneficiadas em Juazeiro do Norte.", total_acao_j,total_pessoas_j);
                        printf("\nNo total foram realizadas neste ano %d ações.", cont_acao);
                        printf("\nNO total foram beneficiadas neste ano %d pessoas.",total_pessoas);
                        printf("\nA média de beneficiados pelas ações realizadas neste ano foi de %.2f.\n",media);
                        
                        //Opção de retornar ao menu principal e repetir todo o processo.
                        printf("\nVocê deseja voltar ao menu principal? (1 - SIM , 2 - NÃO)\n");
                        scanf("%d", &resposta2);
                    }
            }while(resposta1 == 1);
        }while(resposta2 == 1 );
    }while(resposta1<1 || resposta1>2);
    return 0;
}
