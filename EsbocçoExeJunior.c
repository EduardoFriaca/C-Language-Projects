#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// o computador vai sortear um numero de 1 até 100

int main(){

	int sorteio, palpite;
	
	srand(time(NULL));   //incilicializador de sorteio
	sorteio = 1 +rand() %100;
	
	printf("Digite um numero:");
	scanf("%d", &palpite);
	
	while(palpite != sorteio){
		if (palpite <1 || palpite >100){
			printf("Valor inválido.Tente novamente:");
		}else if(palpite > sorteio){
	        printf("Valor muito alto.Tente novamente:");
		}else if (palpite < sorteio){
            printf("Valor muito baixo. Tente novamente:");
		}
		
		scanf("%d, palpite");
    }
	
	printf("Voce acertou!");
	
	return 0;
}

