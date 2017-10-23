
/*
Exerc´ıcio 2. Computar a soma dos elementos de um vetor v com ´ındices de
0 at´e n − 1.
int soma(int n, int *v);
*/

#include <stdio.h>

int soma(int n, int *v){

	n--;
	
	if (n < 0)
		return 0;

	return v[n] + soma(n, v);

}

int main(){
	int vetor[5] = {1, 2, 3, 4, 5};
	printf("Soma:%d\n", soma(5, vetor) );

	return 0;
}