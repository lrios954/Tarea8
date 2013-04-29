#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void condicionesIniciales(float *u_inicial, int n_pasos, int ind, float delta_x){
  //Se fijan las condiciones iniciales de la ecuacion de onda
  
if(ind == 0){
	int i = 0;
	delta_x = 0.001;
	for(i = 0; i < n_pasos; i ++){
		u_inicial[i] =  4*delta_x*i*(1-delta_x*i);
	}

  	
  	
}

else if(ind == 1){
	int i = 0;
	delta_x = 0.010;
	for(i = 0; i < n_pasos; i ++){
   		u_inicial[i] =  exp(-delta_x*i*delta_x*i);
	}

  	
  }
}
