#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "condicionesIniciales.h"

int main(){



	FILE *u_1i;
	FILE *u_1a;
	FILE *u_2i;
	FILE *u_2a;
	u_1i = fopen("inicial1.dat", "w");
	u_1a = fopen("ahora1.dat", "w");
	u_2i = fopen("inicial2.dat", "w");
	u_2a = fopen("ahora2.dat", "w");

  int n_pasos = 1000;
  
  float intervalo_tiempo = 3.0/10.0;
  float delta_x;
  float delta_t = 0.003;
  float alpha = delta_t/(delta_x*delta_x);
  
  float *u_inicial;
  float *u_pasada;
  float *u_ahora;
  float *u_nueva;
  double *x;
  double *t;

int n_t=3E5;
int n_x=100;

int i;
int j;

  u_inicial = malloc(n_pasos*sizeof(float));  
  u_pasada = malloc(n_pasos*sizeof(float));
  u_ahora = malloc(n_pasos*sizeof(float));
  u_nueva = malloc(n_pasos*sizeof(float));
  x=malloc(n_pasos*sizeof(double));
  t=malloc(n_pasos*sizeof(double));


if(!u_inicial || !u_pasada || !u_ahora || !u_nueva){
    printf("Problema con memoria");
    exit(1);
  }
int ind;
for (ind = 0; j < 2; ind ++)
	{

void condicionesIniciales(float *u_inicial, int n_x, int ind, float delta_x);

	for (j = 0; j < n_t; j ++)
	{
		t[i]= j * delta_t;	
	}

	u_nueva[0] = 0.0;
	u_nueva[n_x-1] = 0.0;

	for (i = 1; i < n_x-1; i ++)
	{
		u_nueva[i] = alpha*u_inicial[i+1] + (1.0 - 2.0 * alpha)*u_inicial[i]+alpha*u_inicial[i-1];
		u_ahora[i] = u_nueva[i];
	}

	for (j = 0; j < n_t/10; j ++)
	{	
		for (i = 1; i < n_x-1; i ++)	
		{
			u_nueva[i] = alpha*u_ahora[i+1] + (1.0 - 2.0 * alpha)*u_ahora[i]+alpha*u_ahora[i-1];
			u_ahora[i] = u_nueva[i];
		}
		printf("t = %d \n",j);
	}
if(ind==0)
{
		for (i = 0; i < n_x; i ++)
	{
		fprintf(u_1i,"%e %e \n", x[i],u_inicial[i]);
		fprintf(u_1a,"%e %e \n", x[i],u_ahora[i]);
	}
}
if(ind==1)
{
		for (i = 0; i < n_x; i ++)
	{
		fprintf(u_2i,"%e %e \n", x[i],u_inicial[i]);
		fprintf(u_2a,"%e %e \n", x[i],u_ahora[i]);
	}
}

	}

}
