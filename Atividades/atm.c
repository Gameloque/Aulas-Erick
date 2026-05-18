#include <stdio.h>
#include <stdlib.h>

//Funções usadas
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void limparBuffer();

int main() {
    float saldo = 0;  // Saldo inicial, como se fosse uma conta nova
    int opcao;
    
    printf("Bem-vindo ao CAIXA ELETRONICO FIAP!\n");
    printf("Saldo inicial: R$ %.2f\n\n", saldo);
    
    // Esse é o loop principal para manter o sistema ativo
    do {
        system("cls || clear");  // Limpar a tela
        exibirMenu();
        
        // Leitura da opção do usuário
        scanf("%d", &opcao);
        limparBuffer();  // Limpar o buffer do teclado
        
        // Switch-case para processar a opção selecionada, bem simples
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
                system("pausa || ler -p 'Pressione Enter...'");
        }
        
        // Pausa após cada operação (exceto saida) -- Assim o usuário verifica se está tudo correto
            if(opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
        
    } while(opcao != 0);
    
    return 0;
}

// Função para exibir o menu principal -- Funciona igual arduíno? kkk
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

// Função para consultar o saldo atual
void consultarSaldo(float saldo) {
    printf("\n");
    printf("===================\n");
    printf(" SALDO ATUAL \n");
    printf("===================\n");
    printf("R$ %.2f\n", saldo);
    printf("===================\n");
}

// Função para realizar o saque
float realizarSaque(float saldoAtual) {
    float valorSaque;
    
    printf("\n SAQUE\n");
    printf("--------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("Digite o valor do saque: R$ ");
    scanf("%f", &valorSaque);
    limparBuffer();
    
    // Validações de seguranca para verificar se o usuário não tente burlar o sistema com valores negativos ou exceder um máximo de 1000 reais
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
    
    // Saque autorizado -- Aqui Printa se o saque for 100% autorizado
    saldoAtual -= valorSaque;
    printf(" Saque de R$ %.2f realizado com sucesso!\n", valorSaque);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);
    
    return saldoAtual;
}

// Função para realizar depósito 
float realizarDeposito(float saldoAtual) {
    float valorDeposito;
    
    printf("\n DEPOSITO\n");
    printf("-----------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("Digite o valor do deposito: R$ ");
    scanf("%f", &valorDeposito);
    limparBuffer();
    
    // Validação do deposito --- Ou seja, Verifica se o depósito é válido ou não
    if(valorDeposito <= 0) {
        printf(" Valor invalido! Deve ser maior que zero.\n");
        return saldoAtual;
    }
    
    saldoAtual += valorDeposito;
    printf(" Deposito de R$ %.2f realizado com sucesso!\n", valorDeposito);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);
    
    return saldoAtual;
}

// Função para limpar o buffer do teclado, está fora do main, pois assim pode ser chamada na função globalmente, sem ocorrer problemas
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}