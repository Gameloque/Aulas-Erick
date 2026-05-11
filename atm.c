#include <stdio.h>
#include <stdlib.h>

// Prototipos das funcoes
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void limparBuffer();

int main() {
    float saldo = 1000;  // Saldo inicial
    int opcao;
    
    printf("Bem-vindo ao CAIXA ELETRONICO FIAP!\n");
    printf("Saldo inicial: R$ %.2f\n\n", saldo);
    
    // Loop principal - Mantem o sistema ativo
    do {
        system("cls || clear");  // Limpa tela (Windows/Linux/Mac)
        exibirMenu();
        
        // Leitura da opcao do usuario
        scanf("%d", &opcao);
        limparBuffer();  // Limpa buffer do teclado
        
        // Switch-case para processar a opcao
        switch(opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo);
                break;
            case 3:
                saldo = realizarDeposito(saldo);
                break;
            case 0:
                printf("\n=== OBRIGADO POR USAR NOSSO ATM! ===\n");
                printf("Volte sempre!\n");
                break;
            default:
                printf("\n OPCAO INVALIDA! Escolha entre 0 e 3.\n");
                system("pause || read -p 'Pressione Enter...'");  // Pausa cross-platform
        }
        
        // Pausa apos cada operacao (exceto saida)
        if(opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
        
    } while(opcao != 0);
    
    return 0;
}

// Funcao para exibir o menu principal
void exibirMenu() {
    printf("\n");
    printf("============================\n");
    printf("  CAIXA ELETRONICO FIAP  \n");
    printf("============================\n");
    printf(" 1 - Consultar Saldo\n");
    printf(" 2 - Realizar Saque\n");
    printf(" 3 - Realizar Deposito\n");
    printf(" 0 - Sair\n");
    printf("============================\n");
    printf("Digite sua opcao: ");
}

// Funcao para consultar saldo atual
void consultarSaldo(float saldo) {
    printf("\n");
    printf("===================\n");
    printf(" SALDO ATUAL \n");
    printf("===================\n");
    printf("R$ %.2f\n", saldo);
    printf("===================\n");
}

// Funcao para realizar saque com validacoes completas
float realizarSaque(float saldoAtual) {
    float valorSaque;
    
    printf("\n SAQUE\n");
    printf("--------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("Digite o valor do saque: R$ ");
    scanf("%f", &valorSaque);
    limparBuffer();
    
    // Validacoes de seguranca
    if(valorSaque <= 0) {
        printf(" Valor invalido! Deve ser maior que zero.\n");
        return saldoAtual;
    }
    
    if(valorSaque > 1000.00) {
        printf(" Limite diario excedido! Maximo R$ 1.000,00\n");
        return saldoAtual;
    }
    
    if(valorSaque > saldoAtual) {
        printf(" Saldo insuficiente!\n");
        printf("Voce tem: R$ %.2f\n", saldoAtual);
        return saldoAtual;
    }
    
    // Saque autorizado
    saldoAtual -= valorSaque;
    printf(" Saque de R$ %.2f realizado com sucesso!\n", valorSaque);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);
    
    return saldoAtual;
}

// Funcao para realizar deposito
float realizarDeposito(float saldoAtual) {
    float valorDeposito;
    
    printf("\n DEPOSITO\n");
    printf("-----------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("Digite o valor do deposito: R$ ");
    scanf("%f", &valorDeposito);
    limparBuffer();
    
    // Validacao do deposito
    if(valorDeposito <= 0) {
        printf(" Valor invalido! Deve ser maior que zero.\n");
        return saldoAtual;
    }
    
    saldoAtual += valorDeposito;
    printf(" Deposito de R$ %.2f realizado com sucesso!\n", valorDeposito);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);
    
    return saldoAtual;
}

// Funcao utilitaria para limpar buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}