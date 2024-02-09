//Nome:Eduardo Honorio Friaca        Tia:42205794   
//Nome:Arthur Cezar da Silveira Lima Tia:42210178
//Nome:Lucas Distretti Claudio       Tia:42244633

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGURA_MAX 1024
#define ALTURA_MAX 768
#define TAMANHO_MAX_CODIGO 10000 // Um tamanho máximo grande o suficiente para o código


// Função para ler um arquivo PBM e preencher a matriz de pixels
void lerArquivoPBM(char *nomeArquivo, int *largura, int *altura, int pixels[ALTURA_MAX][LARGURA_MAX]) {
    FILE *arquivo = fopen(nomeArquivo, "r"); // Abro o arquivo PBM para leitura
    if (!arquivo) {
        perror("Erro ao abrir o arquivo"); // Se não conseguir abrir, exibo um erro
        exit(1);
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), arquivo)) { // Leio o cabeçalho do arquivo PBM
        perror("Erro na leitura do arquivo");
        fclose(arquivo);
        exit(1);
    }

    // Ignoro linhas de comentário que começam com '#'
    do {
        fgets(buffer, sizeof(buffer), arquivo);
    } while (buffer[0] == '#');

    sscanf(buffer, "%d %d", largura, altura); // Leio as dimensões da imagem do arquivo
    if (*largura > LARGURA_MAX || *altura > ALTURA_MAX) {
        fprintf(stderr, "Dimensões da imagem excedem o limite máximo\n"); // Verifico se as dimensões são maiores que o limite
        fclose(arquivo);
        exit(1);
    }

    // Leio os dados dos pixels do arquivo e preencho a matriz de pixels
    int i,j;
    for (i = 0; i < *altura; i++) {
        for (j = 0; j < *largura; j++) {
            fscanf(arquivo, "%d", &pixels[i][j]);
        }
    }

    fclose(arquivo); // Fecho o arquivo após a leitura
}

// Função para ler a entrada manual dos dados da imagem
void lerEntradaManual(int *largura, int *altura, int pixels[ALTURA_MAX][LARGURA_MAX]) {
    printf("Informe as dimensões da imagem (largura altura): ");
    scanf("%d %d", largura, altura); // Peço ao usuário para informar a largura e altura da imagem

    if (*largura > LARGURA_MAX || *altura > ALTURA_MAX) {
        fprintf(stderr, "Dimensões da imagem excedem o limite máximo\n"); // Verifico se as dimensões são maiores que o limite
        exit(1);
    }

    printf("Informe os valores dos pixels (0 para branco, 1 para preto):\n");
    // Peço ao usuário para informar os valores de cada pixel
    int i, j;
    for (i = 0; i < *altura; i++) {
        for (j = 0; j < *largura; j++) {
            scanf("%d", &pixels[i][j]);
        }
    }
}

// Verifica se uma área específica da imagem é uniforme (todos os pixels têm o mesmo valor)
void eUniforme(int x, int y, int largura, int altura, int pixels[ALTURA_MAX][LARGURA_MAX], int *uniforme, char *cor) {
    int primeiroPixel = pixels[y][x]; // Pego o valor do primeiro pixel da área
    *uniforme = 1; // Assumo inicialmente que a área é uniforme
    *cor = primeiroPixel == 1 ? 'P' : 'B'; // Defino a cor com base no valor do primeiro pixel
    int i, j;

    for (i = y; i < y + altura && *uniforme; i++) {
        for (j = x; j < x + largura; j++) {
            if (pixels[i][j] != primeiroPixel) {
                *uniforme = 0; // Se encontrar um pixel diferente, a área não é uniforme
                break;
            }
        }
    }
}

// Processa a imagem para gerar o código correspondente
void processarImagem(int x, int y, int largura, int altura, int pixels[ALTURA_MAX][LARGURA_MAX], char *codigo) {
    int uniforme;
    char cor;
    eUniforme(x, y, largura, altura, pixels, &uniforme, &cor); // Verifico se a área atual é uniforme

    if (uniforme) {
        sprintf(codigo, "%c", cor); // Se for uniforme, o código é simplesmente a cor
    } else {
        // Se não for uniforme, divido a imagem em quatro quadrantes e processo cada um
        int larguraMedia = largura / 2;
        int alturaMedia = altura / 2;
        char codigoQuadrantes[4][TAMANHO_MAX_CODIGO]; // Armazeno o código de cada quadrante

        // Processo cada quadrante recursivamente
        processarImagem(x, y, larguraMedia, alturaMedia, pixels, codigoQuadrantes[0]);
        processarImagem(x + larguraMedia, y, largura - larguraMedia, alturaMedia, pixels, codigoQuadrantes[1]);
        processarImagem(x, y + alturaMedia, larguraMedia, altura - alturaMedia, pixels, codigoQuadrantes[2]);
        processarImagem(x + larguraMedia, y + alturaMedia, largura - larguraMedia, altura - alturaMedia, pixels, codigoQuadrantes[3]);

        // Concateno os códigos dos quadrantes com 'X' no início para formar o código final
        sprintf(codigo, "X%s%s%s%s", codigoQuadrantes[0], codigoQuadrantes[1], codigoQuadrantes[2], codigoQuadrantes[3]);
    }
}


void exibirAjuda() {
    // Exibe informações de ajuda sobre como usar o programa
    printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
    printf("Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.\n");
    printf("Argumentos:\n");
    printf("-?, --help : apresenta essa orientação na tela.\n");
    printf("-m, --manual: ativa o modo de entrada manual.\n");
    printf("-f, --file: considera a imagem representada no arquivo PBM.\n");
}

int main(int argc, char *argv[]) {
    int largura = 0, altura = 0;
    int pixels[ALTURA_MAX][LARGURA_MAX];
    char codigo[TAMANHO_MAX_CODIGO];
    char nomeArquivo[256];

    // Processa argumentos da linha de comando para o modo CLI
    if (argc > 1) {
        // Modo CLI: processa os argumentos da linha de comando
        if (strcmp(argv[1], "-f") == 0 && argc > 2) {
            lerArquivoPBM(argv[2], &largura, &altura, pixels);
        } else if (strcmp(argv[1], "-m") == 0) {
            lerEntradaManual(&largura, &altura, pixels);
        } else {
            exibirAjuda();
            return 0;
        }

        // Processamento da imagem e exibição do código resultante
        processarImagem(0, 0, largura, altura, pixels, codigo);
        printf("Código da imagem: %s\n", codigo);
        return 0;
    }

    // Modo interativo com menu para usuários que preferem uma interface gráfica
    char opcao;
    while (1) {
        // Apresenta o menu de opções ao usuário
        printf("\nMenu de Opções:\n");
        printf("1. Ler de arquivo PBM (-f)\n");
        printf("2. Entrada manual (-m)\n");
        printf("3. Ajuda (-?)\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        // Processa a escolha do usuário
        switch (opcao) {
            case '1':
                // Leitura de arquivo PBM
                printf("Digite o nome do arquivo PBM: ");
                scanf("%s", nomeArquivo);
                lerArquivoPBM(nomeArquivo, &largura, &altura, pixels);
                break;
            case '2':
                // Entrada manual de dados da imagem
                lerEntradaManual(&largura, &altura, pixels);
                break;
            case '3':
                // Exibe informações de ajuda
                exibirAjuda();
                continue;
            case '4':
                // Sai do programa
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                continue;
        }

        // Processamento da imagem e exibição do código resultante
        processarImagem(0, 0, largura, altura, pixels, codigo);
        printf("Código da imagem: %s\n", codigo);
    }

    return 0;
}
