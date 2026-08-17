// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct
// {
//     int rm;
//     char nome[32];
//     float media;
// } Aluno;

// void imprimir(const Aluno *v, int n, const char *titulo)
// {
//     printf("\n%s\n", titulo);
//     for (int i = 0; i < n; i++)
//     {
//         printf("RM:%d | Nome:%-10s | Média: %.2f\n", v[i].rm, v[i].nome,
//                v[i].media);
//     }
// }

// void bubble_media_desc(Aluno *v, int n)
// {
//     int trocou;
//     int mov;
//     do
//     {
//         trocou = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             if (v[i].media <
//                 v[i + 1].media)
//             { // troca só quando for estritamente menor
//                 Aluno tmp = v[i];
//                 v[i] = v[i + 1];
//                 v[i + 1] = tmp;
//                 trocou = 1;
//                 mov++;
//             }
//         }
//         n--; // último elemento já está na posição correta
//         mov++;
//     } while (trocou);
//     printf("Bubble Sort: Foram feitas %d movimentações.", mov);
// }

// void insertion_media_desc(Aluno *v, int n)
// {
//     int mov;
//     for (int i = 1; i < n; i++)
//     {
//         Aluno chave = v[i];
//         int j = i - 1;
//         while (j >= 0 && v[j].media < chave.media)
//         {
//             v[j + 1] = v[j];
//             j--;
//             mov++;
//         }
//         v[j + 1] = chave;
//         mov++;
//     }
//     printf("Insertion Sort: Foram feitas %d movimentações.", mov);
// }

// void insertion_nome_asc(Aluno *v, int n)
// {
//     int mov;
//     for (int i = 1; i < n; i++)
//     {
//         Aluno chave = v[i];
//         int j = i - 1;
//         while (j >= 0 && strcmp(v[j].nome, chave.nome) > 0)
//         {
//             v[j + 1] = v[j];
//             j--;
//             mov++;
//         }
//         v[j + 1] = chave;
//         mov++;
//     }
//     printf("Insertion Sort: Foram feitas %d movimentações.", mov);
// }

// // Função de comparação para qsort
// int cmp_rm_asc(const void *a, const void *b)
// {
//     const Aluno *x = (const Aluno *)a;
//     const Aluno *y = (const Aluno *)b;
//     return (x->rm > y->rm) - (x->rm < y->rm); // evita overflow de subtração
// }

// void selection_media_desc(Aluno *v, int n)
// {
//     int mov;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int max = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (v[j].media > v[max].media)
//             {
//                 max = j;
//                 mov++;
//             }
//             mov++;
//         }
//         if (max != i)
//         {
//             Aluno tmp = v[i];
//             v[i] = v[max];
//             v[max] = tmp;
//             mov++;
//         }
//     }
//     printf("Selection Sort: Foram feitas %d movimentações.", mov);
// }

// int busca_binaria_rm(const Aluno *v, int n, int rm)
// {
//     int l = 0, r = n - 1;
//     while (l <= r)
//     {
//         int m = l + (r - l) / 2;
//         if (v[m].rm == rm)
//             return m;
//         if (v[m].rm < rm)
//             l = m + 1;
//         else
//             r = m - 1;
//     }
//     return -1; // não encontrado
// }

// int main(void)
// {
//     Aluno turma[] = {
//         {321, "Ana", 8.5f},
//         {215, "Bruno", 6.7f},
//         {405, "Clara", 9.2f},
//         {198, "Diego", 6.7f}, // mesma média de Bruno (para ver estabilidade)
//         {377, "Eva", 10.0f},
//         {142, "Lia", 7.3f},
//         {450, "Erick", 5.2f}};
//     int n = (int)(sizeof turma / sizeof turma[0]);

//     // Cópia da turma para cada algoritmo de ordenação
//     Aluno bubble_turma[n];
//     Aluno insertion_turma[n];
//     Aluno selection_turma[n];

//     memcpy(bubble_turma, turma, sizeof turma);
//     memcpy(insertion_turma, turma, sizeof turma);
//     memcpy(selection_turma, turma, sizeof turma);

//     imprimir(turma, n, "Estado inicial");

//     bubble_media_desc(bubble_turma, n);
//     imprimir(bubble_turma, n, "Ordenado por média (decrescente) – Bubble (estável)");

//     insertion_media_desc(insertion_turma, n);
//     imprimir(insertion_turma, n, "Ordenado por média (decrescente) – Insertion (estável)");

//     // insertion_nome_asc(turma, n);
//     // imprimir(turma, n, "Ordenado por nome (crescente) – Insertion (estável)");

//     // selection_media_desc(turma, n);
//     // imprimir(turma, n, "Ordenado por média (decrescente) – Selection (estável)");

//     // qsort(turma, n, sizeof(Aluno), cmp_rm_asc);
//     // imprimir(turma, n, "Ordenado por RM (crescente) – qsort");

//     // int alvo = 198;
//     // int idx = busca_binaria_rm(turma, n, alvo);
//     // printf("\nBusca binária por RM=%d → %s (índice %d)\n", alvo,
//     //         (idx >= 0 ? turma[idx].nome : "não encontrado"), idx);

//     return 0;
// }