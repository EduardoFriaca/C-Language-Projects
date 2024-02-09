#include <stdio.h>

//funcao que verifica se a matriz eh cubo magico
int verificaCuboMagico(int matriz[][10], int n) {
    int somaPrincipal = 0;
    int somaSecundaria = 0;
    int i,j;

    //aqui calculo a soma dos elementos da diagonal principal e secundaria
    for (i = 0; i < n; i++) {
        somaPrincipal += matriz[i][i];
        somaSecundaria += matriz[i][n - i - 1];
    }

    //ve se a soma das diagonais principais e secundarias sao iguais
    if (somaPrincipal != somaSecundaria) {
        return 0;
    }

    //verifico as somas das linhas e colunas
    for (i = 0; i < n; i++) {
        int somaLinha = 0;
        int somaColuna = 0;

        for (j = 0; j < n; j++) {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }

        //se soma de linha ou coluna for diferente da soma das diagonais nao eh um cubo magico
        if (somaLinha != somaPrincipal || somaColuna != somaPrincipal) {
            return 0;
        }
    }

    //se passar em toda verificacao eh cubo magico
    return 1;
}

int main() {
    int n,i,j;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    int matriz[10][10];

    printf("Digite os elementos da matriz:\n");
    for ( i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (verificaCuboMagico(matriz, n)) {
        printf("A matriz eh um cubo magico.\n");
    } else {
        printf("A matriz nao eh um cubo magico.\n");
    }

    return 0;
}

