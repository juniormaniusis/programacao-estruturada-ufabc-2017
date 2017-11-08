#include <stdio.h>


void imprimir_em_base(int n, int b){
	if (n==0){
		printf("\n");
		return;
	}
	imprimir_em_base(n/b, b);
	printf("%d", n%b );
	
}
int main(){
	int n = 4;
	int b = 2;
	imprimir_em_base(n,b);
	return 0;
}