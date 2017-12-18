#include <stdio.h>
#include <stdlib.h>

typedef struct s_no *   no;

struct s_no {
  int item;
  no  prox;
  
};
void insere_inicio(no *inicio, no x);
void formata_zeros(no *ini);
no livres = NULL;
no novo(int item){
  if (livres != NULL){//livres = ponteiro de lista de nos livres
    no x = livres;
        x->item = item;
    livres = livres->prox;
        x->prox = NULL;
    return x;
  }
  //printf("%s\n", "Alocando espaço na memória..");
  no v = (struct s_no *) malloc(5000* sizeof(struct s_no));
  for (int i = 0; i < 5000; i++){
    
    insere_inicio(&livres, (v+i));
  }
  return novo(item);
}

// 2. (EXERCÍCIO) Deleta um nó.
//    Adaptar a função deleta para trabalhar
//    com a lista de nós livres. Como visto em sala...
void deleta(no x){
  x->prox = livres;
  livres = x;
}
void deleta_lista(no x){
	no del = x;
	while (x != NULL){
		del = x;
		x = x->prox;
		//printf("delentando o item:%d\n",del->item );
		deleta(del);
	}

}

// 3. Insere um nó no início da lista (como PUSH).
//    (Supõem que x e inicio são ambos diferentes de NULL.)
//    (Mas *inicio pode ser NULL.)
void insere_inicio(no *inicio, no x) {
  x->prox = *inicio;
  *inicio = x;
}

// 4. Remove o primeiro nó da lista.
//    (Se o valor de retorno fosse o item do nó removido,
//    essa função seria como POP.)a
void remove_inicio(no *inicio) {
  no x = *inicio;
  if (*inicio != NULL) {
    *inicio = x->prox;
    deleta(x);
  }
}

// 5. Imprime todos os elementos de uma lista
//    (supondo que sejam inteiros).
void imprime(no inicio) {
  for (no x = inicio; x != NULL; x = x->prox)
    printf("%d", x->item);
  printf("\n");
}

// 6. Busca o primeiro nó contendo item.
//    Retorna NULL se não encontrar o nó.
no busca(no inicio, int item) {
  for (; inicio != NULL && inicio->item != item;
       inicio = inicio->prox);
  return inicio;
}

// 7. Busca o primeiro nó contendo item, recursivamente.
//    Retorna NULL se não encontrar o nó.
no buscaR(no inicio, int item) {
  if (inicio == NULL)
    return NULL;
  if (inicio->item == item)
    return inicio;
  return buscaR(inicio->prox, item);
}

// 8 (EXERCÍCIO) Devolve o último nó de uma lista.
no final(no inicio){
  no x = inicio;
  while (x->prox != NULL){
    x = x->prox;
  }
  return x;
}
// 9. (EXERCÍCIO) Insere nó no final. 
//    (Supõem que x e inicio são ambos diferentes de NULL.)
//    (Mas *inicio pode ser NULL.)
void insere_final(no *inicio, no x){
  if (*inicio != NULL){ 
    final(*inicio)->prox = x;
    x->prox = NULL;
  }else{
    insere_inicio(inicio, x);
  }
}

// 10. (EXERCÍCIO) Insere nó no final, recursivamente. 
//    (Supõem que x e inicio são ambos diferentes de NULL.)
//    (Mas *inicio pode ser NULL.)
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
int num_elementos(no inicio){
  no x = inicio;
  int n = 0;
  while( x != NULL ){
    x = x->prox;
    n++;
  }
  return n;
}
int maior(int a, int b){
  if (a>b){
    return a;
  }else{
    return b;
  }
}
no soma( no num1, no num2){
  no inicio_soma = NULL;
  // obs: num1 e num2 estão de trás para frente //
  int acres = 0;
  int a, b, s;
  no x = num1;
  no y = num2;
  // x != NULL && y!= NULL
  while( x != NULL || y != NULL ){
    if (x!=NULL){
      a = x->item;
      x=x->prox;
    }else{
      a = 0;
    }
    if (y!=NULL){
      b = y->item;
      y=y->prox;
    }else{
      b = 0;
    }
    s = a + b + acres;
    if (s > 9 ){
      acres = 1;
      s = s - 10;
    }else{
      acres = 0;
    }
    insere_inicio(&inicio_soma,novo(s));
    
  }
  if (acres>0){
      insere_inicio(&inicio_soma, novo(acres));
    }
  return inicio_soma; // retorna na ordem certa (difente da entrada);
}
void inverte(no *ini) {
  no x = *ini;
  *ini = NULL;
  
  while (x != NULL) {
    no y = x->prox;
    x->prox = *ini;
    *ini = x;
    x = y;    
  }
}
void formata_zeros(no *ini){
	if ( *ini == NULL ){
		return;
	}
	while ( ((*ini)->prox != NULL) && (*ini)->item == 0){
		remove_inicio( ini );
	}
}
void remove_um(no *ini, int item) {
	if (*ini == NULL)
	return;
	no x, *prev = ini;
	for (x = (*ini); x != NULL && x->item != item;
	prev = &(x->prox), x = x->prox);
	if (x != NULL) {
	*prev = x->prox;
	deleta(x);
	}
}

void multiplica(no num1, no num2){
  no prod_temp = NULL;
  no produto = NULL;
  no res_parcial = NULL;
  int res=0;
  int acres = 0;
  int cont_zero = 0;
  //multiplicar cada digito por vez e dps somar tudo
  for (no x = num2; x!=NULL; x = x->prox){
    for (no y = num1; y != NULL;y = y->prox ){
      res = (x->item * y->item) + acres;
     // printf("%d x %d + acres(%d) = %d\n",x->item, y->item , acres, res );
      if (res > 9){
        acres = res/10;
       //printf("restou = %d\n", acres );
      }else{
        acres = 0;
      }
      res = res - acres*10;
      insere_final(&res_parcial, novo(res));
      //printf("sobe = %d\n", acres );
      //printf("fica = %d\n", res);
    }
    if (acres > 0){
    	insere_final(&res_parcial, novo(acres));
    	acres=0;
    }
    for (int i = 0; i < cont_zero; i++)
     {
      insere_inicio(&res_parcial, novo(0));
     } 
     //printf("produto parcial = ");
     //imprime(res_parcial);
     cont_zero++;
     prod_temp = produto;
    produto = soma(prod_temp, res_parcial); //soma os contrarios e devolve correto
    inverte(&produto);//inverter
    deleta_lista(res_parcial);
    res_parcial = NULL;
    deleta_lista(prod_temp);
    prod_temp = NULL;


  }
  inverte(&produto);
  formata_zeros(&produto);
  imprime(produto);
  deleta_lista(produto);
}

int main() {

	no num1 = NULL;
	no num2 = NULL;
	char operador = 0;
	char num_lido = getc(stdin); 
	//le o numero e adiciona os digitos antes do operador no num1 e depois do operador no num2
	while( num_lido != EOF ){
    if (num_lido != '\n' && num_lido != '\0'){
      if (num_lido == '*' || num_lido == '+')
        operador = num_lido;
      if (operador == 0){
        if (num_lido!= '*' && num_lido!='+')
          insere_inicio(&num1, novo(num_lido -  '0'));
      }else{
        if (num_lido!= '*' && num_lido!='+')
          insere_inicio(&num2, novo(num_lido - '0'));
      }
    }else{

      if (operador == '+'){
      	no inicio_soma = soma(num1, num2);
        imprime(inicio_soma);
        deleta_lista(inicio_soma);
      }
      if (operador == '*')
      {
        multiplica(num1, num2);  
      }
      deleta_lista(num1);
      deleta_lista(num2);
      num1 = NULL;
      num2 = NULL;
      operador = 0;

    }
    num_lido = getc(stdin);
    	
	}



 ///////////
  
}