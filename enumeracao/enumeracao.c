#include <stdio.h>
#include <string.h>

char v[101];
int tamanho_palavra;
int N;




int palavra(int fim, char v[]){
	if (fim == -1){
		for (int i = 0; i < N; ++i)
		{
			printf(".");
		}
		printf("\n");
		return 0;
	}
	for (int inicio = 0; inicio <= fim; inicio++){



		for (int pos = 0; pos<N; pos++){

			if ( pos>=inicio && pos <= fim){
				
				printf("%c",v[pos] );
			
			}else{

				printf(".");

			}

		}
		printf("\n");


		//printf("   i=%d f=%d\n",inicio,fim);

	}

	palavra(fim-1,v);

	return 0;

}

int main(){

	scanf("%100s", v);
	N = strlen(v);
	palavra(N-1,v);

	return 0;

}