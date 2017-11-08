#include <stdio.h>

int fib(int n, int* ptr){
	*ptr = *ptr + 1;
	if (n == 1){
		return 1;
	}
	
	if (n == 0){
		return 0;
	}

	return fib(n-1, ptr) + fib(n-2, ptr);


}

int main(){
	int chamadas = -1;
	int N, num;
	int* ptr = &chamadas;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		printf("fib(%d) = %d calls = %d\n",num, chamadas,fib(num, ptr) );
		chamadas = -1;
	}
}