#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void proximo_sequencia(char* sequencia, char* resultado){
	int lendo = sequencia[0];
	int i = 0;
	int cont=0;
	int pos=0;
	while(i<100){
		if (lendo == sequencia[i]){
			cont++;
		}else{
			resultado[pos] = cont + '0';
			resultado[pos+1] = lendo;
			pos=pos+2;
			lendo = sequencia[i];
			cont = 1;
		}
		i++;
	}

	
}
void limpa(char *v, int n){
	for (int i = 0; i < n; ++i)
	{
		*(v+i) = 0;
	}
}

int main(){
	//char sequencia[100] = {0};
	//scanf("%s", sequencia);
	//char resultado[100] = {0};
	char* seq = (char *) malloc(100*sizeof(char));
	char* res = (char *) malloc(100*sizeof(char));
	int N;
	int control=1;
	while(scanf("%d", &N)>0){
		if (N!=0){
		limpa(seq,100);
		limpa(res,100);
		*seq=3;
		control=1;
		
		for (int i = 0; i < N; ++i)
		{
		
			if (control>0)
			{
				proximo_sequencia(seq, res);
			}else{
				proximo_sequencia(res, seq);
			}

			control=control*-1;
		}
		if (control == 1){
			for (int i = 0; i < 100; i++)
			{
				if (*(res+i)!=0)
					printf("%c", *(res+i));
			}
		}else{
			for (int i = 0; i < 100; i++)
			{
				if (*(seq+i)!=0)
					printf("%c", *(seq+i));
			}
		}
		printf("3\n");
	}
}
	return 0;
}
