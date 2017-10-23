/*
Exerc´ıcio 1. Computar a soma dos primeiros n inteiros positivos.
int soma(int n);
*/

#include <stdio.h>

int soma(int n){
	if (n == 0)
		return 0;
	return n + soma(n -1);
}

int main(){
	printf("Soma:%d\n",soma(4) );

	return 0;
}