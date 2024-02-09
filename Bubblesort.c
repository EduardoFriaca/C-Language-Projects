#include <stdio.h>
#include <string.h> // Para a função memcpy
#include <stdlib.h> // Para a função rand e srand
#include <time.h>   // Para inicializar a semente rand

// Função para embaralhar os elementos de um vetor
void shuffle(int array[], int length) {
    int i, j, temp;
    for (i = length - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Bubble Sort com contador de trocas
int bubbleSort(int array[], int length) {
    int swaps = 0;  // Inicialize o contador de trocas com 0
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Realize a troca
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

// Insertion Sort com contador de trocas
int insertionSort(int array[], int length) {
    int swaps = 0;
    int i;
    for (i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
            swaps++;
        }
        array[j + 1] = key;
    }
    return swaps;
}

// Selection Sort com contador de trocas
int selectionSort(int array[], int length) {
    int swaps = 0;
    int i, j;
    for (i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Realize a troca
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
        swaps++;
    }
    return swaps;
}

int main() {
    int array[] = {54, 57, 61, 9, 13, 22, 30, 65, 69, 70, 78, 84, 87, 90, 92, 97, 34, 45, 47, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int copiedArray[length];
    memcpy(copiedArray, array, sizeof(array));

    int swaps_pior, swaps_medio, swaps_melhor;

    // Caso Pior: Vetor em ordem reversa
    swaps_pior = bubbleSort(array, length);
    printf("Bubble Sort (Pior Caso): %d trocas\n", swaps_pior);

    // Caso Médio: Vetor aleatório
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    shuffle(copiedArray, length);
    swaps_medio = bubbleSort(copiedArray, length);
    printf("Bubble Sort (Caso Médio): %d trocas\n", swaps_medio);

    // Caso Melhor: Vetor já ordenado
    swaps_melhor = bubbleSort(array, length);
    printf("Bubble Sort (Melhor Caso): %d trocas\n", swaps_melhor);

    // Reinicialize os vetores para os outros algoritmos
    memcpy(copiedArray, array, sizeof(array));

    swaps_pior = insertionSort(array, length);
    printf("Insertion Sort (Pior Caso): %d trocas\n", swaps_pior);

    shuffle(copiedArray, length);
    swaps_medio = insertionSort(copiedArray, length);
    printf("Insertion Sort (Caso Médio): %d trocas\n", swaps_medio);

    swaps_melhor = insertionSort(array, length);
    printf("Insertion Sort (Melhor Caso): %d trocas\n", swaps_melhor);

    // Reinicialize os vetores para os outros algoritmos
    memcpy(copiedArray, array, sizeof(array));

    swaps_pior = selectionSort(array, length);
    printf("Selection Sort (Pior Caso): %d trocas\n", swaps_pior);

    shuffle(copiedArray, length);
    swaps_medio = selectionSort(copiedArray, length);
    printf("Selection Sort (Caso Médio): %d trocas\n", swaps_medio);

    swaps_melhor = selectionSort(array, length);
    printf("Selection Sort (Melhor Caso): %d trocas\n", swaps_melhor);

    return 0;
}

