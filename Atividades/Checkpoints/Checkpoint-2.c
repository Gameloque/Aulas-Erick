#include <stdio.h>

int main()
{
    char nome[50];
    char continuar;
    int idade;
    int rm;
    float nota1, nota2, presenca, media;
    int situacao;

    do
    {
        printf("BEM VINDO AO SISTEMA DE NOTAS FIAP...\n");
        printf("VAMOS COMECAR\n");
        printf("PAINEL DE NOTAS\n");

        printf("Digite seu nome: ");
        scanf("%s", nome);

        printf("Digite sua idade: ");
        scanf("%d", &idade);

        printf("Digite seu RM: ");
        scanf("%d", &rm);

        do
        {
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);

            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);

            printf("Digite a sua frequencia (0 a 100): ");
            scanf("%f", &presenca);

            if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || presenca < 0 || presenca > 100)
            {
                printf("Valores invalidos! Digite notas de 0 a 10 e frequencia de 0 a 100.\n");
            }
        } while (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || presenca < 0 || presenca > 100);

        printf("-------------------------\n");

        media = (nota1 + nota2) / 2;

        printf(" Nome: %s\n Idade: %d\n RM: %d\n Media geral: %.2f\n", nome, idade, rm, media);
        printf("-------------------------\n");

        if (media >= 6 && presenca > 66)
        {
            situacao = 1;
        }
        else
        {
            situacao = 2;
        }

        switch (situacao)
        {
        case 1:
            printf("Aluno aprovado!\n");
            break;

        case 2:
            printf("Aluno reprovado!\n");
            break;

        default:
            printf("Erro na verificacao\n");
        }

        printf("\nDeseja cadastrar outro aluno? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Sistema encerrado.\n");

    return 0;
}