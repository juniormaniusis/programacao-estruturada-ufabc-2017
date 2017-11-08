/*
 Decidir se uma palavra p ´e pal´ındroma.
int eh_palindroma(int n, char *p);
*/
#include <stdio.h>
#include <string.h>
int N=5;
char palavra[5]="radar";
char *p = palavra;
int eh_palindroma(int n, char *p){

	//comparar o primeiro com o ultimo até chegar ao meio 
	//(caso base n=tamanho/2)
	//printf("comparando -%c-  e -%c- \n",*(p + N -n) , *(p+n-1) );
	if (n==N/2){
		return 1;
	}
	if (*(p + N -n) == *(p+n-1) )
	{
		eh_palindroma(n-1, p);
	}else{
		return 0;
	}
}
int main(){
	if(eh_palindroma(N,p))
		printf("PALINDROMA\n");
	else
		printf("NAO É PALINDROMA\n");
	return 0;
}