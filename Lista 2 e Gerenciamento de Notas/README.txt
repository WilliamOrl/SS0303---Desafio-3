Vitor Paschoal	11215532
William Orlato	11800991

1) O numero do Y no final do programa será 4.

2) Na linha "printf("\n\%d\n", &q);" deve-se mudar o "&" para "**" ficando "printf("\n\%d\n", &q);". Pois, como q
é um ponteiro para ponteiro não sinalizar os dois asteristicos fará que ele pegue a informação da do espaço de
armazenamento do segundo ponteiro.

3) As expressões validas são A e D

4) Para o Funcionamento do programa deve ser feito as seguintes alterações:

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[2], i;
	int *ptr = arr;
	int *ptr_new = NULL;

	arr[0] = 10;
	arr[1] = 20;

	ptr_new = (int *)realloc(ptr_new, 3*sizeof(int));

	for(i = 0; i < 2; i++)
		ptr_new[i] = ptr[i];

	*(ptr_new + 2) = 30;

	for(i = 0; i < 3; i++)
		printf("\%d ", *(ptr_new + i));

	getchar();

	return 0;
}

A realloc expande o espaço indicado mas muitas vezes não possível pois o espaço não esta livre, estão ele copia
os dados para uma região onde há espaço disponível, o endreço que estávamos tentando expandir estava na memória
Stack, porem o realloc apenas funciona corretamente em endereços da memória Haep. 


5)
	I) Nesta função Recursiva o programa escreve os numeros n de forma decrescente até chegar em 1 escrevendo
	   Fim no final da função.

	II) Nesta função Recursiva o programa escreve os numeros n de forma crescente até chegar em 1, mas 
	    antes escrevendo Fim no inicio da função

	III) Está função é uma junção das duas anteriores escrevendo primeiro os numeros de forma decrescente e Fim
	     Em seguida escrevendo de forma crescente. 

	IV) Sendo 1=x e y=x+1 esta função escreve Fim1 e após Fim(y) retornado em um looping sempre escrevendo
	    sempre Fim1 e a abaixo Fim(y) incrementando sempre o valor de y em 1, até y=n digitado, assim retornando y =0. 

6) As aspas simples servem para delimetar um caracter, já as aspas duplas servem para delimitar uma string


	   