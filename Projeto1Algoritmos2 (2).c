#include <stdio.h>
// Nome: Eduardo Honorio Friaca   Tia:42205794

// função para mostrar o polinômio, contem os coeficientes e graus
void mostrarosPolinomios(float polinomio[], int grau) { //fun
    int i;
    printf("P(x) = ");
    for (i = grau; i >= 0; i--) { //loop decrescente que exibe  os elementos em ordem decrescente de grau
        if (polinomio[i] != 0) { //mostra o coeficiente se for diferente de 0
            if (i == grau || polinomio[i] < 0) { // se for o primeiro termo ou é negativo, não tem +
                printf("%.1fx^%d ", polinomio[i], i);
            } else {
                printf("+ %.1fx^%d ", polinomio[i], i); // coeficiente positivos vai ter o sinal(+)
            }
        }
    }
    printf("\n");
}

//função para calcular o valor do polinômio para um valor x
float calcularPolinomio(float polinomio[], int grau, float x) {
    float valor = 0;
    int i;
    for (i = 0; i <= grau; i++) { //loop para cada coeficiente
        float termo = polinomio[i]; //coeficiente atual 
        int j;
        for (j = 1; j <= i; j++) { // multipliquei pelo valor de x, i vezes, ou seja x elevado a i
            termo *= x;
        }
        valor += termo; // acumulei o valor total
    }
    return valor;
}

//Função que soma os dois polinomios
void somaPolinomios(float p1[], float p2[], float resultado[], int grau) {
    int i;
    for (i = 0; i <= grau; i++) { // fiz o loop parra somar coeficiente por coeficiente
        resultado[i] = p1[i] + p2[i];
    }
}

//Função que multiplica os dois polinomios
void multiplicacaoPolinomios(float p1[], float p2[], float resultado[], int grau) {
    int i, j;
    for (i = 0; i <= 2 * grau; i++) {
        resultado[i] = 0; // o vetor resultado incializa com zero
    }
    for (i = 0; i <= grau; i++) { //multipliquei cada termo de p1 com cada termo de p2
        for (j = 0; j <= grau; j++) {
            resultado[i + j] += p1[i] * p2[j];  //somei na posição i+j do resultado, ja que multiplicacao de x^i * x^j é: x^i+j
        }
    }
}

#include <stdio.h>

int main() { // função principal
    int grau, opcao, i;
    float x; //armazena o valor de x para calcular o valor do polinômio

    printf("Informe o grau maximo dos polinomios: "); //soliciata o grau dos polinomios
    scanf("%d", &grau);

    float polinomio1[grau + 1];  //declarei os vetores para os polinomios e seu resultado, grau +1 pois o array começa em 0
    float polinomio2[grau + 1];
    float resultado[2 * grau + 1];  //aloquei espaço para o resultado da multiplicação: grau máximo para dois polinomios de grau n eh 2n.

    while(1) { //loop com o menu e as opcoes da calculadora
        printf("\nCalculadora de Polinomios:\n");
        printf("1. Preencher Polinomio 1\n");
        printf("2. Preencher Polinomio 2\n");
        printf("3. Mostrar Polinomios\n");
        printf("4. Calcular valor do Polinomio\n");
        printf("5. Somar Polinomios\n");
        printf("6. Multiplicar Polinomios\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Preencha os coeficientes do Polinomio 1:\n");
            for (i = 0; i <= grau; i++) {
                printf("Coeficiente de x^%d: ", i);
                scanf("%f", &polinomio1[i]);
            }
        } else if (opcao == 2) {
            printf("Preencha os coeficientes do Polinomio 2:\n");
            for (i = 0; i <= grau; i++) {
                printf("Coeficiente de x^%d: ", i);
                scanf("%f", &polinomio2[i]);
            }
        } else if (opcao == 3) {
            printf("\nPolinomio 1: ");
            mostrarosPolinomios(polinomio1, grau);
            printf("Polinômio 2: ");
            mostrarosPolinomios(polinomio2, grau);
        } else if (opcao == 4) {
            printf("Escolha o polinomio (1 ou 2): ");
            int escolha;
            scanf("%d", &escolha);
            printf("Informe o valor de x: ");
            scanf("%f", &x);
            if (escolha == 1) {
                printf("P(%.2f) para Polinomio 1 = %.2f\n", x, calcularPolinomio(polinomio1, grau, x));
            } else if (escolha == 2) {
                printf("P(%.2f) para Polinomio 2 = %.2f\n", x, calcularPolinomio(polinomio2, grau, x));
            } else {
                printf("Escolha inválida!\n");
            }
        } else if (opcao == 5) {
            somaPolinomios(polinomio1, polinomio2, resultado, grau);
            printf("\nResultado da soma: ");
            mostrarosPolinomios(resultado, grau);
        } else if (opcao == 6) {
            multiplicacaoPolinomios(polinomio1, polinomio2, resultado, grau);
            printf("\nResultado da multiplicacao: ");
            mostrarosPolinomios(resultado, 2 * grau);
        } else if (opcao == 7) {
            return 0; //encerro o programa
        } else {
            printf("\nOpcao invalida!\n");
        }
    } 

    return 0;
}

