#include <stdio.h>
int main(){
	double t[20000];//array de temperaturas
	

	//leitura dos dados, a entrada padrao será redirecionada
	//para o arquivo temperatura.csv
	int i=0; //conta o numero de temperatudas realmente lidos
	while( scanf("%lf", &t[i]) > 0){
		i++;
	}


	//calcula o maximo, minimo e a média
	double  med=0, min=t[0], max=t[0],soma=0;
	for(int j =0;j<i;j++){
		soma += t[j];
		if (t[j] > max)
			max = t[j];
		if (t[j] < min){
			min = t[j];
		}
	}
	med = soma/i;
	printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med,min,max);
	


	/*media das temperaturas acima da media*/
	soma=0;
	int n_temp_acima_med=0;
	for (int j=0;j<i;j++){
		if (t[j]>med){
			soma +=t[j];
			n_temp_acima_med++;
		}
	}
	double med_acima_media = soma/n_temp_acima_med;
	printf("Média das temperaturas acima da média: %.3lf\n",  med_acima_media);

	


	
	return 0;

}