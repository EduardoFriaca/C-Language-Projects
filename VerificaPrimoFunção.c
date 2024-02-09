#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int numero) {
    // 0 e 1 não são primos
    if (numero <= 1) {
        return false;
    }
    int i;

    // Verifica divisões de 2 até a raiz quadrada do número
    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Se encontrar um divisor, não é primo
        }
    }

    return true; // Se nenhum divisor foi encontrado, é primo
}

int main() {
    int numero;
    printf("Digite um número inteiro maior que 1: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }

    return 0;
}

