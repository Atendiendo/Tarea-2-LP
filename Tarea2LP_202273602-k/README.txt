Miguel Huerta Flores
Rol: 202273602-k

Instrucciones:
    -Para compilar se debe usar en consola:
    make programa
    -Para borrar los archivos generados:
    make clean
    -Para correr el programa:
    ./programa
    -Para correr el programa con valgrind:
    valgrind --leak-check=full --show-leak-kinds=all ./programa

Informacion adicional:
    -No se implemento ExplosionX
    -No se implemento casos en que la bomba explota afuera de la matriz
    -Se puede terminar el programa abruptamente (opcion 4), borrando todo lo del heap.
    -Se utilizo gcc version: 11.4.0
    -Se utilizo valgrind version: 3.18.1
    -Se añadieron variables globales con el objetivo de 
    apoyar algunas funciones estas son:
    * int** tipos: matriz para conocer los tipos de cada celda del
    tablero (1 si es Tierra, 0 si es Bomba).
    * int cant_tesoros_total: Cantidad total de tesoros en el tablero.
    * int cant_tesoros: Cantidad de tesoros descubiertos por el jugador.