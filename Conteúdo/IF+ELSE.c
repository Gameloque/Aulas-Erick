#include <stdio.h>

int main (){

    int presenca; // Presença deve estar de 0 a 100
    float nota_1, nota_2;
    
        printf(" SAIBA SE VOCE E ANIMAL, VOCE CONSEGUIU?\n ");
    printf("Digite sua primeira nota: ");
        scanf("%f", &nota_1);
    printf("\nDigite sua segunda nota: ");
        scanf("%f", &nota_2);
    
    printf("Digite a presenca do aluno (de 0 a 100): ");
        scanf("%d", &presenca);
    
    
    float media = (nota_1 + nota_2)  / 2;




    if(media>=9 && presenca <=75){
        printf("Aluno Excelente!");
         } else if(media>= 6 && presenca>= 75){
             printf("Aluno Aprovado!");
             } else if(media>= 6 && presenca < 75){
                printf("Aluno Reprovado por falta");
                    } else if(media < 6 && presenca >=  75){
                         printf("Aluno Reprovado por nota!");
     } else{
      printf("PARABENS, VOCE CONSEGUIU!");
    

}
return 0;
}