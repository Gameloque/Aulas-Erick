#include <stdio.h>

int main(void){
    int opcao, presenca;
    float nota_1, nota_2, nota_3, media;

        printf("                   ------------ MENU ------------            \n");
        printf(" Digite 1 para saber sua media\n");
        printf(" Digite 2 para saber sua presenca\n");
        printf(" Digite 3 para saber se foi aprovado\n");
        printf(" Digite a opcao desejada: ");

        scanf("%d", &opcao);
        
        switch(opcao){
            
            case 1:
            printf("\n ------------ MEDIA ------------\n");
            printf(" Digite sua nota: ");
            scanf("%f", &nota_1);
            printf(" Digite sua segunda nota: ");
            scanf("%f", &nota_2);
            printf(" Digite sua terceira nota: ");
            scanf("%f", &nota_3);
            media = (nota_1 + nota_2 + nota_3)/3;
            printf("A sua media final e: %.2f", media);

            break; // Sai do Switch
            
                case 2:
                printf("\n ------------ PRESENCA ------------\n");
                printf(" Quanto foi sua presenca esse semestre? \n");
                scanf("%d", &presenca);
                if(presenca > 74){
                    printf(" Aluno Aprovado com %d %%", presenca);
                }else{
                    printf("Aluno Reprovado!");
                }

                break;

    default:
    printf("Desliga ai man");
        // break is optional
                }




return 0;

}
