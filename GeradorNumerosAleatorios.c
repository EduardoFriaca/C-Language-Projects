#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Função para realizar uma busca linear em um vetor
int busca_linear(int vetor[], int tamanho, int elemento) {
	int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return i; // Retorna a posição se o elemento for encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    int vetor[TAM], i;
    srand(time(NULL)); // Inicializa o gerador de números pseudoaleatórios

    // Preenche o vetor com valores aleatórios de 1 a 100
    for (i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100 + 1;
    }

    // Valores a serem buscados
    int valores[] = {10, 15, 60, 65, 90};
    int num_valores = sizeof(valores) / sizeof(valores[0]);

    // Busca e imprime as posições dos valores
    for (i = 0; i < num_valores; i++) {
        int posicao = busca_linear(vetor, TAM, valores[i]);
        if (posicao != -1) {
            printf("O valor %d foi encontrado na posição %d.\n", valores[i], posicao);
        } else {
            printf("O valor %d não foi encontrado no vetor.\n", valores[i]);
        }
    }

    return 0;
}

