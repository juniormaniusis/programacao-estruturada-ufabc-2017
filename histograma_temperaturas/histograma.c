#include <stdio.h>
int main(){
	double t[20000];//array de temperaturas
	

	//leitura dos dados, a entrada padrao será redirecionada
	//para o arquivo temperatura.csv
	int n=0; //conta o numero de temperatudas realmente lidos
	while( scanf("%lf", &t[n]) > 0){
		n++;
	}

	//calcula o maximo, minimo e a média
	double  med = 0, min = t[0], max = t[0], soma = 0;
	for(int j = 0; j < n; j++){
		soma += t[j];
		if (t[j] > max)
			max = t[j];
		if (t[j] < min){
			min = t[j];
		}
	}
	med = soma/n;
	printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med,min,max);
	


	/*media das temperaturas acima da media*/
	soma=0;
	int n_temp_acima_med=0;
	for (int j = 0;j < n; j++){
		if (t[j]>med){
			soma +=t[j];
			n_temp_acima_med++;
		}
	}
	double med_acima_media = soma/n_temp_acima_med;
	printf("Média das temperaturas acima da média: %.3lf\n",  med_acima_media);

	double intervalo[20] = {0.0};

	/*
	intervalo = [min,max]
	n(x) = a + bx
	n(0) = min  => a = min
	n(20) = max => max = min + 20*b => b = (max-min)/20
	n(x) = min + x*W(max-min)/20
	*/

	for (int x=0;x<=20;x++){
		intervalo[x] = min + x*(max-min)/20;
		}

	//conta as ocorrencias das temperaturas em seus respectivos intervalos

	int aux[20] = {0};

	for (int i = 0; i <= n; i++){
		for (int j = 0; j < 20; j++){
			if (t[i] >= intervalo[j] && t[i] < intervalo[j+1]){
				aux[j]++;
			}
		}
	}


	//imprime o vetor auxiliar
	for (int x = 0; x < 20; x++)
	{
		printf("aux[%d]=%d\n",x,aux[x] );
	}

	
	//histograma das temperaturas na horizontal
/*
	for (int i = 0; i < 20; i++){
		printf("Temperaturas entre %6.3lf e %6.3lf: ",
		 intervalo[i], intervalo[i+1] );
		int j = 0;
		while(j <= aux[i] / 122){
			printf("*");
			j++;
		}
		printf("\n");
	}
*/

	char histograma[20][20];

	
	//inicializa o histograma com espaços vazios
	for(int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++)
		{
			histograma[i][j] = ' ';
		}
	}

	
	//preenche o histograma
	for (int i = 0; i < 20; i++){
		int j = 0;

		while(j <= aux[i] / 122){
			histograma[i][j] = '*';
			j++;
		}
	}
	
	//imprime o histograma na horizontal
	for (int i = 0; i < 20; i++)
	{
		printf("Temperaturas entre %6.3lf e %6.3lf: ",
		intervalo[i], intervalo[i+1] );
		for(int j = 0; j < 20; j++)
		{
			printf("%c",histograma[i][j] );
		}
		printf("\n");
	}


	printf("Histograma na vertical:\n");
	for (int lin = 19; lin >=0 ; lin--)
	{
		for(int col=0; col<20; col++){
			printf("%c", histograma[col][lin] );
		}
		printf("\n");
	}
	return 0;

}