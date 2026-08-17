#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct
{
    char rua[40];
    char bairro[20];
    uint numero;
} Endereco;

typedef struct
{
    char nome[20];
    int rm;
    char email[20];
    Endereco end;
    float media;
    bool aprovado; // booleano
} Aluno;

int main()
{
    Aluno aluno[100]; // declaracao da array para a struct Aluno
    Aluno aluno_1;    // declaracao independente
    // Completar dados do aluno indice 0
    strcpy(aluno[0].nome, "Joao Silva");
    aluno[0].rm = 123456;
    strcpy(aluno[0].email, "joao.silva@gmail.com");
    strcpy(aluno[0].end.rua, "Rua josefina");
    strcpy(aluno[0].end.bairro, "Cambuci");
    aluno[0].end.numero = 80;

    printf("Confirme seu endereco: %s, %d, %s\n", aluno[0].end.rua, aluno[0].end.numero, aluno[0].end.bairro);
    aluno[0].rm = 123456;
    strcpy(aluno[0].nome, "Erick Yamamoto");
    printf("O nome do aluno(a) --> %s\n", aluno[0].nome);
    printf("O rm do aluno(a) --> %d\n", aluno[0].rm);
    float nota1 = 6.0;
    float nota2 = 7.3;
    float nota3 = 2.4;
    aluno[0].media = (nota1 + nota2 + nota3) / 3;
    printf("Sua média é de %.2f\n", aluno[0].media);
    if (aluno[0].media >= 7)
    {
        printf("Aluno(a) Aprovado(a)!");
    }
    else
    {
        printf("Aluno(a) Reprovado(a)!");
    }
    // Fazer um sistema de registro de alunos
    // printf("O aluno esta %c", aluno_1.aprovado);
}
