#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void condicionesIniciales(float *u_inicial, int n_pasos, int delta_x);
void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r);
void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r, int n_tiempo);



int main(){

  FILE *datos1.txt;
  FILE *datos2.txt;
  int n_pasos = 1000;
  
  float intervalo_tiempo = 3.0/10.0;
  float delta_x = 0.001;
  float delta_t = 0.003;
  float c = 1.0;
  float r = c*delta_t/delta_x;
  
  int j = 0;

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

	condicionesIniciales(u_inicial, n_pasos, delta_x, ind);

	int i;
	for (i = 0; i < 10; i ++){
 	
	int n_tiempo = i*intervalo_tiempo;	
	iteracionTemporal(u_inicial, u_pasada, u_ahora, u_nueva, n_pasos, r, n_tiempo);
	
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
      
		fprintf(export,"%f\n" u[j]); //cambiamos x por u
	}
	fclose(export);

}
              

}


}

void iteracion(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r){
  
  int i = 0;
u_inicial[0] = 0.0;
u_inicial[n_pasos - 1] = 0.0;

//Se copia u_inicial en u_nueva
// for(i = 0; i < n_pasos; i ++){
//    u_nueva[i] = u_inicial[i];
//}


//Se construye u_nueva
 for(i = 0; i < n_pasos; i ++){
   u_nueva[i] = u_inicial[i] + ((r*r)/2.0)*(u_inicial[i+1] - 2.0*u_inicial[i] + u_inicial[i-1]);
 }

for(i = 0; i < n_pasos; i ++){
   u_pasada[i] = u_inicial[i];
 }

for(i = 0; i < n_pasos; i ++){
  u_ahora[i] = u_nueva[i];
}

}

void iteracionTemporal(float *u_inicial, float *u_pasada, float *u_ahora, float *u_nueva, int n_pasos, float r,  int n_tiempo){

  int j = 0;
  for(j = 0; j < n_tiempo; j ++){

    iteracion(u_inicial, u_pasada, u_ahora, u_nueva,  n_pasos, r);

  }

}
