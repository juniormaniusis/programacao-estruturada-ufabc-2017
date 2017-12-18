#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;
no livres = NULL;

struct s_no{
	int item;
	no ant;
	no prox;
};
//variavel que controla a lista de nós livres..

void insere_inicio(no *ini, no x){
	x->ant = NULL;
	x->prox = *ini;
	if (*ini != NULL){
		(*ini)->ant = x;
	}
	*ini = x;
	return;
}
no novo(int item){
	if (livres == NULL){
		//se não há novos nós, alocar mais
		no mem = (no) malloc(sizeof(struct s_no)*5);
		fprintf(stderr, "Alocando memória..\n");
		fflush(stderr);
		if (mem == NULL){
			fprintf(stderr, "%s\n", "Memória insulficiente");
			fflush(stderr);
			exit(1);
		}
		//aloca um grande bloco na memoria
		//transforma os blocos em uma lista de nós livres
		//mem.type = no, mem + i = no tbm
		
		for (int i = 0; i < 5; i++)
		{
			insere_inicio(&livres, (mem+i));
		}
		return novo(item);
	}else{
		no x = livres;
		livres = x->prox;
		x->item = item;
		x->prox = NULL;
		x->ant = NULL;
		return x;
	}
	return NULL;

}
void imprime(no inicio){
	if (inicio == NULL)
		printf("NULL");
	no x = inicio;
	while (x != NULL){
		printf("%d ",x->item );
		x = x->prox;
	}
	printf("\n");
	return;
}
void imprime2(no ultimo){
	if ( ultimo == NULL ){
		printf("NULL");
	}
	no x = ultimo;
	for (; x != NULL; x = x->ant){
		printf("%d ",x->item );
	}
	printf("\n");
}
void deleta(no x){
	(*x).ant= NULL;// x = ponteiro para estrutura s_no
	x->prox = livres;
	livres = x;
	return;
}
no final(no inicio){
	if (inicio == NULL){
		return NULL;
	}
	no x = inicio;
	for (; x->prox != NULL; x = x->prox);
	return x;
}
void insere_final(no *ini, no x){
 	if (*ini == NULL){
 		*ini = x;
 		return;
 	}
	 no fin = final(*ini);
	 fin->prox = x;
	 x->ant = fin;
	 return;
}

void remove_inicio(no *ini){
	if (*ini == NULL)
		return;
	no x = *ini;
	*ini = (*ini)->prox;
	deleta(x);
}
void carrega_lista_de_arquivo(no *ini){
	FILE *f = fopen("lista.txt", "r");
	if (f == NULL){
		fprintf(stderr,"Erro ao manipular arquivo..\n");
		fflush(stderr);
		exit(1);
		return;
	}
	int item = 0;
	while( fscanf(f, "%d", &item) > 0){
		insere_final(ini, novo(item));
	}
	fclose(f);
	return;
}
int tamanho_lista(no inicio){
	no x = inicio;
	int tamanho = 0;
	while ( x != NULL ){
		x = x->prox;
		tamanho++;
	}
	return tamanho;
}
void grava_lista_em_arquivo(no inicio){
	FILE *f = fopen("lista.txt", "w");
	if (f == NULL){
		printf("ERRO  AO MANIPULAR ARQUIVO\n");
		exit(1);
	}
	no x = inicio;
	for (; x != NULL; x = x->prox)
	{
		fprintf(f, "%d\n", x->item);
	}
	fclose(f);
}
void deleta_lista(no *ini){
	no del = *ini;
	while (*ini != NULL){
		del = *ini;
		*ini = del->prox;
		deleta(del);
	}
}
no busca(no inicio, int valor){
	no x = inicio;
	for(; x!=NULL && x->item != valor; x = x->prox);
	return x;
}
void deleta_um(no *ini, int item){
	no x = busca(*ini, item);
	if (x == NULL)
		return;
	if (x->prox == NULL && x->ant == NULL){
		*ini = x->prox;
		deleta(x);
		return;
	}
	if (x->prox == NULL){
		x->ant->prox = NULL;
		deleta(x);
		return;
	}

	if (x->ant == NULL){
		*ini = x->prox;
		x->prox->ant = x->ant;
		deleta(x);
		return;
	}



	x->ant->prox = x->prox;
	x->prox->ant = x->ant;
	deleta(x);
	return;
}

void deleta_todos(no *ini, int item){
	no x = *ini;
	no del = NULL;
	while( x != NULL ){
		if (x->item == item){
			if (x->ant == NULL && x->prox == NULL){
				*ini = NULL;
				del = x;
			}else if (x->ant == NULL){
				*ini = x->prox;
				x->prox->ant = NULL;
				del = x;
				
			}else if (x->prox == NULL){
				x->ant->prox = NULL;
				del = x;
				
			}else{
				x->ant->prox = x->prox;
				x->prox->ant = x->ant;
				del = x;
				
			}
		}
		x = x->prox;
		if (del != NULL){
			deleta(del);
			del = NULL;
		}
	}
}
void inverte(no *ini){
	no x = *ini;
	no ant = NULL;
	no prox = NULL;
	
	while ( x != NULL){
		ant = x->ant;
		prox = x->prox;
		x->prox = ant;
		x->ant = prox;
		*ini = x;
		x = x->ant;
	}
	
}
void inverteR2( no *ini){
	if ( (*ini) == NULL ){
		return;
	}
	inverteR2(&(*ini)->prox);
	no prox = (*ini)->prox;
	no ant = (*ini)->ant;

	(*ini)->prox = ant;
	(*ini)->ant = prox;
	
	return;
}
int main(){
	no inicio = NULL;
	carrega_lista_de_arquivo(&inicio);
	imprime(inicio);
	imprime(livres);
	inverteR2(&inicio);
	imprime(inicio);
	imprime(livres);
	return 0;
}