#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LARGURA 1024
#define MAX_ALTURA 768

// Fun��o auxiliar para verificar se uma regi�o da imagem � uniforme
int eUniforme(int x, int y, int largura, int altura, int pixels[MAX_ALTURA][MAX_LARGURA]) {
    int primeiroPixel = pixels[y][x];
    for (int i = y; i < y + altura; i++) {
        for (int j = x; j < x + largura; j++) {
            if (pixels[i][j] != primeiroPixel) {
                return 0;  // N�o � uniforme
            }
        }
    }
    return 1;  // � uniforme
}

// Fun��o recursiva para processar a imagem
void processarImagem(int x, int y, int largura, int altura, int pixels[MAX_ALTURA][MAX_LARGURA], char *codigo) {
    if (eUniforme(x, y, largura, altura, pixels)) {
        // Se a regi�o � uniforme, adiciona 'P' (preto) ou 'B' (branco) ao c�digo
        codigo[0] = pixels[y][x] == 1 ? 'P' : 'B';
        codigo[1] = '\0';
    } else {
        // Se n�o � uniforme, divide a imagem em quatro quadrantes e processa cada um
        int larguraMedia = largura / 2;
        int alturaMedia = altura / 2;

        // Inicia o c�digo com 'X'
        strcpy(codigo, "X");

        // Processa cada quadrante
        char codigoQuadrante[4][MAX_ALTURA * MAX_LARGURA]; // Buffer para cada quadrante
        processarImagem(x, y, larguraMedia, alturaMedia, pixels, codigoQuadrante[0]);
        processarImagem(x + larguraMedia, y, largura - larguraMedia, alturaMedia, pixels, codigoQuadrante[1]);
        processarImagem(x, y + alturaMedia, larguraMedia, altura - alturaMedia, pixels, codigoQuadrante[2]);
        processarImagem(x + larguraMedia, y + alturaMedia, largura - larguraMedia, altura - alturaMedia, pixels, codigoQuadrante[3]);

        // Concatena os c�digos dos quadrantes
        for (int i = 0; i < 4; i++) {
            strcat(codigo, codigoQuadrante[i]);
        }
    }
}


void lerArquivoPBM(char *nomeArquivo, int *largura, int *altura, int pixels[MAX_ALTURA][MAX_LARGURA]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Ignora o cabe�alho PBM (P1) e poss�veis coment�rios
    char buffer[100];
    fgets(buffer, sizeof(buffer), arquivo); // L� a linha do cabe�alho
    do {
        fgets(buffer, sizeof(buffer), arquivo);
    } while (buffer[0] == '#'); // Ignora coment�rios

    // L� as dimens�es da imagem
    sscanf(buffer, "%d %d", largura, altura);

    // L� os valores dos pixels
    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            fscanf(arquivo, "%d", &pixels[i][j]);
        }
    }

    fclose(arquivo);
}


void lerEntradaManual(int *largura, int *altura, int pixels[MAX_ALTURA][MAX_LARGURA]) {
    printf("Informe as dimens�es da imagem (largura altura): ");
    scanf("%d %d", largura, altura);

    if (*largura > MAX_LARGURA || *altura > MAX_ALTURA) {
        fprintf(stderr, "Dimens�es da imagem excedem o limite m�ximo\n");
        exit(1);
    }

    printf("Informe os valores dos pixels (0 para branco, 1 para preto):\n");
    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            scanf("%d", &pixels[i][j]);
        }
    }
}


// Fun��o para exibir o menu interativo
void exibirMenu() {
    printf("\nMenu de Op��es:\n");
    printf("1. Ler de arquivo PBM\n");
    printf("2. Entrada manual\n");
    printf("3. Ajuda\n");
    printf("4. Sair\n");
}

int main() {
    int largura, altura;
    int pixels[MAX_ALTURA][MAX_LARGURA];
    char opcao;
    char nomeArquivo[256];
    char codigo[MAX_LARGURA * MAX_ALTURA];

    while (1) {
        exibirMenu();
        printf("Escolha uma op��o: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Digite o nome do arquivo PBM: ");
                scanf("%s", nomeArquivo);
                lerArquivoPBM(nomeArquivo, &largura, &altura, pixels);
                processarImagem(0, 0, largura, altura, pixels, codigo);
                printf("C�digo da imagem: %s\n", codigo);
                break;
            case '2':
                lerEntradaManual(&largura, &altura, pixels);
                processarImagem(0, 0, largura, altura, pixels, codigo);
                printf("C�digo da imagem: %s\n", codigo);
                break;
            case '3':
                printf("Ajuda: Este programa codifica imagens bin�rias...\n");
                break;
            case '4':
                printf("Saindo...\n");
                return 0;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    }
    return 0;
}

