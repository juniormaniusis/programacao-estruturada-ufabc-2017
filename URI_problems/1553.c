#include <stdio.h>
int ocorrencia[100];
int frequencia_corte;
int n_perguntas;
int pergunta;
int perguntas_adicionadas;
int main(){

	do{
		//laço que repete até n==k==0
		scanf("%d %d", &n_perguntas, &frequencia_corte);
				//zera ocorrencias
		for (int i = 0; i < 100; ++i)
		{
			ocorrencia[i] = 0;
		}
		for(int i = 0; i < n_perguntas; i++ ){
			//le e coloca a pergunta no vetor que 
			//conta as ocorrencias das perguntas

			scanf("%d", &pergunta);
			ocorrencia[pergunta]++;
		}
		

		


		//calcula as ocorrecias
		perguntas_adicionadas=0;
		for (int i = 0; i < n_perguntas; i++)
		{

			if(ocorrencia[i]>=frequencia_corte){
				perguntas_adicionadas++;
			}
		}

		if (n_perguntas>0 && frequencia_corte>0)
		{
			printf("%d\n", perguntas_adicionadas );
		}


	}while(n_perguntas!=0 || frequencia_corte!=0);

	return 0;
}