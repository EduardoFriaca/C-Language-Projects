#include <stdio.h>
#define PI 3.14

float calculaarea(float raio){
	float area;
	area = PI * (raio*raio);
	return area;
}

int main(){
	float area, raio;
	
	printf("Digite o raio:");
	scanf("%f", &raio);
	
	area = calculaarea(raio);
	printf("A area eh de %.2f", area);
	return 0;
	
	
}
