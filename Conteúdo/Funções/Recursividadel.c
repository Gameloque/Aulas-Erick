#include <stdio.h>
#include <string.h>

// Função Recursiva de contagem
void contagem(int n)
{
    // Caso base
    if (n == 0) {printf("FIM\n"); return;}

        // Caso recursivo
        printf("%d\n", n);
        contagem(n - 1);
    
}

// Função Recursiva de Soma
int somatoria(int n)
{
    // Caso Base
    if (n == 0) {printf("FIM\n"); return 0;}
    // Caso recursivo
    return n + somatoria(n-1);
}
// Função Recursiva de Potência
long long potencia(int base, int exp)
{
    // Caso Base
    if (exp == 0) {return 1;}
    // Caso recursivo
    return base * potencia(base, exp - 1);
}
// Função Recursiva de Fatorial
int fatorial(int n)
{
    // Caso Base
    if (n == 0) {return 1;}
    // Caso recursivo
    return n * fatorial(n - 1);
}
// Função Recursiva de Soma de Vetor
int somaVetor(int v[], int n)
{
    // Caso Base
    if (n == 0) {return 0;}
    // Caso recursivo
    return v[n - 1] + somaVetor(v, n - 1);
}
// Maior elemento do Vetor
int maiorElemento(int v[], int n)
{
    // Caso Base
    if (n == 1) {return v[0];}
    // Caso recursivo
    int anterior = maiorElemento(v, n - 1);

    if (v[n - 1] > anterior) {return v[n - 1];}
    else {return anterior;}
    
}
// Inverter String
void inverterString(char s[], int inicio, int fim)
{
    // Caso Base
    if (inicio >= fim) {return;}
    // Caso recursivo
    char temp = s[inicio];
    s[inicio] = s[fim];
    s[fim] = temp;
    inverterString(s, inicio + 1, fim - 1);
}
// Fazer Busca Binária, Palindromo, Fibonacci(Recursivo e Iterativo)
int main()
{
    contagem(10);
    printf("O resultado da somatoria e: %d\n", somatoria(5));
    printf("O resultado da potencia e: %lld\n", potencia(2, 5));
    printf("O resultado do fatorial e: %d\n", fatorial(5));
    int v[] = {10, 20, 30, 40, 50};
    int n = sizeof(v) / sizeof(v[0]);
    printf("O resultado da somatoria do vetor e: %d\n", somaVetor(v, n));
    printf("O resultado do maior elemento do vetor e: %d\n", maiorElemento(v, n));
    char s[] = "Hello, World!";
    printf("String original: %s\n", s);
    inverterString(s, 0, strlen(s) - 1);
    printf("String invertida: %s\n", s);
    return 0;
}