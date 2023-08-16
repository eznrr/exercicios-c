#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    float valor_vendas[3];
    float pontos[3];
    float totalPontos;
} Funcionarios;

void cadastroFuncionarios(Funcionarios funcionarios[]){

    for(int i = 0; i < 15; i++){
        printf("Insira o nome do Funcionario: ", i + 1);
        scanf(" %99[^\n]", funcionarios[i].nome);

        for(int j = 0; j < 3; j++){
            printf("O funcionario %s, vendeu quanto no mes %d: ", funcionarios[i].nome, j + 1);
            scanf("%f", &funcionarios[i].valor_vendas[j]);
        }
    }
}

void calculoPontuacao(Funcionarios *funcionario) {

    for(int i = 0; i < 3; i++){
        funcionario->pontos[i] = funcionario->valor_vendas[i] / 1000;
        funcionario->totalPontos += funcionario->pontos[i];
    }

}

void pontuacao(Funcionarios funcionarios[], int mes){

    if (mes == 1){
        printf("\nA pontuação geral dos funcionarios no mes de Novembro:\n");
        for(int i = 0; i < 15; i++){
            printf("%s: %.2f\n", funcionarios[i].nome, funcionarios[i].pontos[mes]);
        }
    }else if(mes == 2){
        printf("\nA pontuação geral dos funcionarios no mes de Dezembro:\n");
        for(int i = 0; i < 15; i++){
            printf("%s: %.2f\n", funcionarios[i].nome, funcionarios[i].pontos[mes]);
        }
    }else{
        printf("\nA pontuação geral dos funcionarios no mes de Janeiro:\n");
        for(int i = 0; i < 15; i++){
            printf("%s: %.2f\n", funcionarios[i].nome, funcionarios[i].pontos[mes]);
        }
    } 
}

void pontuacaoGeral(Funcionarios funcionarios[]){
    printf("\nA pontuacao geral dos funcionarios nos 3 meses foi:\n");
    for(int i = 0; i < 15; i++){
        printf("%s: %.2f\n", funcionarios[i].nome, funcionarios[i].totalPontos);
    }
}

void maiorPontuacao(Funcionarios funcionarios[]){

    float pontuacaoMaior = -1;
    char nomeMaiorPontuador[100];

    for(int i = 0; i < 15; i++){
        if(funcionarios[i].totalPontos > pontuacaoMaior){
            pontuacaoMaior = funcionarios[i].totalPontos;
            strcpy(nomeMaiorPontuador, funcionarios[i].nome);
        }
    }

    printf("\nA maior pontuacao dentro dos tres meses foi de: %s\n", nomeMaiorPontuador);
    printf("Sua pontuação foi de: %.2f\n", pontuacaoMaior);
}

float totalVendido(Funcionarios funcionarios[]) {
    float total = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            total += funcionarios[i].valor_vendas[j];
        }
    }
    return total;
}

int main(){
    Funcionarios funcionarios[15];

    cadastroFuncionarios(funcionarios);

    for(int i = 0; i < 15; i++){
        calculoPontuacao(&funcionarios[i]);
    }

    for(int i = 0; i < 3; i++){
        pontuacao(funcionarios, i);
    }
    
    pontuacaoGeral(funcionarios);

    maiorPontuacao(funcionarios);

    float valorTotal = totalVendido(funcionarios);
    printf("\nValor total vendido dentro dos 3 meses: R$ %.2f\n", valorTotal);

    return 0;
}
