#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct
{
    char nome[40];
    uint preco;
    float desconto;

} Produtos;

void AplicacaoDesc(Produtos *p, float desconto)
{
    p->preco = p->preco - (p->preco * desconto / 100);
    printf("O produto %s com preco de R$%d,00 recebeu um desconto de %.2f%%\n", p->nome, p->preco, desconto);
    printf("O valor final do produto %s com desconto de %.2f%% é de R$%.2f\n", p->nome, desconto, p->preco - (p->preco * (desconto / 100)));
}

void ListaProd(Produtos *prod, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n || Produto: %s || Preço: R$%.2f || Desconto: %.2f%% || ", prod[i].nome, prod[i].preco, prod[i].desconto);
    }
}
int main()
{

    Produtos prod[10];
    strcpy(prod[0].nome, "Leite");
    prod[0].preco = 9;
    prod[0].desconto = 10.0;
    strcpy(prod[1].nome, "Arroz");
    prod[1].preco = 21;
    prod[1].desconto = 15.0;

    AplicacaoDesc(&prod[0], 10.0);
    AplicacaoDesc(&prod[1], 10.0);
    printf(" ||======================================================||");
    ListaProd(prod, 2);
    printf("\n ||======================================================||");

    return 0;
}
