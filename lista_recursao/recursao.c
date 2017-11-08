int soma(int n){
	if (n == 0)
		return 0;
	return n + soma(n -1);
}

int soma(int n, int *v){

	n--;
	
	if (n < 0)
		return 0;

	return v[n] + soma(n, v);

}

int min(int n, int *v){
	 //int min;
	 //a b c d e
	 if (n == 1)
	 	return v[n-1];

	 if (v[n-1] < min(n-1, v) ){

	 	return v[n-1];
	 }else{
	 	return min(n-1, v);

	 }

}

int eh_palindroma(int n, char *p){

	//comparar o primeiro com o ultimo até chegar ao meio 
	//(caso base n=tamanho/2)
	//printf("comparando -%c-  e -%c- \n",*(p + N -n) , *(p+n-1) );
	if (n==N/2){ //N = tamnho da string 
		return 1;
	}
	if (*(p + N -n) == *(p+n-1) )
	{
		eh_palindroma(n-1, p);
	}else{
		return 0;
	}
}

void reverter(int n, char *p){
	if (n==N/2)
		return;
	//*(p+N-n) = *(p+n-1);
	char aux = *(p+n-1);
	 *(p+n-1) = *(p+N-n);
	*(p+N-n) = aux;
	reverter(n-1, p);

}

long pot2(int k){
	if (k==0){
		return 1;
	}
	return 2*pot2(k-1);
}


void enum_pot2(int k){
	if(k==0)
		printf("2^%d=2\n",k);
	
	
}

void imprimir_em_base(int n, int b){
	if (n==0){
		printf("\n");
		return;
	}
	imprimir_em_base(n/b, b);
	printf("%d", n%b );
	
}

int soma_digitos(int n){
	if (n==0){
		return 0;
	}
	return soma_digitos(n/10) + n%10;
}




