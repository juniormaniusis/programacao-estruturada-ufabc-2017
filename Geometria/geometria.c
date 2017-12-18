#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometria.h"


/*
Carlos Alberto Maniusis Junior 			RA 11081816
Henrique Matsuoka Medeiros                         11024016
*/

//////////////////////////////////////////////


double produto_interno(vetor u, vetor v){

	return v.x * u.x + v.y * u.y;

}

vetor subtrai(vetor u, vetor v){
	vetor resultado;
	resultado.x = u.x - v.x;
	resultado.y = u.y - v.y;
	return resultado;

}

void imprime( vetor v){
	printf("x=%lf y=%lf\n", v.x, v.y );
}

vetor roda90(vetor p){
	double aux=0;
	aux = p.x;
	p.x = p.y;
	p.y = aux;
	p.x*=-1;
	return p;
}

double distancia(ponto p, ponto q){
	return sqrt( (q.x - p.x)*(q.x-p.x) + (q.y - p.y)*(q.y - p.y) );
}

int sinal_do_coseno(vetor u, vetor v){
	double prod = produto_interno(u, v);
	
	if (prod == 0)
		return 0;
	else if (prod > 0)
		return 1;
	else
		return -1;
}
/* Retorna 1 se p, q e r est~ao em sentido hor´ario e -1 se for
anti-hor´ario. Se os pontos forem colineares devolva 0. */
int sentido(ponto p, ponto q, ponto r){

	double aux= ((p.x-q.x) * (r.y-q.y) - (p.y-q.y) * (r.x-q.x));
	if (aux==0)
		return 0;
	if (aux>0)
		return 1;
	if (aux<0)
		return -1;

}





int cruza(segmento s, segmento t){
			
	//if()	
	if (sentido(s.p, s.q,  t.p) != sentido(s.p, s.q,  t.q) && sentido(t.p, t.q,  s.p) != sentido(t.p, t.q,  s.q)){
		return 1;
	}

	return 0;
}

/*

int main(){
	ponto a = {0,0};
	ponto b = {1,0};
	ponto c = {0,1};
	printf("%d\n", sentido(a,b,c));
	printf("%d\n", sentido(a,c,b));
	printf("%d\n", sentido(a,a,b));
	printf("%d\n", sentido(a,a,a));
	return 0;
}
*/

















