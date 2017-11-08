/*Exerc´ıcio 6. Calcular 2^k
.
long pot2(int k);/*/
#include <stdio.h>
long pot2(int k){
	if (k==0){
		return 1;
	}
	return 2*pot2(k-1);
}
int main(){
	printf("%ld\n",pot2(10) );
	return 0;
}