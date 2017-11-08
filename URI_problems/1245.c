#include <stdio.h>
#include <stdlib.h>


int char_to_int(char c1, char c2){
	int x = c1 - '0';
	x=x*10;
	x = x + c2 - '0';
	return x;
}

int main(){
	int N;
	int sapato[2][60-30+1]; //esquerda = 1, direita = 0
	char entrada[4];
	char lado;
	int num_pares;
	int menor;
	// até e4 sapatos, sendo do pe direito ou esquerto
	//tamanhos variando de 60>=t>=30
	while (scanf("%d", &N)>0){
		//printf("leu n \n");

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < (60-30+1); ++j)
			{
				sapato[i][j] = 0;
			}
		}
		
		for (int i = 0; i < N; ++i)
		{
			//printf("lendo entrada\n");
			scanf("%s %c", entrada, &lado);

			if (lado == 'E')
				sapato[1][60-char_to_int(entrada[0], entrada[1])]++;
			else
				sapato[0][60-char_to_int(entrada[0], entrada[1])]++;
		}
		
		N = 0;
		num_pares = 0;
		for (int i = 0 ; i < (60-30+1); i++){
			menor = sapato[0][i];
			if (sapato[1][i] < menor){
				menor = sapato[1][i];
			}
			//printf("menor=%d\n",menor);
			num_pares += menor;
		}
		printf("%d\n", num_pares);



		//IMRPIME 
	/*for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < (60-30+1); ++j)
		{
			printf("%d ",sapato[i][j] );
		}
		printf("\n");
	}*/
	}


	return 0;
}