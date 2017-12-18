#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct s_particle particle;

struct velocity{
	double x;
	double y;
};
struct point{
	double x;
	double y;
};
struct s_particle{
	struct velocity vel;
	struct point position;
 	double mass;
	double charge;
};
double abs_velocity(struct velocity vel){
	return  sqrt(vel.x*vel.x + vel.y*vel.y);
}
void print_state(particle x){
	printf("Speed = %.2fm/s (x = %.2fm/s, y = %.2fm/s)\n",abs_velocity(x.vel), x.vel.x, x.vel.y );
	printf("Coodinates = {%.2fm,%.2fm}\n", x.position.x, x.position.y);
	printf("Gravitational Mass = %.2fkg\n", x.mass );
	printf("Eletrical Charge = %.2fC\n",x.charge );
}

int main(){
	int a=4;
	int **M = malloc(5*sizeof(int *));
	for (int i = 0; i<5; i++){
		*(M+i) = malloc(5*sizeof(int));
	}
	for (int i = 0; i<5; i++){
		for (int j = 0; j< 5; j++){
			*(*(M+i)+j) = a;
			printf("%d ", a);
		}printf("\n");
	}

	return 0;
}