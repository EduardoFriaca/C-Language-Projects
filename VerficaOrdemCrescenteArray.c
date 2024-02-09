#include <stdio.h>
#include <stdbool.h>

bool verificaOrdemCrescente(int vetor[], int tamanho) {
	int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] < vetor[i - 1]) {
            return false; // Se algum elemento for menor que o anterior, não está em ordem crescente
        }
    }
    return true; // Se todos os elementos estão em ordem crescente
}

int main() {
    int tamanho, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    bool estaEmOrdem = verificaOrdemCrescente(vetor, tamanho);

    if (estaEmOrdem) {
        printf("O vetor está em ordem crescente.\n");
    } else {
        printf("O vetor não está em ordem crescente.\n");
    }

    return 0;
}

