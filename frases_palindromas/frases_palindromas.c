#include <stdio.h>
#include <string.h>

void remove_espacos(int frase_tamanho,char frase[frase_tamanho]){

    int i , j;

    for (i = 0; i < frase_tamanho; i++)
    {
        if (frase[i] == ' ')
        {
            j = i+1;
            
            while (frase[j] == ' ' && j < (frase_tamanho-1))
            {
                j++;
            }
            frase[i] = frase[j];
            frase[j] = ' ';
        }
    }
}

int e_palindroma(int frase_tamanho, char frase[]){
	//a frase deve ter os espaços removidos antes
    //aloca os espaços no final do array
    remove_espacos(frase_tamanho, frase);
    //encontrar no fim do array qual o indice que não é um caractere nulo ou espaço
    int indice;
    for(int i=frase_tamanho; i>0;i--){
    	if (frase[i]!= ' ' && frase[i]!='\0'){
    		indice=i;
    		break;
    	}
    }
    int i=0,j=indice;
    //percorre o array comparando 0 a n, 0 + 1 a n - 1 .. etc
    while(i!=j){
    	if(frase[i]==frase[j]){
    		i++;
    		j--;
    	}else{
    		return 0;//nao eh palindroma
    	}
    	return 1;//eh palindroma
    }
}



int main(int argc, char** argv) {
    char *frase;
    int n;
    
    if (argc >= 2) {
        frase = argv[1];
        n = strlen(frase);
        if (e_palindroma(n,frase)){
        	printf("É palindroma\n");
        }
        else{
        	printf("Não é palindroma\n");
        }



    }

    return 0;
}