#include <stdio.h>

int soma_digitos(int n) {
    if (n < 10) {    //se n for um digito so, retorno n.
        return n;
    } else {
        return n % 10 + soma_digitos(n / 10);   //senao eu divido o numero para ter apenas um digito e o somo recursivamente
    }
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    int resultado = soma_digitos(numero); //chamei a funcao
    printf("A soma dos digitos do numero eh igual a %d", resultado);

    return 0;
}

