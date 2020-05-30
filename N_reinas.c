/* Solución al problema N Reinas con pragmaomp */
/*Realizado por: Elda Corella Pérez*/
/* Sistemas Embebidos*/
/*Algoritmos utilizados basados en la ṕagina http://penguin.ewu.edu/~trolfe/Queens/OptQueen.html*/

#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include<time.h>

/* Global variables*/
int soluciones;
int queens;
int col2 = 1;

void solution(){
	/*Critical Section*/
	#pragma omp atomic		
    	soluciones++;
    	//printf("soluciones %d", soluciones);
}


void safe_place(int board[queens],int row,int col){
	/* check row*/	
	for (int i = 0; i < row; i++){
			if (board[i] == col) return;
			if (abs(board[i]-col) == row-i ) return;
		}
	/*queen's position*/
	board[row] = col;
	if(row == queens - col2){  
		//printf("\nSolucion %d encontrada por hilo %d",soluciones +1 ,omp_get_thread_num()); 
		/*is a solution*/
		solution();
	}
	else{
		/* if isn't a solution check */
		for(int i = 0; i<queens; i++){
			safe_place(board, row+1, i);
		}
	}
}


int main(int argc, char* argv[]){
 	
	char *p;
	int workers = 0;
	
	{
		if (argc == 2) { 
			long verifica_letra = strtol(argv[1], &p, 10); 
				/* check if the argument is a letter*/
				if(p == argv[1]){
					printf("Ingresaste un dato no numerico\n");
					printf("Por favor intenta con ./reinas [numero de reinas entre 4 y 50]\n" );
					exit (0);
				}
				else{
					sscanf(argv[1], "%d", &queens);

					/*Check value range*/
					if(queens < 4 || queens > 50){
						printf("valor fuera de rango\n");
						printf("Por favor intenta con ./reinas [numero de reinas entre 4 y 50]\n");
						exit(0);
						
					}
				}
		}
		else{
			if(argc == 1){ //Code starts with default value
				printf("No se ingresaron argumentos\n");
				printf("Inicio de programa con valor DEFAULT : REINAS = 8\n");
				queens = 8;
			}

		}
		/* creation of workers*/
		if(queens >= 4 & queens <= 14) {
			workers = 6;
		}else{
			
				workers = 12;
			}
			printf("\nNúmero de workers %d\n",workers);
		}
	
	//creation of threads
	omp_set_num_threads(workers);


	#pragma omp parallel for
	/*Parallel Region */
	for (int i = 0; i < queens; i++){

	    int board[queens];						
		safe_place(board, 0,i);
	}

	printf("\n %d soluciones encontradas para el numero de reinas: %d\n", soluciones, queens);				
	return 0;
}
