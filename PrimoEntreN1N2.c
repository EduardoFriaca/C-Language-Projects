#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    int i;
    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N1, N2, i;
    
    printf("Digite o valor de N1: ");
    scanf("%d", &N1);
    printf("Digite o valor de N2: ");
    scanf("%d", &N2);

    printf("Números primos entre %d e %d:\n", N1, N2);

    for ( i = N1; i < N2; i++) {
        if (ehPrimo(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

