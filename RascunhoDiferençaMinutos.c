#include <stdio.h>
#include <stdlib.h>

int funcaominuto(int horas1, int minutos1, int horas2, int minutos2){
	int tempo1, tempo2, diferenca; 
	tempo1 = (horas1 *60)+ minutos1;
	tempo2 = (horas2 *60)+ minutos2;
	diferenca = abs(tempo2 - tempo1);
	return diferenca;
}

int main(){
	int horas1, minutos1, horas2, minutos2, diferenca;
	printf("Digite as horas e os minutos: no formato h:m\n");
	scanf("%d:%d", &horas1, &minutos1);
	printf("Digite as horas e os minutos:\n");
	scanf("%d:%d", &horas2, &minutos2);
	
	diferenca = funcaominuto(horas1, minutos1, horas2, minutos2);
	printf("A diferenca eh de: %d minutos", diferenca);
	return 0;
}

