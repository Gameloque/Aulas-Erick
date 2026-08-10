#include <stdio.h>

int somaMatriz(int matriz[][3], int n){     
    int soma = 0;                           // O (1)

    for (int i = 0; i < n; i++){            // O (n + 3)
        for(int j = 0; j < n; j++) {
            soma += matriz[i][j];           // O (n + 4)
        }           
    }
    return soma;                            // O (1)
    //TOTAL = n² + 7n + 14
}
    int main(void){
        int matriz[3][3] = {
            {1, 2, 3},
            {3, 5, 6},
            {7, 8, 9}
        };
        int resultado = somaMatriz(matriz, 3);

        printf("Soma= %d\n", resultado);

        return 0;
    // TOTAL n² + 7n + 25
    }
