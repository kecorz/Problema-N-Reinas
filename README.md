**************************** Problema de las N-Reinas ********************

El problema de las n reinas consiste en encontrar una distrubción de n reinas en un tablero de ajedrez de n × n
de tal modo que éstas no se ataquen.

Se considera que una reina ataca a otra si:
	* Ambas reinas están en la misma fila.
	* Ambas reinas están en la misma columna.
	* Ambas reinas se encuentran en la misma diagonal formada por cuadros del mismo color (negros o blancos).


El programa calcula la solución al problema de las N-Reinas. Imprime de cuántas formas es posible posicionar N reinas en un tablero de ajedrez de NxN sin que ninguna de ellas se ataquen entre sí. Se adapta dinámicamente al número de Reinas que se ingresen por consola.

********* Ejecución******

El programa se compila de la siguiente manera y en este orden:

gcc -fopenmp -o reinas N_reinas.c

Y se ejecuta de la siguiente manera:

./reinas [numero de reinas del 4 al 50]

******************

Autor: Corella Pérez Elda

Consulta de algoritmos de las siguientes páginas:

* http://penguin.ewu.edu/~trolfe/Queens/OptQueen.html
* https://elvex.ugr.es/decsai/c/problemas/reinas/reinas2.c
