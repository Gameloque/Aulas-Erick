#include <stdio.h>
#include <stdlib.h>
// Criando o Nó - Recursão
typedef struct Node
{
    int dado;             // A informação
    struct Node *proximo; // A linkagem
} Node;

void inserirInicio(Node **head, int valor)
{
    Node *novo = malloc(sizeof(struct Node));
    novo->dado = valor;
    novo->proximo = *head;
    *head = novo;
}
// Função imprimirLista
void imprimirLista(Node *head)
{
    Node *atual = head;

    while (atual != NULL)
    {
        printf("%d -> ", atual->dado);
        atual = atual->proximo; // Pulo
    }
    printf("NULL\n");
}

int main()
{
    // Criando um novo nó dinamicamente
    struct Node *novoNode1;
    struct Node *novoNode2;
    struct Node *novoNode3;
    // Aloca espaço para 1 nó
    novoNode1 = (struct Node *)malloc(sizeof(struct Node));
    novoNode2 = (struct Node *)malloc(sizeof(struct Node));
    novoNode3 = (struct Node *)malloc(sizeof(struct Node));

    if (novoNode1 == NULL || novoNode2 == NULL || novoNode3 == NULL)
    {
        printf(" Erro: Memória Insuficiente!\n");
        exit(1);
    }
    inserirInicio(&novoNode1, 5);
    inserirInicio(&novoNode2, 15);
    inserirInicio(&novoNode3, 25);
    imprimirLista(novoNode1);
    printf("%d", novoNode1->dado); // Ponteiro mostrando o dado armazenado no "dado"
    // Atribuindo Valores
    novoNode1->dado = 10; // Ponteiro atribuindo um novo dado no "dado"
    novoNode1->proximo = NULL;
    printf("\n%d", novoNode1->dado); // Ponteiro mostrando o novo dado armazenado no "dado"
    return 0;
}