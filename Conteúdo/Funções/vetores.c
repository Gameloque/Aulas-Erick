#include <stdio.h>

int main(){
    int quantidade_notas;
    printf("Digite a quantidade de notas: ");
    scanf("%d", &quantidade_notas);
    float notas[quantidade_notas]; // De 0 a 1 (indice)
    float soma;
    
    for(int i = 0; i < quantidade_notas; i++){
        printf("Digite a sua nota %d: ", i+1);
        scanf("%f", &notas[i]);
        soma += notas[i];
        
    }
    printf("A media do aluno e: %.2f\n", soma/quantidade_notas);
  
    char s1[10] = "Aula";
    char s2[] = "FIAP";

return 0;
}
