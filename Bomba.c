#include <stdlib.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

extern int** tipos;

void TryExplotar(int fila, int columna){
    // Su codigo
    return;
}

void BorrarBomba(int fila, int columna){
    // Su codigo
    fila -=1;
    columna -=1;
    tipos[fila][columna] = 1;
    Tierra* temp;
    temp = ((Bomba*)tablero[fila][columna])->tierra_debajo;
    free(tablero[fila][columna]);
    tablero[fila][columna] = temp;
    return;
}

void ExplosionPunto(int fila, int columna){
    // Su codigo
    return;
}

void ExplosionX(int fila, int columna){
    // Su codigo
    return;
}
