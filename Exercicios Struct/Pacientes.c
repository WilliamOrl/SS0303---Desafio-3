#include<stdio.h>
#include<string.h>

typedef struct{
	char nome[30];
	float tamanho;
	float peso;
	char genero;
	int id;
}individuo;


int main(void){
	
	int i,n,aux;

	
	scanf("%d",&n);
	
	individuo pessoa[n];
	
	for(i=0;i!=n;i++){
				
		fflush(stdin);
		fgets(pessoa[i].nome, 30, stdin);
	
		scanf("%f", &pessoa[i].tamanho);
	
		scanf("%f", &pessoa[i].peso);
	
		scanf("  %c", &pessoa[i].genero);
	
		scanf("%d", &pessoa[i].id);
		
	}

		
	while(aux!=-1){
		scanf("%d",&aux);
		for(i=0;i!=n;i++){
			if(pessoa[i].id==aux){
				printf("Nome: %s",pessoa[i].nome);
				printf("altura: %.1f\n",pessoa[i].tamanho);
				printf("Peso: %.1f\n",pessoa[i].peso);
				printf("Genero: %c\n",pessoa[i].genero);
				printf("Id: %d\n",pessoa[i].id);	
			}
		}
	}	 	
}

