#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE  *f = fopen("file.txt", "r");
	//ler inteiro de um arquivo..
	int a=99, b=88, c=77;
	printf("Lidos com sucesso = %d\n",fscanf(f, "%d %d %d", &a, &b, &c));
	printf("%d %d %d\n", a, b, c );
	return 0;
}