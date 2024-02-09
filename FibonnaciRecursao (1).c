#include <stdio.h>

// Funcao recursiva para calcular o n-esimo numero de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("O numero de Fibonacci nao esta definido para valores negativos.\n");
    } else {
        int resultado = fibonacci(n);
        printf("O %d-esimo numero de Fibonacci eh: %d\n", n, resultado);
    }

    return 0;
}

