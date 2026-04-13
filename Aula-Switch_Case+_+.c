#include <stdio.h>

void menu(){
    printf("                   ------------ MENU ------------            \n");
        printf(" Digite 1 para saber sua media\n");
        printf(" Digite 2 para saber sua presenca\n");
        printf(" Digite 3 para saber se foi aprovado\n");
        printf(" Digite a opcao desejada: ");

}

float media_arit(float nota_1,float nota_2,float nota_3){
    
    return (nota_1 + nota_2 + nota_3)/3;
}

int main(){
    int opcao, presenca;
    float nota_1, nota_2, nota_3, media_ait;
        
    menu();
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
            //media = (nota_1 + nota_2 + nota_3)/3; // substituir essa equação
            media_arit = media_arit(nota_1, nota_2, nota_3);
            printf("A sua media final e: %.2f", media_arit);

            break; // Sai do Switch
            
                case 2:
                printf("\n ------------ PRESENCA ------------\n");
                printf(" Quanto foi sua presenca esse semestre? \n");
                scanf("%d", &presenca);
                if(presenca > 74 && presenca < 101){
                    printf(" ALUNO APROVADO COM %d %%", presenca);
                }else if(presenca > 100 || presenca < 0){
                    printf(" QUE ISSO CHEFE?");
                }else{
                    printf(" ALUNO REPROVADO!");
                }

                break;

    default:
    printf(" QUER NADA COM NADA ");
        // break is optional
                }




return 0;

}
