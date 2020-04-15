#include<stdio.h>
int main(){
	
	int n,m,i=0,j=0,k=0,maior=0,aux,x=4;
	float div;
	
	scanf("%d",&n);
	
	do{
		scanf("%d",&m);	
	
		int mat[m][m],digv[m][m];	
	
		//==================================================================================
		//							Escrita dos numeros na matriz
		//==================================================================================
	
		for(i=0;i!=m;i++){								//escrita das variaveis na matriz
			for(j=0;j!=m;j++){
			scanf("%d",&aux);
			aux=aux*aux;
			div=aux;
			
			for(k=1;div>10;k++)							//contagem do numero de digitos de cada elemento da matriz
				div=div/10;
			
			
			digv[i][j]=k;
			mat[i][j]=aux;
			
			}			
		}


		//==================================================================================
		//					Diferenciação de digitos da variavel
		//==================================================================================
		
		for(j=0;j!=m;j++)
			for(i=0,k=0;i!=m;i++){
				switch(k){
				
					case 0:
						aux = digv[i][j];
						
						if(aux>=maior){
							maior=aux;

							}
						if(i==m-1){
							i=-1;
							k=1;
						}
						
						break;
					case 1:		
						digv[i][j] = maior - digv[i][j];
											
						if(i==m-1){
							k=0;
							maior=0;
						}
						
						break;
				}
			}
	

		
		//==================================================================================
		//					Escrita na tela com enquadramento
		//==================================================================================
		
		printf("Quadrado da matriz #%d:",x);
	
		for(i=0;i<m;i++){							
				
			printf("\n");	
		
			for(j=0;j<m;j++){
			
					while(digv[i][j]>0){
					aux = digv[i][j];
					aux--;
					digv[i][j] = aux;
					printf(" ");						
					}
									
				printf(" %d",mat[i][j]);
				
			}
		}
	printf("\n");			
	x++;
	n--;		
	}while(n!=0);
	return 0;	
}