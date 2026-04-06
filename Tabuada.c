/*Aqui tem For + While + Do While*/
#include <stdio.h>

int main () {
    int numero;
    int limite = 11;
    //printf("TABUADA\n");
    //printf("Digite o número que meu fi quer saber: ");
    //scanf("%d", &numero);

    /* Estrutura For
    for(int i = 0; i <10; limite){
    //printf("%d", i);
}*/
    /*Estrutura WHILE*/
    /*printf(" WHILE\n");
    int i = 0;
    while(i < limite){
        //printf("%d", i);
        int resultado = numero * i;

        printf("%d x %d = %d\n", numero, i, resultado);
         i++;

    }*/
    /* Estrutura Do-While */
    /**/ 
    int i = 0;
    do {
        int resultado2 = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado2);
        i++;
    }while(i < limite);


return 0;
}
