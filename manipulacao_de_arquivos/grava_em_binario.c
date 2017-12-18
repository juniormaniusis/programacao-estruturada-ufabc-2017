#include <stdio.h>
#include <stdlib.h>
	
typedef struct s_numero numComplexo;
struct s_numero
{
	double real;
	double imag;
};

int main(int argc, char const *argv[])
{
	numComplexo a[3];
	a[0].real = 1;
	a[0].imag = 99.66;
	a[1].real = 2;
	a[2].real = 3;
	printf("%f\n", a[0].real*a[2].real*a[1].real);
	FILE *f = fopen("file.txt", "wb");
	fwrite(&a, sizeof(numComplexo), 3, f);
	fclose(f);
	FILE *g = fopen("file.txt", "rb");
	numComplexo k[3];
	fread(k, sizeof(numComplexo), 4, g);
	for (int i = 0; i < 3; ++i)
	{
		printf("a[%d].real = %f\n",i, k[i].real );
		printf("a[0].imag = %f\n", k[i].imag);
	}
	fclose(g);
	return 0;
};