#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include<time.h>

int soluciones;
int reinas;
int col2 = 1;

void safe_place(int tablero[reinas],int row,int col){

	for (int i = 0; i < row; i++){
			if (tablero[i] == col) return;
			if (abs(tablero[i]-col) == row-i )return;
		}

	tablero[row] = col;
	if(row == reinas - col2){   
		if(soluciones == col2){
			printf("aqui");
	}
		else{
		printf("\nSolucion %d encontrada por hilo %d",soluciones +1 ,omp_get_thread_num()); 
	}
	
	#pragma omp atomic		
    	soluciones++;
	}
	else{
		for(int i = 0; i<reinas; i++)
			safe_place(tablero, row+1, i);
	}
}



int main(int argc, char* argv[]){
 	
	char *p;
	int workers = 0;
	
	{
		if (argc == 2) { //SI SE INGRESO UN VALOR DE REINAS, REALIZAR VALIDACIONES
			long verifica_letra = strtol(argv[1], &p, 10); 
				if(p == argv[1]){
					printf("Ingresaste un dato no numerico\n");
					printf("Por favor intenga con ./reinas [numero de reinas entre 4 y 50]\n" );
					exit (0);
				}
				else{
					sscanf(argv[1], "%d", &reinas);
					if(reinas < 4 || reinas > 50){
						printf("valor fuera de rango\n");
						printf("Por favor intenga con ./reinas [numero de reinas entre 4 y 50]\n");
						exit(0);
						
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

		/******Creacion de workers*/
		
		
	}
	
	//Creacion de hilos 
	omp_set_num_threads(4);
	#pragma omp parallel for
	/* Region paralela*/

	for (int i = 0; i < reinas; i++){
	    int tablero[reinas];						
		safe_place(tablero, 0,i);
	}

	printf("\n %d soluciones encontradas para el numero de reinas: %d\n", soluciones, reinas);				
	return 0;
}