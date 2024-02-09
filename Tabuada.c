#include <stdio.h>

// Fun��o para apresentar a tabuada de um n�mero N
void tabuada(int N) {
	int i;
    printf("Tabuada do %d:\n", N);
    for ( i = 1; i <= 9; i++) {
        printf("%d x %d = %d\n", N, i, N * i);
    }
}

int main() {
    int numero;

    // Solicita ao usu�rio o n�mero para o qual deseja ver a tabuada
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &numero);

    // Apresenta a tabuada do n�mero fornecido pelo usu�rio
    tabuada(numero);

    return 0;
}

