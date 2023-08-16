#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char descricao[100];
    float precoCompra;
    float precoVenda;
    int quantidadeEstoque;
    int estoqueMin;
};

struct Produto capacidade[40];
int contador = 0;

void adicionarProduto() {
    if (contador < 40) {
        struct Produto novoProduto;

        printf("Escreva o codigo do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Escreve a descricao do produto: ");
        scanf(" %99[^\n]s", novoProduto.descricao);
        printf("Escreva o preco de compra do produto: ");
        scanf("%f", &novoProduto.precoCompra);
        printf("Escreva o preco de venda do produto: ");
        scanf("%f", &novoProduto.precoVenda);
        printf("Coloque a quantidade no estoque: ");
        scanf("%d", &novoProduto.quantidadeEstoque);
        printf("Coloque o valor minimo para o estoque: ");
        scanf("%d", &novoProduto.estoqueMin);

        capacidade[contador] = novoProduto;
        contador++;

        printf("Produto Adicionado!\n");
    } else {
        printf("A capacidade de armazenamento esta cheia!.\n");
    }
}

void calculoLucro(int codigo) {
    for (int i = 0; i < contador; i++) {
        if (capacidade[i].codigo == codigo) {
            float lucro = (capacidade[i].precoVenda - capacidade[i].precoCompra) * capacidade[i].quantidadeEstoque;
            float lucroPorcentagem = (lucro / (capacidade[i].precoCompra * capacidade[i].quantidadeEstoque)) * 100;

            printf("O lucro no produto %d (%s) foi de: R$ %.2f\n", capacidade[i].codigo, capacidade[i].descricao, lucro);
            printf("Porcentagem de lucro: %.2f%%\n", lucroPorcentagem);

            return;
        }
    }

    printf("O produto nao foi encontrado!\n");
}

void produtosBaixoEstoque() {
    printf("Produtos com quantidade abaixo do estoque minimo:\n");
    for (int i = 0; i < contador; i++) {
        if (capacidade[i].quantidadeEstoque < capacidade[i].estoqueMin) {
            printf("Produto %d (%s) esta com baixo estoque: %d\n unidades", capacidade[i].codigo, capacidade[i].descricao, capacidade[i].quantidadeEstoque);
        }
    }
}

int main() {
    int opcao, codigo;

    do {
        printf("\nMenu:\n");
        printf("============================================\n");
        printf("1. Adicionar Produto\n");
        printf("============================================\n");
        printf("2. Calcular Lucro\n");
        printf("============================================\n");
        printf("3. Mostrar Produtos com Baixo Estoque\n");
        printf("============================================\n");
        printf("4. Sair\n");
        printf("============================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                printf("Escreva o codigo do produto: ");
                scanf("%d", &codigo);
                calculoLucro(codigo);
                break;
            case 3:
                produtosBaixoEstoque();
                break;
            case 4:
                printf("Saindo do Programa...\n");
                break;
            default:
                printf("Escolha inexistente. Tente Novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
