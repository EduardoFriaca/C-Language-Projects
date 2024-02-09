#include <stdio.h>

int potencia(int x, int n) {                       
    if (n == 0) {  //x^0 = 1
        return 1;
    }

    
    return x * potencia(x, n - 1); //aqui retorna com a funcao da potencia
}

int main() {
    int x, n;  // x^n
    printf("Informe o valor de x: ");
    scanf("%d", &x);
    printf("Informe o valor de n: "); 
    scanf("%d", &n);

    int resposta = potencia(x, n);
    printf("%d elevado a %d eh igual a %d\n", x, n, resposta);

    return 0;
}

