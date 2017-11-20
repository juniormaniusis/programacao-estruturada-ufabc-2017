#include <stdio.h>

int main(int argc, char const *argv[])
{
	int *a = NULL;
	int b = 666;
	a = &b;
	printf("%d\n", *a);
	return 0;
}