/*
Exerc´ıcio 3. Encontrar o valor do menor elemento de um vetor v com´ındices
de 0 at´e n − 1.
int min(int n, int *v);
*/

#include <stdio.h>

int min(int n, int *v){
	 //int min;
	 //a b c d e
	 if (n == 1)
	 	return v[n-1];

	 if (v[n-1] < min(n-1, v) ){

	 	return v[n-1];
	 }else{
	 	return min(n-1, v);

	 }

}

int main(){
	int vetor[10] = { 0, 1, 2, 3, -5,-6,0,1,65,100};
	printf("Minimo: %d\n", min(10,vetor));
	return 0;
}