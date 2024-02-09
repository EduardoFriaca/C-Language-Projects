#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int numero) {
    // 0 e 1 n�o s�o primos
    if (numero <= 1) {
        return false;
    }
    int i;

    // Verifica divis�es de 2 at� a raiz quadrada do n�mero
    for (i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Se encontrar um divisor, n�o � primo
        }
    }

    return true; // Se nenhum divisor foi encontrado, � primo
}

int main() {
    int numero;
    printf("Digite um n�mero inteiro maior que 1: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("%d � um n�mero primo.\n", numero);
    } else {
        printf("%d n�o � um n�mero primo.\n", numero);
    }

    return 0;
}

