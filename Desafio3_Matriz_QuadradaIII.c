#include <stdio.h>
#include<math.h>
int main(void){
	
	int n,i,j,k,maior=0;
	double div,aux=0,aux1,aux2;
	 
	
	 do{
		 scanf("%d",&n);
			
		 if(n>=1 && n<=15){
			double mat[n][n];
			int dig[n][n];
		
		//==================================================================================
		//							Escrita dos numeros na matriz
		//==================================================================================
			
			for(i=0;i!=n;i++){
			
					aux1 = pow(2,i);
				
				for(j=0;j!=n;j++){
					aux2 = pow(2,j);
					aux = aux1*aux2;
					div=aux;
					
					for(k=1;div>10;k++)							//contagem do numero de digitos de cada elemento da matriz
						div=div/10;
				
				
					dig[i][j]=k;
					mat[i][j]=aux;
					
				}
			}
		 	
		//==================================================================================
		//					Diferenciação de digitos da variavel
		//==================================================================================
		
		 
			for(j=0;j!=n;j++)
				for(i=0,k=0;i!=n;i++){
					switch(k){
					
						case 0:
							aux = dig[i][j];
							
							if(aux>=maior){
								maior=aux;
	
								}
							if(i==n-1){
								i=-1;
								k=1;
							}
							
							break;
						case 1:		
							dig[i][j] = maior - dig[i][j];
												
							if(i==n-1){
								k=0;
								maior=0;
							}
							
							break;
					}
				}
			 	 
		//==================================================================================
		//					Escrita na tela com enquadramento
		//==================================================================================
		 
			//printf("\n");
			 
			for(i=0;i<n;i++){							
					
				printf("\n");	
			
				for(j=0;j<n;j++){
				
						while(dig[i][j]>0){
						aux = dig[i][j];
						aux--;
						dig[i][j] = aux;
						printf(" ");						
						}
										
					printf(" %.0f",mat[i][j]);
							
				}
			}
			printf("\n\n");	
		}
	}while(n!=0);
	return 0;
}