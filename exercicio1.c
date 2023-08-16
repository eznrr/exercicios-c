#include <stdio.h>
#include <string.h>

struct Conta {
    int conta;
    char nome[100];
    float saldo;
};

int numeroContas = 0;
struct Conta contas[15];

void cadastrarConta() {
    if (numeroContas >= 15) {
        printf("Limite maximo de contas atingido.\n");
        return;
    }

    struct Conta novaConta;
    printf("Numero da conta: ");
    scanf("%d", &novaConta.conta);

    for (int i = 0; i < numeroContas; i++) {
        if (contas[i].conta == novaConta.conta) {
            printf("Ja existe uma conta com esse numero.\n");
            return;
        }
    }

    printf("Nome do cliente: ");
    scanf(" %99[^\n]", novaConta.nome);

    printf("Saldo: ");
    scanf("%f", &novaConta.saldo);

    contas[numeroContas] = novaConta;
    numeroContas++;

    printf("Sua conta foi cadastrada!\n");
}

void visualizarContas() {
    char nomeBusca[100];
    printf("Digite o nome do cliente: ");
    scanf(" %99[^\n]", nomeBusca);

    printf("Contas de %s:\n", nomeBusca);
    for (int i = 0; i < numeroContas; i++) {
        if (strcmp(contas[i].nome, nomeBusca) == 0) {
            printf("Conta: %d | Saldo: %.2f\n", contas[i].conta, contas[i].saldo);
        }
    }
}

void excluirMenorSaldo() {
    if (numeroContas == 0) {
        printf("Nenhuma conta esta cadastrada no momento.\n");
        return;
    }

    int menorSaldo = 0;
    for (int i = 1; i < numeroContas; i++) {
        if (contas[i].saldo < contas[menorSaldo].saldo) {
            menorSaldo = i;
        }
    }

    printf("Conta %d excluida, seu saldo era de: '%.2f'\n", contas[menorSaldo].conta, contas[menorSaldo].saldo);

    for (int i = menorSaldo; i < numeroContas - 1; i++) {
        contas[i] = contas[i + 1];
    }

    numeroContas--;
}

int main() {
    int opcao;

    do {
        printf("1. Cadastrar contas\n");
        printf("2. Visualizar as contas\n");
        printf("3. Excluir a conta com menor saldo\n");
        printf("4. Sair\n");
        printf("Escolha o numero correspondente ao que deseja: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarConta();
                break;
            case 2:
                visualizarContas();
                break;
            case 3:
                excluirMenorSaldo();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Numero inválido.\n");
        }
    } while (opcao != 4);

    return 0;
}