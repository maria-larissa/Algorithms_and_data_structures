#include <stdio.h>
typedef struct atendimento{
    int atendimento;
    int medicamento;
    int quant;
}Atendimento;

typedef struct medicamentos{
    int codMedica;
    float precoUnidade;
}Medicamentos;

float gastoTotal(Atendimento atendimentos[], Medicamentos medicamentos[],int n_atendimentos, int n_medicamentos){
    float totalgasto=0, aux=0;
    for(int i=0; i<n_atendimentos; i++){
        for(int j=0; j<n_medicamentos; j++){
            if(atendimentos[i].medicamento == medicamentos[j].codMedica){
                totalgasto+=(atendimentos[i].quant * medicamentos[j].precoUnidade);;
            }
        }
    }
    return totalgasto;
}
int carregarAtendimentos (FILE* atendimentos, Atendimento vetorAtendimentos[]){
    int cod_atendimento, cod_medicamento, quant_remedio, i=0, cont=0;
    while(fscanf(atendimentos,"%d %d %d", &cod_atendimento, &cod_medicamento, &quant_remedio)!=EOF){
        vetorAtendimentos[i].atendimento = cod_atendimento;
        vetorAtendimentos[i].medicamento = cod_medicamento;
        vetorAtendimentos[i].quant = quant_remedio;
        ++cont;
        i++;
    }
    return cont;
}
int carregaMedicamentos(FILE *medicamentos, Medicamentos vetorMedicamentos[]){
    int codMedicamento, i=0, cont1=0;
    float precoUnidade;
    while(fscanf(medicamentos, "%d %f", &codMedicamento, &precoUnidade)!=EOF){
        vetorMedicamentos[i].codMedica = codMedicamento;
        vetorMedicamentos[i].precoUnidade = precoUnidade;
        ++cont1;
        i++;
    }
    return cont1;
}
int main(){
    FILE *p = fopen("atendimentos.txt","r");
    int numAtendimentos, numMedicamentos;
    Atendimento vetor_atendimentos[1000];
    Medicamentos vetor_medicamentos[1000];

    if(p==NULL){
        printf("\nErro na leitura do arquivo de atendimentos!\n");
    }else{
        numAtendimentos = carregarAtendimentos(p,vetor_atendimentos);
    }
    fclose(p);
    FILE *p1 = fopen("medicamentos.txt","r");
    if(p1==NULL){
        printf("\nErro na leitura do arquivo de medicamentos!\n");
    }else{
        numMedicamentos = carregaMedicamentos(p1,vetor_medicamentos);
    }
    fclose(p1);
    float total = gastoTotal(vetor_atendimentos,vetor_medicamentos,numAtendimentos, numMedicamentos);
    printf("\nForam gastos R$%.2f em medicamentos durante o último mês.\n", total);
    return 0;
}