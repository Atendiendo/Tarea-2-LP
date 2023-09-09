Miguel Huerta Flores
Rol: 202273602-k

Instrucciones:
    -Coloca los problemas a resolver en un archivo de texto,
    donde cada línea contiene una expresión matemática o un bloque de operaciones.
    -Los nombres predeterminados de los archivos para leer problemas y guardar los
    resultados son respectivamente: "problemas.txt"  "desarrollos.txt"
    -Si se desea correr este programa desde la terminal debes estar en la
    carpeta correspondiente y escribir:
    python calculadora.py problemas.txt resultados.txt

Informacion adicional:
    -Se utilizo gcc version: 11.4.0
    -Se utilizo valgrind version: 3.18.1
    -Se añadieron variables globales con el objetivo de 
    apoyar algunas funciones estas son:
    * int** tipos: matriz para conocer los tipos de cada celda del
    tablero (1 si es Tierra, 0 si es Bomba).
    * int cant_tesoros_total: Cantidad total de tesoros en el tablero.
    * int cant_tesoros: Cantidad de tesoros descubiertos por el jugador.