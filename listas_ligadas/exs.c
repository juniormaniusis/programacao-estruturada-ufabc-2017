#include <stdio.h>
#include <stdlib.h>

typedef struct s_no * no;

struct s_no {
	int item;
	no prox;
};

//1. Cria um novo nó da lista.
no novo(int item){
	no x = (no) malloc(sizeof(struct s_no));
	// retorna o endereço do primeiro byte de um novo nó
	if (x == NULL){
		fprintf(stderr, "%s\n", "Memória Insulficiente.");
		exit(1);
	}

	x->item = item;
	x->prox = NULL;
	return x;
}
//2. Deleta um nó.
void deleta(no x){
	free(x);
}
// 3. Insere um no no inicio da lista (como PUSH).
// (Supoem que x e inicio sao ambos diferentes de NULL.)
// (Mas *inicio pode ser NULL.)
void insere_inicio(no *inicio, no x){
	x->prox = *inicio;
	*inicio = x;
}
// 4. Remove o primeiro no da lista.
// (Se o valor de retorno fosse o item do no removido,
// essa funcao seria como POP.)
void remove_inicio(no *inicio){
	if (*inicio != NULL){
		no x = *inicio;
		*inicio = x->prox;
		deleta(x);
	}
}

// 5. Imprime todos os elementos de uma lista
// (supondo que sejam inteiros).
void imprime(no inicio){
	no x = inicio;
	while(x != NULL){
		printf("%d ", x->item);
		//printf("%p ", x);
		x = x->prox;
	}
	printf("\n");

}


// 6. Busca o primeiro no contendo item.
// Retorna NULL se nao encontrar o no.
no busca(no inicio, int item) {
	no i = inicio;
	while(i != NULL){
		if ((*i).item == item)
			return i;
		i = (*i).prox ;

	}
	return NULL;

}

no buscaR(no inicio, int item){
	if (inicio == NULL)
		return NULL;
	if (inicio->item == item)
		return inicio;
	return buscaR(inicio->prox, item);

}
// 8 (EXERCICIO) Devolve o ultimo no de uma lista. 
no final(no inicio){
	no x = inicio;
	while (x->prox != NULL){
		x = x->prox;
	}
	return x;
}
// 9. (EXERCICIO) Insere no no final. 
// (Sup~oem que x e inicio sao ambos diferentes de NULL.)
// (Mas *inicio pode ser NULL.)
void insere_final(no *inicio, no x){
	if (*inicio != NULL){ 
		final(*inicio)->prox = x;
		x->prox = NULL;
	}else{
		insere_inicio(inicio, x);
	}
}

// 10. (EXERCÍCIO) Insere nó no final, recursivamente.
//(Supoem que x e inicio sao ambos diferentes de NULL.)
//(Mas *inicio pode ser NULL.)
void insere_finalR(no *inicio, no x){

	if (*inicio == NULL){
		*inicio = x;
		x->prox = NULL;
		return;
	}
	if ( (*inicio)->prox == NULL)
	{
		(*inicio)->prox = x;
		x->prox = NULL;
		return;
	}
	else
	{
		insere_finalR(&(*inicio)->prox, x);
	}
	
}
// 14. (EXERCÍCIO) Cria uma cópia da lista dada
//     (copiar em outras posições de memória, é claro).
no copia(no inicio){
	if (inicio == NULL)
		return NULL;

	no novo_inicio = novo(inicio->item);
	no x = inicio->prox;
	while( x != NULL){
		insere_final(&novo_inicio, novo(x->item));
		x = x->prox;
	}
	return novo_inicio;
}

int main(){
	no inicio = NULL;
	printf("%s\n", "chegou aqui");
	insere_inicio(&inicio, novo(77));
	insere_finalR(&inicio, novo(4));
	imprime(inicio);
	imprime(copia(inicio));

}