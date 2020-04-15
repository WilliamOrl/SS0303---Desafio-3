#include<stdio.h>
main(){
	int n;
	unsigned long int p,q,r,s,x,y;
	int i,j,k;
	unsigned long long int c=0;	

	scanf("%d",&n);
	
		if(n>=2 && n<=100000){
		
			long int a[n][n],b[n][n];
		
			
			scanf("%d",&p);
			scanf("%d",&q);
			scanf("%d",&r);
			scanf("%d",&s);
			scanf("%d",&x);
			scanf("%d",&y);
			
			/*
			printf("variavel p %d\n",p);
			printf("variavel q %d\n",q);
			printf("variavel r %d\n",r);
			printf("variavel s %d\n",s);
			printf("variavel x %d\n",x);
			printf("variavel y %d\n",y);
			printf("\n");
			
			teste1=7%5;
			teste2=((p*1)+(q*3))%x;
			
			printf("variavel teste1 %d\n",teste1);
			printf("variavel teste2 %d\n",teste2);
			printf("\n");
			*/	
			
			if(x>=2 && y>=2 && x<=10000 && y<=10000 && p<x && q<x && p>=0 && q>=0 && r<y && s<y && r>=0 && s>=0)
			{
			
		/////////////////////////////////////////////////////////////////////
		//					Pra a Matriz A
		////////////////////////////////////////////////////////////////////
				for(i=1;i<=n;i++){		
					for(j=1;j<=n;j++)
						a[i][j]=((p*i)+(q*j))%x;
				}
			
			/*	for(i=1;i<=n;i++){		
					for(j=1;j<=n;j++)
						printf("matriz a[%d][%d] = %d\n",i,j,a[i][j]);
				}*/
				
				
		/////////////////////////////////////////////////////////////////////
		//					Pra a Matriz B
		////////////////////////////////////////////////////////////////////
			
				for(i=1;i<=n;i++){		
					for(j=1;j<=n;j++)
						b[i][j]=((r*i)+(s*j))%y;				
					}
					
			/*	printf("\n");
				for(i=1;i<=n;i++){		
					for(j=1;j<=n;j++)
						printf("matriz b[%d][%d] = %d\n",i,j,b[i][j]);
				}*/
				
				
		/////////////////////////////////////////////////////////////////////
		//					Pra a Matriz C
		////////////////////////////////////////////////////////////////////
				
				scanf("%d",&i);
				scanf("%d",&j);	
				c=0;
			
				if(i>=1 && j>=1 && i<=n && j<=n){		
	
				for(k=1;k<=n;k++)
					c=c+a[i][k]*b[k][j];							
			
				printf("%d\n",c);				
				}
			}
	
	}
 return 0;
}