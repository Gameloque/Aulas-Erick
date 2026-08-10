#include <stdio.h>

int maiorElemento(int v[], int n){
    int maior = v[0];

    for (int i = 1; i < n; i++){
        if (v[i] > maior){
            maior = v[i];
        }
    }
    return maior;
}
    int main(void){
        int vetor[] = {10,25,8,40,32,70,15};
        int n = sizeof(vetor) / sizeof(vetor[0]);

        int maior = maiorElemento(vetor, n);

        printf("Maior Elemento: %d\n", maior);

        return 0;
    }
