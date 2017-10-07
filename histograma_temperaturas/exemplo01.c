#include <stdio.h>

#define N 20000

int main() {
  int n = 0;
  double t[N], med, min = 100, max = -100, soma = 0;;

  while(n < N && scanf("%lf", &t[n]) > 0) {
    /* escreva parte de seu código aqui */
    n++;
  }
  
  med = soma / n;

  printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med, min, max);
  
  /* escreva a maior parte de seu código aqui */
  
  return 0;
}
