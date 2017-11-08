#include <stdio.h>

void test(int* n ){
	*n = *n + 1;
	printf(":%d\n",*n );
}
int main(){
	int x = '3' - '0';
	x=x*10;
	x = x + '8' - '0';
	printf("%d\n", x);
	return 0;
}