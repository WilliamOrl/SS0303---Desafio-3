#include<stdio.h>
#include<string.h>

typedef struct{
	char nome[30];
	float clorias;
	float gramas;
}produto;

void Leitura(produto *comida,int n);
void Lista(produto *comida,int n);

int main(void){
	
	int i,n;

	
	scanf("%d",&n);
	
	produto comida[n];

	Leitura(comida,n);
		
	Lista(comida,n);
	
	return 0;
		 	
}

void Leitura(produto *comida,int n){

	int i;
	
	for(i=0;i!=n;i++){
		fflush(stdin);
		fgets(comida[i].nome, 30, stdin);
	
		scanf("%f", &comida[i].clorias);
	
		scanf("%f", &comida[i].gramas);
	}
	return;
}

void Lista(produto *comida,int n){
	
	int i,j,k,aux=0,aux2=0;
	int maior[n];
	
	for(i=n-1;i>=0;i--){
		for(j=0;j!=n;j++){
			if(aux<=comida[j].clorias){
				if(aux==comida[j].clorias && aux2<=comida[j].gramas){
					aux = comida[j].clorias;
					aux2 = comida[j].gramas;
					maior[i]=j;	
				}			
				aux = comida[j].clorias;
				aux2 = comida[j].gramas;
				maior[i]=j;	
			}
		}
		k = maior[i];
		comida[k].clorias = -100;
		comida[k].gramas = -100;
		aux = 0;
		aux2 = 0;
	}
	
	for(i=0,j=1;i!=n;i++,j++){
		aux = maior[i];
		printf("%d = %s",j,comida[aux].nome);
	}
	return;
}
