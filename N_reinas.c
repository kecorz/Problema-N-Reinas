#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>


int soluciones;
int reinas;



int main(int argc, char * argv[]){

	char *p;
	

	if (argc == 2) { //SI SE INGRESO UN VALOR DE REINAS, REALIZAR VALIDACIONES
		long a1= strtol(argv[1], &p, 10); 
			if(p == argv[1]){
				fprintf(stderr, "Ingresaste un dato no numerico\n");
				exit (0);
			}
			else{
				sscanf(argv[1], "%d", &reinas);
				if(reinas < 4 || reinas > 50){
					printf("valor fuera de rango");
				}
			}
	}
	else{
		if(argc == 1){ //SE INGRESO UN DATO Y SE INICIA CON VALOR d DEFAULT
			printf("No se ingresaron argumentos\n");
			printf("Inicio de programa con valor DEFAULT : REINAS = 8\n");
			reinas = 8;
		}

	}


	printf("NUmero de reinas: %d",reinas);
	
	return 0;
}