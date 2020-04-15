#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define vezes 1000000

void atk(int *atacante, int *defensor, int dano);

int main(){
	
	int ev1,ev2,ev1bk,ev2bk,at,d,p=0;
	double vitoria=0;
	unsigned int dado;
	
	do{
		scanf("%d",&ev1);
		scanf("%d",&ev2);
		scanf("%d",&at);
		scanf("%d",&d);
		ev1bk = ev1;
		ev2bk = ev2;
		vitoria = 0;
		p=0;
		srand(time(NULL));
		
		if(ev1>=1 && ev2>=1 && ev1<=10 && ev2<=10 && at>=1 && at<=5 && d>=1 && d<=10){
			do{	
				
				dado = rand() %6;	
				dado = dado + 1;  
				
				if(dado<=at)
					atk(&ev1,&ev2,d);
				
				if(dado>at)
					atk(&ev2,&ev1,d);
				
				
				if(ev1<=0){
					p++;				
					ev1 = ev1bk;
					ev2 = ev2bk;
				}
				
				if(ev2<=0){
					vitoria++;
					p++;
					ev1 = ev1bk;
					ev2 = ev2bk;
				}
				
				
			}while(p!=vezes);
		//	printf("%f\n",vitoria);
			vitoria = (vitoria/vezes)*100;
			printf("%.1f\n",vitoria);
		}
			 
	}while(ev1!=0 && ev2!=0 && at!=0 && d!=0);
	return 0;
}

void atk(int *atacante, int *defensor, int dano){
	*defensor = *defensor - dano;
	*atacante = *atacante + dano;
}