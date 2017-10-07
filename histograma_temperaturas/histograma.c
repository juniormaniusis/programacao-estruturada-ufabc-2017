#include <stdio.h>
int main(){
	double t[20000];
	int i=0;
	printf("Iniciando a leitura..\n");
	while( scanf("%lf", &t[i]) > 0){
		//lê os dados

		//printf("t[%d]=%lf\n",i,t[i] );
		i++;
	}

	//processamento
	
	double  med=0, min=t[0], max=t[0],soma=0;
	for(int j =0;j<i;j++){
		
		soma += t[j];

		if (t[j] > max)
			max = t[j];
		if (t[j] < min){
			min = t[j];
			//printf("MINIMO=%lf\n",min);
		}




	}
	//for(int j =0;j<i;j++){printf("%lf  -  %d\n",t[j],j );}
	med = soma/i;
	printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med,min,max);
	//printf("Foram realizadas %d leituras\n",i );
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