#include <stdio.h>

#define MAX_SESSOES 100
#define TARIFA_PARTICULAR 0.75
#define TARIFA_COMERCIAL 1.80

typedef struct {
    int id;
    char veiculo[30];

    int tipo_usuario;
    int tipo_carregador;

    float hora_inicio;
    float hora_final;
    float minutos_recarga;

    float potencia;
    float energia;
    float tarifa;
    float custo;

    int ativa;
} Sessao;

Sessao sessoes[MAX_SESSOES];
int totalSessoes = 0;


/* Limpa o que ficou no teclado */
void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}


/* Calcula a tarifa */
float calcularTarifa(int tipo_usuario, float hora) {

    if (tipo_usuario == 1) {
        return TARIFA_PARTICULAR;
    }

    if (hora >= 18 && hora <= 22) {
        return 1.20;
    }
    else if (hora >= 0 && hora <= 6) {
        return 0.60;
    }
    else {
        return TARIFA_COMERCIAL;
    }
}


/* Define a potencia do carregador */
float calcularPotencia(int tipo_carregador) {

    if (tipo_carregador == 1) {
        return 11.0;
    }
    else if (tipo_carregador == 2) {
        return 22.0;
    }
    else {
        return 7.0;
    }
}


/* Cria uma nova sessao */
void criarSessao() {

    if (totalSessoes >= MAX_SESSOES) {
        printf("\nLimite de sessoes atingido!\n");
        return;
    }

    Sessao nova;

    nova.id = totalSessoes + 1;

    printf("\n===== NOVA SESSAO =====\n");


    /* Nome do veiculo */
    printf("Nome do veiculo: ");

    scanf("%29s", nova.veiculo);
    limparBuffer();


    /* Tipo de usuario */
    do {

        printf("\n1 - Particular\n");
        printf("2 - Comercial\n");
        printf("Tipo de usuario: ");

        if (scanf("%d", &nova.tipo_usuario) != 1) {
            limparBuffer();
            nova.tipo_usuario = 0;
        }

        if (nova.tipo_usuario != 1 &&
            nova.tipo_usuario != 2) {

            printf("\nTipo de usuario invalido!\n");
            printf("Digite 1 para Particular ou 2 para Comercial.\n");
        }

    } while (nova.tipo_usuario != 1 &&
             nova.tipo_usuario != 2);


    /* Tipo de carregador */
    do {

        printf("\n1 - Carregador 11 kW\n");
        printf("2 - Carregador 22 kW\n");
        printf("3 - Carregador 7 kW\n");
        printf("Tipo de carregador: ");

        if (scanf("%d", &nova.tipo_carregador) != 1) {
            limparBuffer();
            nova.tipo_carregador = 0;
        }

        if (nova.tipo_carregador < 1 ||
            nova.tipo_carregador > 3) {

            printf("\nTipo de carregador invalido!\n");
            printf("Digite 1, 2 ou 3.\n");
        }

    } while (nova.tipo_carregador < 1 ||
             nova.tipo_carregador > 3);


    /* Calcula potencia */
    nova.potencia =
        calcularPotencia(nova.tipo_carregador);


    /* Horarios */
    do {

        printf("\nHora inicio (0-23): ");

        if (scanf("%f", &nova.hora_inicio) != 1) {
            limparBuffer();
            nova.hora_inicio = -1;
        }

        printf("Hora final (0-23): ");

        if (scanf("%f", &nova.hora_final) != 1) {
            limparBuffer();
            nova.hora_final = -1;
        }


        /* Verifica horario */
        if (nova.hora_inicio < 0 ||
            nova.hora_inicio > 23 ||
            nova.hora_final < 0 ||
            nova.hora_final > 23) {

            printf("\nERRO! Horario invalido.\n");
            printf("As horas devem estar entre 0 e 23.\n");

            nova.minutos_recarga = 0;
            continue;
        }


        /* Calcula o tempo de recarga */
        nova.minutos_recarga =
            (nova.hora_final * 60) -
            (nova.hora_inicio * 60);


        /* Verifica tempo */
        if (nova.minutos_recarga < 1 ||
            nova.minutos_recarga > 480) {

            printf("\nERRO! Tempo invalido.\n");
            printf("A recarga deve durar entre 1 e 480 minutos.\n");
        }

    } while (nova.hora_inicio < 0 ||
             nova.hora_inicio > 23 ||
             nova.hora_final < 0 ||
             nova.hora_final > 23 ||
             nova.minutos_recarga < 1 ||
             nova.minutos_recarga > 480);


    /* Calcula energia */
    nova.energia =
        nova.potencia *
        (nova.minutos_recarga / 60);


    /* Calcula tarifa */
    nova.tarifa =
        calcularTarifa(
            nova.tipo_usuario,
            nova.hora_inicio
        );


    /* Calcula custo */
    nova.custo =
        nova.energia *
        nova.tarifa;


    nova.ativa = 1;


    /* Guarda a sessao */
    sessoes[totalSessoes] = nova;
    totalSessoes++;


    printf("\n======= SESSAO CRIADA =======\n");

    printf(" || ID: %d\n", nova.id);
    printf(" || Veiculo: %s\n", nova.veiculo);
    printf(" || Potencia: %.2f kW\n", nova.potencia);
    printf(" || Tempo: %.2f minutos\n", nova.minutos_recarga);
    printf(" || Energia: %.2f kWh\n", nova.energia);
    printf(" || Tarifa: R$ %.2f\n", nova.tarifa);
    printf(" || Custo: R$ %.2f\n", nova.custo);
}


/* Lista as sessoes */
void listarSessoes() {

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    printf("\n======= LISTA DE SESSOES =======\n");

    for (int i = 0; i < totalSessoes; i++) {

        printf(" || ID: %d\n", sessoes[i].id);
        printf(" || Veiculo: %s\n", sessoes[i].veiculo);
        printf(" || Potencia: %.2f kW\n", sessoes[i].potencia);
        printf(" || Energia: %.2f kWh\n", sessoes[i].energia);
        printf(" || Tarifa: R$ %.2f\n", sessoes[i].tarifa);
        printf(" || Custo: R$ %.2f\n", sessoes[i].custo);

        if (sessoes[i].ativa == 1) {
            printf("\nStatus: Ativa\n");
        }
        else {
            printf("\nStatus: Encerrada\n");
        }
    }
}


/* Busca uma sessao pelo ID */
void buscarSessao() {

    int id;

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    printf("\nDigite o ID da sessao: ");

    if (scanf("%d", &id) != 1) {
        limparBuffer();
        printf("\nID invalido.\n");
        return;
    }

    for (int i = 0; i < totalSessoes; i++) {

        if (sessoes[i].id == id) {

            printf("\n===== SESSAO ENCONTRADA =====\n");

            printf("ID: %d\n", sessoes[i].id);
            printf("Veiculo: %s\n", sessoes[i].veiculo);
            printf("Potencia: %.2f kW\n", sessoes[i].potencia);
            printf("Energia: %.2f kWh\n", sessoes[i].energia);
            printf("Tarifa: R$ %.2f\n", sessoes[i].tarifa);
            printf("Custo: R$ %.2f\n", sessoes[i].custo);

            if (sessoes[i].ativa == 1) {
                printf("Status: Ativa\n");
            }
            else {
                printf("Status: Encerrada\n");
            }

            return;
        }
    }

    printf("\nSessao nao encontrada.\n");
}



/* Mostra as estatisticas */
void mostrarEstatisticas() {

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }


    float totalEnergia = 0;
    float totalFaturamento = 0;

    float maiorEnergia = sessoes[0].energia;
    float menorEnergia = sessoes[0].energia;


    for (int i = 0; i < totalSessoes; i++) {

        totalEnergia =
            totalEnergia + sessoes[i].energia;

        totalFaturamento =
            totalFaturamento + sessoes[i].custo;


        if (sessoes[i].energia > maiorEnergia) {
            maiorEnergia = sessoes[i].energia;
        }


        if (sessoes[i].energia < menorEnergia) {
            menorEnergia = sessoes[i].energia;
        }
    }


    printf("\n===== ESTATISTICAS =====\n");

    printf("Total de sessoes: %d\n",
           totalSessoes);

    printf("Total de energia: %.2f kWh\n",
           totalEnergia);

    printf("Faturamento total: R$ %.2f\n",
           totalFaturamento);

    printf("Media por sessao: R$ %.2f\n",
           totalFaturamento / totalSessoes);

    printf("Maior consumo: %.2f kWh\n",
           maiorEnergia);

    printf("Menor consumo: %.2f kWh\n",
           menorEnergia);
}


/* Encerra uma sessao */
void encerrarSessao() {

    int id;


    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }


    printf("\nDigite o ID da sessao: ");

    if (scanf("%d", &id) != 1) {
        limparBuffer();
        printf("\nID invalido.\n");
        return;
    }


    for (int i = 0; i < totalSessoes; i++) {

        if (sessoes[i].id == id) {

            sessoes[i].ativa = 0;

            printf("\nSessao encerrada!\n");

            return;
        }
    }


    printf("\nSessao nao encontrada.\n");
}


/* Programa principal */
int main() {

    int opcao;


    do {

        printf("\n====================================\n");
        printf(" ||      SIMULADOR DE RECARGA    ||\n");
        printf("====================================\n");

        printf("1 - Criar sessao\n");
        printf("2 - Listar sessoes\n");
        printf("3 - Buscar sessao\n");
        printf("4 - Mostrar estatisticas\n");
        printf("5 - Encerrar sessao\n");
        printf("0 - Sair\n");


        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {

            limparBuffer();
            opcao = -1;

            printf("\nOpcao invalida!\n");

            continue;
        }


        switch (opcao) {

            case 1:
                criarSessao();
                break;

            case 2:
                listarSessoes();
                break;

            case 3:
                buscarSessao();
                break;

            case 4:
                mostrarEstatisticas();
                break;

            case 5:
                encerrarSessao();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);


    return 0;
} 
