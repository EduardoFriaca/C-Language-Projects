#include <stdio.h>

// Função para apresentar a tabuada de um número N
void tabuada(int N) {
	int i;
    printf("Tabuada do %d:\n", N);
    for ( i = 1; i <= 9; i++) {
        printf("%d x %d = %d\n", N, i, N * i);
    }
}

int main() {
    int numero;

    // Solicita ao usuário o número para o qual deseja ver a tabuada
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Apresenta a tabuada do número fornecido pelo usuário
    tabuada(numero);

    return 0;
}

