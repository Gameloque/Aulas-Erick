#include <stdio.h>

int somar(int a, int b); // 1. Protótipo
    int main( ){
        int resultado = somar(10, 5); // 2. Chamada
        printf("Soma: %d", resultado);
        return 0;
    }
        int somar (int a, int b){
            return a + b;


}