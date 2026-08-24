#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

typedef struct
{
    char nome_livro[40];
    char autor[30];
    uint id_livro;
    bool Emprestado;

} Livros;

void Emprestimo(Livros *livro, bool Emprestado)
{
    livro->Emprestado = Emprestado;
    if (livro->Emprestado == true)
    {
        printf("O livro %s do autor %s foi emprestado com sucesso!\n",
               livro->nome_livro,
               livro->autor);
    }
    else
    {
        printf("O livro %s do autor %s foi devolvido com sucesso!\n",
               livro->nome_livro,
               livro->autor);
    }
}

void ListaLivros(Livros *livro, int tamanho)
{
    printf("O livro %s - Autor %s - ID 0%d - Emprestado? %s\n",
           livro->nome_livro,
           livro->autor,
           livro->id_livro,
           livro->Emprestado ? "Sim" : "Não"

    );
}
int main()
{
    Livros livro[100];
    Livros livro1 = {"Dom Casmurro", "Machado de Assis", 00 + 1, false};
    Livros livro2 = {"Noites Brancas", "Fiódor Dostoiévski", 00 + 2, false};
    Livros livro3 = {"Retórica", "Aristóteles", 00 + 3, false};

    ListaLivros(&livro1, 1);
    ListaLivros(&livro2, 2);
    ListaLivros(&livro3, 3);
    return 0;
}
