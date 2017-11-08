#include <stdio.h>
/*Exerc´ıcio 7.
 Dado k, enumerar as potencias de 2 ate 2^k
*/
void enum_pot2(int k){
	if(k==0)
		printf("2^%d=2\n",k);
	
	
}

int main(){
	printf("%ld\n",pot2(10) );
	return 0;
}