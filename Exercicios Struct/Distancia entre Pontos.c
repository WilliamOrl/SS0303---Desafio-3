#include <stdio.h>
#include <math.h>


typedef struct{
	float x;
	float y;
}pontos;


float distancia(pontos ponto_a,pontos ponto_b);


int main (void){
	float dis;

	
	pontos ponto_a,ponto_b;
	
	printf("digite o valor de X o ponto A e B: ");
	scanf("%f %f",&ponto_a.x,&ponto_b.x);
	
	printf("\ndigite o valor de Y o ponto A e B: ");
	scanf("%f %f",&ponto_a.y,&ponto_b.y);
	
	dis = distancia(ponto_a,ponto_b);
	
	printf("\n A distancia entre os pontos e = %.2f",dis);
	
	return 0;
}

float distancia(pontos ponto_a,pontos ponto_b){
	float dif;
	dif = sqrt(pow(ponto_a.x-ponto_b.x,2) + pow(ponto_a.y-ponto_b.y,2));
	return dif;
}
