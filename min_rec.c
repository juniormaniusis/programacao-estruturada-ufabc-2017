#include <stdio.h>

int M(int v[], int n){

	if (n==1)
		return v[0];
	else {
		int x;
		x = M(v, n-1);
		if (x <= v[n-1])
			return x;
		else
			return v[n-1];
	}
}

int main(){
	int v[5] = {1,2,-1,3,5};
	printf("%d\n", M(v,5) );
}