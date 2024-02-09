#include <stdio.h>

int mul(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + mul(a, b - 1); //adicionei o a para si mesmo em b vezes
}

int main() {
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    int resultado = mul(a, b);
    printf("%d * %d = %d\n", a, b, resultado);

    return 0;
}

