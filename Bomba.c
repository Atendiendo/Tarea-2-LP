#include <stdlib.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

extern int** tipos;
extern int cant_tesoros;

void TryExplotar(int fila, int columna){
    fila -=1;
    columna -=1;
    Bomba* bomba = (Bomba*)tablero[fila][columna];
    bomba->contador_turnos -= 1;
    if (bomba->contador_turnos == 0){
        bomba->explotar(fila+1,columna+1);
    }
    return;
}

void BorrarBomba(int fila, int columna){
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
    if (bomba->tierra_debajo->vida==0 && bomba->tierra_debajo->es_tesoro==1){
        cant_tesoros +=1;
    }
    return;
}

//ME FALTA ESTA PURA WEA
void ExplosionX(int fila, int columna){
    // fila -=1;
    // columna -=1;

    // Bomba* bomba1 = (Bomba*)tablero[fila-1][columna-1];
    // bomba1->contador_turnos -=1;
    // if (bomba1->tierra_debajo->vida==0){
    //     BorrarBomba(fila+1,columna+1);
    // }
    // if (bomba1->tierra_debajo->vida==0 && bomba1->tierra_debajo->es_tesoro==1){
    //     cant_tesoros +=1;
    // }

    // Bomba* bomba2 = (Bomba*)tablero[fila+1][columna+1];
    // bomba2->contador_turnos -=1;
    // if (bomba2->tierra_debajo->vida==0){
    //     BorrarBomba(fila+1,columna+1);
    // }
    // if (bomba2->tierra_debajo->vida==0 && bomba2->tierra_debajo->es_tesoro==1){
    //     cant_tesoros +=1;
    // }

    // Bomba* bomba3 = (Bomba*)tablero[fila-1][columna+1];
    // bomba3->contador_turnos -=1;
    // if (bomba3->tierra_debajo->vida==0){
    //     BorrarBomba(fila+1,columna+1);
    // }
    // if (bomba3->tierra_debajo->vida==0 && bomba3->tierra_debajo->es_tesoro==1){
    //     cant_tesoros +=1;
    // }

    // Bomba* bomba4 = (Bomba*)tablero[fila+1][columna-1];
    // bomba4->contador_turnos -=1;
    // if (bomba4->tierra_debajo->vida==0){
    //     BorrarBomba(fila+1,columna+1);
    // }
    // if (bomba4->tierra_debajo->vida==0 && bomba4->tierra_debajo->es_tesoro==1){
    //     cant_tesoros +=1;
    // }

    // Bomba* bomba5 = (Bomba*)tablero[fila][columna];
    // bomba5->contador_turnos -=1;
    // if (bomba5->tierra_debajo->vida==0){
    //     BorrarBomba(fila+1,columna+1);
    // }
    // if (bomba5->tierra_debajo->vida==0 && bomba5->tierra_debajo->es_tesoro==1){
    //     cant_tesoros +=1;
    // }

    return;
}
