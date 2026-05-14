#include <stdio.h>
#include <stdlib.h>

// Funções 
float fazerSaque(float saldo) {
    float valor;
    printf("Digite o valor do saque: ");
    scanf("%f", &valor);

    if (valor > saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        saldo = saldo - valor;
        printf("Saque realizado!\n");
    }
    system("pause");
    return saldo;
}



//função main
int main() {
    float saldo = 500.0;
    int opcao = -1;

    // Variáveis para guardar as 3 últimas operações
    float h1 = 0, h2 = 0, h3 = 0;
    int operacoes = 0;

    while (opcao != 0) {
        system("cls");
        printf("1-Saldo | 2-Saque | 3-Deposito | 4-Extrato | 0-Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Saldo atual: R$ %.2f\n", saldo);
            system("pause");
        } 
        else if (opcao == 2) {
            float anterior = saldo;
            saldo = fazerSaque(saldo);
            
            // configurando o histórico
            if (saldo < anterior) {
                h3 = h2;
                h2 = h1;
                h1 = (anterior - saldo) * -1; // aqui é para transformar em negativo
            }
        } 
        else if (opcao == 3) {
            float anterior = saldo;
            saldo = fazerDeposito(saldo);
            
            h3 = h2;
            h2 = h1;
            h1 = saldo - anterior; 
        } 
        else if (opcao == 4) {
            printf("\n--- ULTIMAS OPERACOES ---\n");
            printf("1: R$ %.2f\n", h3);
            printf("2: R$ %.2f\n", h2);
            printf("3: R$ %.2f\n", h1);
            printf("Saldo Final: R$ %.2f\n", saldo);
            system("pause");
        }
    }

    return 0;
}