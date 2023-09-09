#include <stdlib.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

extern int** tipos;

void TryExplotar(int fila, int columna){
    fila -=1;
    columna -=1;
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    bomba->contador_turnos -= 1;
    if (bomba->contador_turnos == 0){
        bomba->explotar(fila,columna);
    }
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
    fila -=1;
    columna -=1;
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    bomba->tierra_debajo->vida = bomba->tierra_debajo->vida -3;
    if (bomba->tierra_debajo->vida<0){
        bomba->tierra_debajo->vida = 0;
    }
    if (bomba->tierra_debajo->vida==0){
        BorrarBomba(fila+1,columna+1);
    }
    return;
}

void ExplosionX(int fila, int columna){
    fila -=1;
    columna -=1;
    Bomba* bomba = (Bomba*)tablero[fila][columna];

    return;
}
