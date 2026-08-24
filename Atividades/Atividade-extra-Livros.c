#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct
{
    char nome_livro[40];
    char autor[30];
    uint id_livro;

} Livros;

void ListaLivros(Livros *livro, int tamanho)
{
    printf("O livro %s do autor %s com id %d\n", livro->nome_livro, livro->autor, livro->id_livro);
}
int main()
{
    Livros livro[100];
    Livros livro1 = {"Dom Casmurro", "Machado de Assis", 00 + 1};
    Livros livro2 = {"Noites Brancas", "Fiódor Dostoiévski", 00 + 2};
    Livros livro3 = {"Retórica", "Aristóteles", 00 + 3};

    ListaLivros(&livro1, 1);
    ListaLivros(&livro2, 2);
    ListaLivros(&livro3, 3);
    return 0;
}
