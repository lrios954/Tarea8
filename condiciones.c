#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void condicionesIniciales(float *u_inicial, int n_pasos, int delta_x, int ind){
  //Se fijan las condiciones iniciales de la ecuacion de onda
  
if(ind == 0){
	int i = 0;
	for(i = 0; i < n_pasos; i ++){
		u_inicial[i] =  4*delta_x*i*(1-delta_x*i);
	}

}

else if(ind == 1){
	int i = 0;
	for(i = 0; i < n_pasos; i ++){
   		u_inicial[i] =  exp(-delta_x*i*delta_x*i);
	}
}
}
