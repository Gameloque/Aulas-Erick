#include <stdio.h>

void imprimirTriangulo(int n) {
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j++){
            print("*");
        }
    print("\n");
    }
}
    int main(void){
        imprimirTriangulo(5);
        return 0;
    }
