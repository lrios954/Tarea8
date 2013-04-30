#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pde.h"

int main(){

	FILE *u_0;
	FILE *u;
	u_0 = fopen("u_initial.dat", "w");
	u = fopen("u_now.dat", "w");
	int n_t;
	int n_x;
	double delta_x;
	double delta_t;
	double alpha;
	int i;
	int j;


	double *x;
	double *t;
	double *u_initial;
	double *u_new;
	double *u_now;


	x = malloc(n_x*sizeof(double));
	t = malloc(n_t*sizeof(double));
	u_initial = malloc(n_x*sizeof(double));
	u_new = malloc(n_x*sizeof(double));
	u_now = malloc(n_x*sizeof(double));

	delta_x = pow(10.0,-2.0);
	delta_t = pow(10.0,-5.0);
	alpha = delta_t/pow(delta_x, 2.0);

	n_t = 3*pow(10,5);
	n_x = pow(10,2);

for (i = 0; i < n_x; i ++)
	{
		x[i] = i * delta_x;
		u_initial[i] = 4.0 * x[i] * (1.0 - x[i]);
	}

	for (j = 0; j < n_t; j ++)
	{
		t[i]= j * delta_t;	
	}

	u_new[0] = 0.0;
	u_new[n_x-1] = 0.0;

	for (i = 1; i < n_x-1; i ++)
	{
		u_new[i] = alpha*u_initial[i+1] + (1.0 - 2.0 * alpha)*u_initial[i]+alpha*u_initial[i-1];
		u_now[i] = u_new[i];
	}

	int k;
	for (k = 0; k <= 10; k++)
	{
		char number[2];
		sprintf(number, "%d", k);
		FILE *export;
		export = fopen(strcat(number,".dat"), "w");
		
		for (j = 0; j < (n_t*k)/10; j ++)
		{	
			
			for (i = 1; i < n_x-1; i ++)	
			{
				u_nueva[i] = alpha*u_ahora[i+1] + (1.0 - 2.0 * alpha)*u_ahora[i]+alpha*u_ahora[i-1];
				u_ahora[i] = u_nueva[i];
			}
		}
		
		for (i = 0; i < n_x; i ++)	
		{
			fprintf(export,"%e %e \n", x[i],u_ahora[i]);
		}		
	}
}
