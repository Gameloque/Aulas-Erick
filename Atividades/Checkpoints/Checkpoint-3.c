#include <stdio.h>
#include <stdlib.h> // Usado para dar o ("cls") e ("pause") -- Não estudamos ainda, mas quis implementar para o melhor funcionamento do sistema

// Funções usadas no texto
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void limparBuffer();

int main()
{
    float saldo = 0; // Saldo inicial, como se não tivsse nada no começo da operação do caixa
    int opcao;
    printf("Bem-vindo ao CAIXA ELETRONICO FIAP!\n");
    printf("Saldo inicial: R$ %.2f\n\n", saldo);

    // Esse é o loop principal para manter o sistema ativo
    do
    {
        system("cls || clear"); // Limpar a tela
        exibirMenu();
        // Leitura da opção do usuário
        scanf("%d", &opcao);
        limparBuffer(); // Limpar para não dar erros

        switch (opcao)
        {

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
            printf("Opcao invalida! Escolha entre 0 e 3.\n");
            system("pausa || ler -p 'Pressione Enter...'");
        }

        if (opcao != 0)
        {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0);
    return 0;
}

// Função para exibir o menu principal -- Funciona igual arduíno? kkk
void exibirMenu()
{
    printf("\n");
    printf("============================\n");
    printf("  CAIXA ELETRONICO FIAP  \n");
    printf("============================\n");
    printf("\n1 - Consultar Saldo");
    printf("\n2 - Realizar Saque");
    printf("\n3 - Realizar Deposito");
    printf("\n0 - Sair\n");
    printf("============================\n");
    printf("Digite sua opcao: ");
}
// Função para consultar o saldo atual
void consultarSaldo(float saldo)
{
    printf("\n");
    printf("===================\n");
    printf(" SALDO ATUAL \n");
    printf("===================\n");
    printf("R$ %.2f\n", saldo);
    printf("===================\n");
}

// Função para realizar o saque
float realizarSaque(float saldoAtual)
{
    float valorSaque;
    printf("--------\n");
    printf("\n SAQUE\n");
    printf("--------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("Valor do saque: ");
    scanf("%f", &valorSaque);
    limparBuffer();

    // Validações de seguranca para verificar se o usuário não tente burlar o sistema com valores negativos ou exceder um máximo de 1000 reais
    if (valorSaque <= 0)
    {
        printf("\nO saque não foi realizado!\n");
        return saldoAtual;
    }
    if (valorSaque > 2000.00)
    {
        printf("Valor excede o limite de saque disponível no dia! Maximo de R$1.500,00\n");
        return saldoAtual;
    }
    if (valorSaque > saldoAtual)
    {
        printf("\nSaldo insuficiente para realizar o saque!\n");
        return saldoAtual;
    }
    // Saque autorizado -- Aqui Printa se o saque for 100% autorizado

    saldoAtual -= valorSaque;
    printf("Saque de R$ %.2f realizado com sucesso!\n", valorSaque);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);

    return saldoAtual;
}
float realizarDeposito(float saldoAtual)
{
    float valorDeposito;

    printf("-----------\n");
    printf("\n DEPOSITO\n");
    printf("-----------\n");
    printf("Saldo atual: R$ %.2f\n", saldoAtual);
    printf("\nDigite o valor do deposito: R$ ");
    scanf("%f", &valorDeposito);
    limparBuffer();

    // Validação do deposito --- Ou seja, Verifica se o depósito é válido ou não

    if (valorDeposito <= 0)
    {
        saldoAtual += valorDeposito;
        printf(" Valor de deposito invalido, por favor, tente novamente!\n");
        return saldoAtual;
    }
    if (valorDeposito > 67000.00)
    {
        printf("Valor excede o limite de deposito disponivel no dia! Maximo de R$67.000,00\n");
        return saldoAtual;
    }
    saldoAtual += valorDeposito;
    printf("Deposito de R$ %.2f realizado com sucesso!\n", valorDeposito);
    printf("Novo saldo: R$ %.2f\n", saldoAtual);

    return saldoAtual;
}

// Função para limpar o buffer do teclado, evitando erros de leitura
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Limpa o buffer
    }
}