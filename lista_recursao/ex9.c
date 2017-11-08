#include <stdio.h>
/*Exerc´ıcio 9. Dado um inteiro positivo n, calcular a soma dos d´ıgitos de n
(em base 10)*/
int soma_digitos(int n){
	if (n==0){
		return 0;
	}
	return soma_digitos(n/10) + n%10;
}

int main(){
	int num;
	scanf("%d", &num);
	printf("%d\n", soma_digitos(num));
	return 0;
}