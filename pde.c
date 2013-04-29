#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "condiciones.h"

void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r);
void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r, int n_tiempo);



int main(){

  int n_pasos = 1000;
  
  float intervalo_tiempo = 3.0/10.0;
  float delta_x;
  float delta_t = 0.003;
  float alpha = delta_t/(delta_x*delta_x);
  
  float *u_inicial;
  float *u_pasada;
  float *u_ahora;
  float *u_nueva;

  u_inicial = malloc(n_pasos*sizeof(float));  
  u_pasada = malloc(n_pasos*sizeof(float));
  u_ahora = malloc(n_pasos*sizeof(float));
  u_nueva = malloc(n_pasos*sizeof(float));

if(!u_inicial || !u_pasada || !u_ahora || !u_nueva){
    printf("Problema con memoria");
    exit(1);
  }


//Itera sobre las condiciones iniciales (aunque creo que esta iteracion tendremos que sacarla de este archivo). Luego sobre 10 intervalos de tiempo igualmente espaciados para producir 10 graficas para cada juego de condiciones iniciales. Finalmente itera para producir las tablas de la funcion para los valores entre 0 y 1 de x.
int ind;
for (ind = 0; ind < 2; ind ++){

	condicionesIniciales(u_inicial, n_pasos,  ind, delta_x);

	int i;
	for (i = 0; i < 10; i ++){
 	
		int n_tiempo = i*intervalo_tiempo;	
		iteracionTemporal(u_inicial, u_pasada, u_ahora, u_nueva, n_pasos, alpha, n_tiempo);
	
		int temp = ind*10 + i;    
		char num[30];
		sprintf(num, "%d.dat", temp);
		FILE *export;
		export = fopen(num, "w");
		if(!export){
			printf("problem with file %s\n", num);
			exit(1);
		}
    
	   	int j;
		for(j = 0; j < n_pasos; j ++){
      
			fprintf(export,"%f\n", u_ahora[j]); //cambiamos x por u
		}
		fclose(export);

	}
              

}

}


void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float alpha){
  
int i = 0;
u_inicial[0] = 0.0;
u_inicial[n_pasos - 1] = 0.0;

//Se construye u_nueva
 for(i = 0; i < n_pasos; i ++){
   u_nueva[i] = alpha*u_inicial[i+1] + (1-2*alpha)*u_inicial[i] + alpha*u_inicial[i-1];
 }

for(i = 0; i < n_pasos; i ++){
   u_pasada[i] = u_inicial[i];
 }

for(i = 0; i < n_pasos; i ++){
  u_ahora[i] = u_nueva[i];
}

}

void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float alpha,  int n_tiempo){

  int j;
  for(j = 0; j < n_tiempo; j ++){

    iteracion(u_inicial, u_pasada, u_ahora, u_nueva,  n_pasos, alpha);

  }

}
