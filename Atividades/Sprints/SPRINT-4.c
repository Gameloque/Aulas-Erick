#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_SESSOES 100
#define LARGURA 55
#define TARIFA_COMERCIAL 1.80
#define POTENCIA_CARREGADOR 7.0
#define MAX_HORAS_SIMULACAO 24

typedef struct {
    int id;
    char veiculo[30];

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

/* 1 se o vetor esta ordenado por id */
int ordenadoPorId = 1;


void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}


/* desenha uma linha com o caractere escolhido */
void linha(char c) {

    for (int i = 0; i < LARGURA; i++) {
        putchar(c);
    }

    putchar('\n');
}


/* titulo centralizado entre duas linhas */
void titulo(const char *texto) {

    int espacos = (LARGURA - (int) strlen(texto)) / 2;

    linha('=');
    printf("%*s%s\n", espacos, "", texto);
    linha('=');
}


/* titulo de cada tela */
void subtitulo(const char *texto) {

    printf("\n  %s\n", texto);
    linha('-');
}


float calcularTarifa(float hora) {

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


/* le a hora e o minuto do relogio do computador */
void lerRelogio(int *hora, int *minuto) {

    time_t agora = time(NULL);
    struct tm *relogio = localtime(&agora);

    *hora = relogio->tm_hour;
    *minuto = relogio->tm_min;
}


/* mostra um valor em reais com virgula: R$1,20 */
void mostrarReais(float valor) {

    int centavos = (int) (valor * 100 + 0.5);

    printf("R$%d,%02d", centavos / 100, centavos % 100);
}


/* igual ao mostrarReais, mas alinhado a direita (para tabelas) */
void mostrarReaisAlinhado(float valor, int largura) {

    char texto[20];
    int centavos = (int) (valor * 100 + 0.5);

    snprintf(texto, sizeof(texto), "R$%d,%02d", centavos / 100, centavos % 100);
    printf("%*s", largura, texto);
}


/* cabecalho do carregador: hora certa e tarifas */
void mostrarCabecalho() {

    int hora;
    int minuto;
    char rotulo[10];

    lerRelogio(&hora, &minuto);

    printf("\n");
    titulo("VisionWe Charger");

    printf("  %-16s%02d:%02d\n", "Hora certa", hora, minuto);

    printf("  %-16s", "Tarifa atual");
    mostrarReais(calcularTarifa(hora));
    printf(" /kWh\n");

    printf("\n  Tarifa dinamica por horario\n");

    printf("    %-14s", "00h as 06h");
    mostrarReais(calcularTarifa(0));
    printf("\n    %-14s", "07h as 17h");
    mostrarReais(calcularTarifa(12));
    printf("\n    %-14s", "18h as 22h");
    mostrarReais(calcularTarifa(20));
    printf("\n    %-14s", "23h");
    mostrarReais(calcularTarifa(23));
    printf("\n");

    printf("\n  Proximas horas\n");

    for (int i = 1; i <= 3; i++) {

        int h = (hora + i) % 24;

        snprintf(rotulo, sizeof(rotulo), "%02dh", h);

        printf("    %-14s", rotulo);
        mostrarReais(calcularTarifa(h));
        printf("\n");
    }

    linha('=');
}


/* le um horario no formato HH:MM (ou so a hora). Devolve 1 se for valido */
int lerHorario(int *hora, int *minuto) {

    char texto[20];

    if (scanf("%19s", texto) != 1) {
        limparBuffer();
        return 0;
    }
    limparBuffer();

    *minuto = 0;

    if (sscanf(texto, "%d:%d", hora, minuto) < 1) {
        return 0;
    }

    if (*hora < 0 || *hora > 23 || *minuto < 0 || *minuto > 59) {
        return 0;
    }

    return 1;
}


/* tabela de uma recarga: uma linha por hora do relogio, com a tarifa
   daquela hora. Devolve a energia e o custo totais */
void mostrarTabela(int hora, int minuto, int minutos,
                   float *energiaTotal, float *custoTotal) {

    int restante = minutos;
    int h = hora;
    int m = minuto;

    *energiaTotal = 0;
    *custoTotal = 0;

    printf(" Inicio | Duracao  |  Tarifa  |     Energia |    Custo\n");
    linha('-');

    while (restante > 0) {

        /* ate o fim da hora atual ou ate o fim da recarga */
        int parte = 60 - m;

        if (parte > restante) {
            parte = restante;
        }

        float duracao = parte / 60.0;
        float tarifa = calcularTarifa(h);
        float energia = POTENCIA_CARREGADOR * duracao;
        float custo = energia * tarifa;

        *energiaTotal = *energiaTotal + energia;
        *custoTotal = *custoTotal + custo;

        printf("  %02d:%02d | %5.2f h  | ", h, m, duracao);
        mostrarReaisAlinhado(tarifa, 8);
        printf(" | %7.2f kWh | ", energia);
        mostrarReaisAlinhado(custo, 8);
        printf("\n");

        restante = restante - parte;
        m = 0;
        h = (h + 1) % 24;
    }

    linha('-');
    printf("  %-14s %dh%02d\n", "Tempo total", minutos / 60, minutos % 60);
    printf("  %-14s %.2f kWh\n", "Energia total", *energiaTotal);
    printf("  %-14s ", "Custo total");
    mostrarReais(*custoTotal);
    printf("\n");
}


/* simula uma recarga: o usuario informa a hora em que esta e quantas horas quer */
void simularRecarga() {

    int hora;
    float horas;
    float energia;
    float custo;

    do {

        subtitulo("SIMULAR RECARGA");
        printf("  Que horas sao (0-23): ");

        if (scanf("%d", &hora) != 1) {
            hora = -1;
        }
        limparBuffer();

        if (hora < 0 || hora > 23) {
            printf("\nHorario invalido! Digite de 0 a 23.\n");
        }

    } while (hora < 0 || hora > 23);


    do {

        char texto[20];

        printf("\n  Quantas horas de recarga (ex: 2 ou 1,5): ");

        if (scanf("%19s", texto) != 1) {
            horas = -1;
        }
        else {
            /* aceita virgula no lugar do ponto */
            for (int i = 0; texto[i] != '\0'; i++) {
                if (texto[i] == ',') {
                    texto[i] = '.';
                }
            }

            if (sscanf(texto, "%f", &horas) != 1) {
                horas = -1;
            }
        }
        limparBuffer();

        if ((int) (horas * 60 + 0.5) < 1 || horas > MAX_HORAS_SIMULACAO) {
            printf("\nTempo invalido! Digite de 1 minuto ate %d horas.\n",
                   MAX_HORAS_SIMULACAO);
        }

    } while ((int) (horas * 60 + 0.5) < 1 || horas > MAX_HORAS_SIMULACAO);


    printf("\n  Simulacao de %.2f horas, comecando as %02dh\n", horas, hora);
    printf("  Carregador de %.0f kW. Nada e salvo na lista.\n\n",
           POTENCIA_CARREGADOR);

    mostrarTabela(hora, 0, (int) (horas * 60 + 0.5), &energia, &custo);
}


void mostrarSessao(Sessao s) {

    int minutos = (int) s.minutos_recarga;

    printf("  %-13s %d\n", "Sessao", s.id);
    printf("  %-13s %s\n", "Veiculo", s.veiculo);
    printf("  %-13s %.0f kW\n", "Carregador", s.potencia);
    printf("  %-13s %dh%02d (%d min)\n", "Tempo", minutos / 60, minutos % 60, minutos);
    printf("  %-13s %.2f kWh\n", "Energia", s.energia);

    printf("  %-13s ", "Tarifa media");
    mostrarReais(s.tarifa);
    printf(" /kWh\n");

    printf("  %-13s ", "Custo");
    mostrarReais(s.custo);
    printf("\n");

    if (s.ativa == 1) {
        printf("  %-13s Ativa\n", "Status");
    }
    else {
        printf("  %-13s Encerrada\n", "Status");
    }
}


void criarSessao() {

    if (totalSessoes >= MAX_SESSOES) {
        printf("\nLimite de sessoes atingido!\n");
        return;
    }

    Sessao nova;

    int confirmou = 0;

    nova.id = totalSessoes + 1;

    subtitulo("NOVA SESSAO");

    do {

        int horaInicio;
        int minutoInicio;
        int horaFinal;
        int minutoFinal;
        int minutos;
        int resposta;

        printf("\n  Nome do veiculo: ");

        scanf(" %29[^\n]", nova.veiculo);
        limparBuffer();


        /* a hora de inicio e a hora em que o veiculo foi conectado */
        lerRelogio(&horaInicio, &minutoInicio);

        printf("\n  Veiculo conectado as %02d:%02d\n\n", horaInicio, minutoInicio);


        do {

            printf("  Hora final da recarga (HH:MM): ");

            if (lerHorario(&horaFinal, &minutoFinal) == 0) {
                printf("\nERRO! Horario invalido.\n");
                printf("Digite no formato HH:MM, de 00:00 ate 23:59.\n\n");
                minutos = 0;
                continue;
            }

            /* se a hora final for menor, a recarga termina no dia seguinte */
            minutos = (horaFinal * 60 + minutoFinal) -
                      (horaInicio * 60 + minutoInicio);

            if (minutos < 0) {
                minutos = minutos + 24 * 60;
            }

            if (minutos < 1 || minutos > 480) {
                printf("\nERRO! Tempo invalido.\n");
                printf("A recarga deve durar entre 1 e 480 minutos.\n\n");
            }

        } while (minutos < 1 || minutos > 480);


        nova.hora_inicio = horaInicio + minutoInicio / 60.0;
        nova.hora_final = horaFinal + minutoFinal / 60.0;
        nova.minutos_recarga = minutos;
        nova.potencia = POTENCIA_CARREGADOR;


        subtitulo("CONFIRME OS DADOS");
        printf("  %-13s %s\n", "Veiculo", nova.veiculo);
        printf("  %-13s %.0f kW\n", "Carregador", nova.potencia);
        printf("  %-13s %02d:%02d\n", "Inicio", horaInicio, minutoInicio);
        printf("  %-13s %02d:%02d\n\n", "Fim", horaFinal, minutoFinal);

        mostrarTabela(horaInicio, minutoInicio, minutos,
                      &nova.energia, &nova.custo);

        nova.tarifa = nova.custo / nova.energia;


        do {

            printf("\n  1 - Confirmar e iniciar a recarga\n");
            printf("  2 - Corrigir (cadastrar o veiculo novamente)\n");
            printf("\n  Escolha: ");

            if (scanf("%d", &resposta) != 1) {
                resposta = 0;
            }
            limparBuffer();

            if (resposta != 1 && resposta != 2) {
                printf("\nOpcao invalida! Digite 1 ou 2.\n");
            }

        } while (resposta != 1 && resposta != 2);


        if (resposta == 1) {
            confirmou = 1;
        }
        else {
            printf("\nVamos cadastrar o veiculo novamente.\n");
        }

    } while (confirmou == 0);


    nova.ativa = 1;

    sessoes[totalSessoes] = nova;
    totalSessoes++;


    subtitulo("RECARGA INICIADA");
    mostrarSessao(nova);
}


void listarSessoes() {

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    subtitulo("SESSOES CADASTRADAS");

    for (int i = 0; i < totalSessoes; i++) {
        mostrarSessao(sessoes[i]);
        linha('-');
    }

    printf("  Total: %d sessao(oes)\n", totalSessoes);
}


/* devolve o campo usado na ordenacao */
float valorCriterio(Sessao s, int criterio) {

    if (criterio == 2) {
        return s.energia;
    }
    else if (criterio == 3) {
        return s.custo;
    }
    else if (criterio == 4) {
        return s.minutos_recarga;
    }
    else {
        return (float) s.id;
    }
}


/* bubble sort - crescente = 1 ou decrescente = 0 */
void bubbleSort(int criterio, int crescente) {

    for (int i = 0; i < totalSessoes - 1; i++) {

        int trocou = 0;

        for (int j = 0; j < totalSessoes - 1 - i; j++) {

            float a = valorCriterio(sessoes[j], criterio);
            float b = valorCriterio(sessoes[j + 1], criterio);

            int trocar;

            if (crescente == 1) {
                trocar = (a > b);
            }
            else {
                trocar = (a < b);
            }

            if (trocar) {
                Sessao temp = sessoes[j];
                sessoes[j] = sessoes[j + 1];
                sessoes[j + 1] = temp;

                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}


void ordenarSessoes() {

    int criterio;
    int ordem;

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    do {

        subtitulo("ORDENAR SESSOES");
        printf("  1 - Por ID\n");
        printf("  2 - Por energia consumida\n");
        printf("  3 - Por custo da sessao\n");
        printf("  4 - Por tempo de recarga\n");
        printf("\n  Ordenar por: ");

        if (scanf("%d", &criterio) != 1) {
            limparBuffer();
            criterio = 0;
        }

        if (criterio < 1 || criterio > 4) {
            printf("\nOpcao invalida! Digite de 1 a 4.\n");
        }

    } while (criterio < 1 || criterio > 4);


    do {

        printf("\n  1 - Crescente\n");
        printf("  2 - Decrescente\n");
        printf("\n  Ordem: ");

        if (scanf("%d", &ordem) != 1) {
            limparBuffer();
            ordem = 0;
        }

        if (ordem != 1 && ordem != 2) {
            printf("\nOrdem invalida! Digite 1 ou 2.\n");
        }

    } while (ordem != 1 && ordem != 2);


    bubbleSort(criterio, ordem == 1);

    if (criterio == 1 && ordem == 1) {
        ordenadoPorId = 1;
    }
    else {
        ordenadoPorId = 0;
    }

    printf("\nSessoes ordenadas!\n");

    listarSessoes();
}


/* busca linear - devolve a posicao ou -1 */
int buscaLinear(int id) {

    for (int i = 0; i < totalSessoes; i++) {

        if (sessoes[i].id == id) {
            return i;
        }
    }

    return -1;
}


/* busca binaria - o vetor precisa estar ordenado por id */
int buscaBinaria(int id) {

    int inicio = 0;
    int fim = totalSessoes - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if (sessoes[meio].id == id) {
            return meio;
        }
        else if (sessoes[meio].id < id) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}


void buscarSessao() {

    int id;
    int metodo;
    int pos;

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    subtitulo("BUSCAR SESSAO");
    printf("  1 - Busca linear\n");
    printf("  2 - Busca binaria\n");
    printf("\n  Metodo: ");

    if (scanf("%d", &metodo) != 1) {
        limparBuffer();
        printf("\nMetodo invalido.\n");
        return;
    }

    if (metodo != 1 && metodo != 2) {
        printf("\nMetodo invalido.\n");
        return;
    }

    printf("  Digite o ID da sessao: ");

    if (scanf("%d", &id) != 1) {
        limparBuffer();
        printf("\nID invalido.\n");
        return;
    }


    if (metodo == 1) {
        pos = buscaLinear(id);
    }
    else {

        /* a busca binaria so funciona com o vetor ordenado por id */
        if (ordenadoPorId == 0) {
            printf("\nVetor fora de ordem, ordenando por ID...\n");

            bubbleSort(1, 1);
            ordenadoPorId = 1;
        }

        pos = buscaBinaria(id);
    }


    if (pos == -1) {
        printf("\nSessao nao encontrada.\n");
    }
    else {
        subtitulo("SESSAO ENCONTRADA");
        mostrarSessao(sessoes[pos]);
        linha('-');
    }
}


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

        totalEnergia = totalEnergia + sessoes[i].energia;
        totalFaturamento = totalFaturamento + sessoes[i].custo;

        if (sessoes[i].energia > maiorEnergia) {
            maiorEnergia = sessoes[i].energia;
        }

        if (sessoes[i].energia < menorEnergia) {
            menorEnergia = sessoes[i].energia;
        }
    }

    subtitulo("ESTATISTICAS DA ESTACAO");

    printf("  %-20s %d\n", "Sessoes realizadas", totalSessoes);
    printf("  %-20s %.2f kWh\n", "Energia fornecida", totalEnergia);

    printf("  %-20s ", "Faturamento");
    mostrarReais(totalFaturamento);
    printf("\n");

    printf("  %-20s ", "Ticket medio");
    mostrarReais(totalFaturamento / totalSessoes);
    printf("\n");

    printf("  %-20s %.2f kWh\n", "Maior consumo", maiorEnergia);
    printf("  %-20s %.2f kWh\n", "Menor consumo", menorEnergia);
    linha('-');
}


void encerrarSessao() {

    int id;
    int pos;

    if (totalSessoes == 0) {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    printf("\n  Digite o ID da sessao: ");

    if (scanf("%d", &id) != 1) {
        limparBuffer();
        printf("\nID invalido.\n");
        return;
    }

    pos = buscaLinear(id);

    if (pos == -1) {
        printf("\nSessao nao encontrada.\n");
        return;
    }

    sessoes[pos].ativa = 0;

    printf("\nSessao encerrada!\n");
}


int main() {

    int opcao;

    do {

        mostrarCabecalho();

        printf("\n  1 - Nova sessao de recarga\n");
        printf("  2 - Listar sessoes\n");
        printf("  3 - Buscar sessao\n");
        printf("  4 - Ordenar sessoes\n");
        printf("  5 - Estatisticas\n");
        printf("  6 - Simular uma recarga\n");
        printf("  7 - Encerrar\n");
        printf("  8 - Finalizar uma sessao\n");

        printf("\n  Escolha: ");

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
                ordenarSessoes();
                break;

            case 5:
                mostrarEstatisticas();
                break;

            case 6:
                simularRecarga();
                break;

            case 7:
                printf("\nEncerrando sistema...\n");
                break;

            case 8:
                encerrarSessao();
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}
