#include <stdio.h>

/*Exerc´ıcio 5. Reverter a ordem das letras de uma palavra p.
void reverter(int n, char *p);*/
char palavra[6] = "macaco";
char *c = palavra;
int N = 6;

void reverter(int n, char *p){
	if (n==N/2)
		return;
	//*(p+N-n) = *(p+n-1);
	char aux = *(p+n-1);
	 *(p+n-1) = *(p+N-n);
	*(p+N-n) = aux;
	reverter(n-1, p);

}
int main(){

	printf("%s\n", palavra);
	//printf("%c\n",*(c+6) );
	reverter(N,c);
	printf("%s\n", palavra);
	return 0;
}