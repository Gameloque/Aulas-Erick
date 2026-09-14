#include <stdio.h> 

int main() {
    float nota1, nota2, nota3, presenca;
    int opcao;
    printf(" BEM VINDO AO SISTEMA DE NOTAS FIAP... \n");
    printf(" VAMOS COMECAR...   \n");
    printf("     PAINEL DE NOTAS MANEIRAS   \n");
    printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
        scanf("%f", &nota3);
    printf("Digite a sua frequencia (0 a 100): ");
        scanf("%f", &presenca);
    printf("    -------------------------     \n");
    printf("Digite 1 para saber sua media final e se foi aprovado: ");
    printf("\nDigite 2 para mais informacoes: ");
    printf("\nDigite 0 para sair: ");
        scanf("%d", &opcao);


    switch(opcao){

        case 1:
        float media = (nota1 + nota2 + nota3) / 3;
            printf("Sua media é: %.2f", media);

        if(media>=9 && presenca <=75){
        printf("\nAluno Excelente!");
         } else if(media>= 6 && presenca>= 75){
             printf("\nAluno Aprovado!");
             } else if(media>= 6 && presenca < 75){
                printf("\nAluno Reprovado por falta");
                    } else if(media < 6 && presenca >=  75){
                         printf("\nAluno Reprovado por nota!");
        } else{
        printf("PARABENS, VOCE CONSEGUIU!");
            break;
            
    default:
    printf(" QUER NADA COM NADA ");
    return 0;
}
}
}
