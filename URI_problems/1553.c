#include <stdio.h>
int main(){
int N,k; // numero de perguntas e frequencia min
int P[100]; // 100 >= P >= 1
int aux;
int novas_perguntas;
	do{	
		for (int i = 0; i < 100; i++){
			P[i] = 0; // zera o vetor
		}
		novas_perguntas = 0;
		scanf("%d%d", &N, &k);
		for (int i = 0; i < N; i++){
			scanf("%d", &aux);
			P[aux-1]++;
		}
		for (int i = 0; i < 100; i++){
			if(P[i] >= k ){
				novas_perguntas++;
			}
		}
		if (N!=0 && k!=0){
			printf("%d\n", novas_perguntas);
		}
	}while(N!= 0 && k!=0);
	return 0;
}