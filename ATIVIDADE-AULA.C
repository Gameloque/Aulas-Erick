#include <stdio.h>

int main () {
                    // Usuario precisa digitar um valor
        int numero;
    printf("Digite um valor ae man para que ele seja somado ou digite o caracter s para sair: ");
scanf("%d", &numero);

                    //Lógica do Loop e da soma
char sair;
    while(sair != "s" || sair != 'S'){
        printf('Digite mais um numero para ser somado ou digite s para sair');
scanf("%c", &sair);
    }                


    return 0;
}