#include<stdio.h>
#include<math.h>

int main(void){
	
	int t,n,i,j,k,l;
	float aux;
	int auxint;
	
	scanf("%d",&t);									//leitura do numero de vezes que o programa vai repetir
	
	if(t>=1 && t<=50){
		
		for(;t!=0;t--){
		
			scanf("%d",&n);							//leitura da do numero de varetas
			
			if(n>=1 && n<=50){
				
			int varetas[n];
			
				for(i=0;i<=n;i++)					//limpando o vetor 
					varetas[i]=0;
				
				j=1;								//numero do primeiro disco
				
				for(i=0,l=0;l!=2;i++){					//testadando os discos em cada vareta 
					
					if(varetas[i]==0){
						varetas[i] = j;
						l=0;
						i=0;
						j++;
					}
						
					for(k=0;k!=1;){
						
						aux = varetas[i] + j;
						aux=sqrt(aux);
						
						auxint = aux;
						if(aux == auxint){
						varetas[i] = j;
							if(i!=0){
								k=1;
								i=0;
								j++;	
							}
						}
						else{
							if(i!=0 && l!=1){
								i=0;
								k=1;		
							}
							else{
								if(i!=n){
									l=1;
									k=1;
								}else
									if(i==n)
										l=2;
							}
						}
							
												
					}
				}
				j--;
				printf("%d\n",j);
				
			}else
			t++;
		}
	}	
}
