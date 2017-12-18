#include <stdio.h>
int main(){
	//cria um handler para o arquivo
	FILE *file = fopen("file.txt", "w");
	
	fprintf(file, "Inteiros de 0 a 9\n");
	
	for (int i = 0; i < 10; ++i)
	{
		fprintf(file, "%d\n",i);
	}

	fclose(file);

	return 0;
}