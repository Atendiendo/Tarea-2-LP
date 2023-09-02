#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Listo
int** tipos;
void*** tablero;
int dimension;

void IniciarTablero(int n){

    int probabilidad_tesoro;
    dimension = n;
    srand(time(NULL));
    tablero = (void***)malloc(n*sizeof(void**));
    tipos = (int**)malloc(n*sizeof(int*));

    for(int i = 0; i<n; i++) {
        tablero[i] = (void**)malloc(n*sizeof(void*));
        tipos[i] = (int*)malloc(n*sizeof(int));

        for(int j = 0; j<n; j++){
            //Tipo es 1 si es tierra
            //Tipo es 0 si es bomba
            tipos[i][j] = 1;
            tablero[i][j] = (Tierra*)malloc(sizeof(Tierra));
            Tierra* tierra = (Tierra*)tablero[i][j];

            tierra->vida= rand() % 3 + 1;
            probabilidad_tesoro = rand() % 100 + 1;
            if (probabilidad_tesoro >=1 && probabilidad_tesoro <= 5){
                tierra->es_tesoro = 1;
            } else {
                tierra->es_tesoro = 0;
            }
        }
    }
    return;
}


void PasarTurno(){
    // Su codigo
    return;
}


void ColocarBomba(Bomba* b, int fila, int columna){
    fila -=1;
    columna -=1;
    tipos[fila][columna] = 0;
    b->tierra_debajo = (Tierra*)tablero[fila][columna];
    tablero[fila][columna] = (Bomba*)malloc(sizeof(Bomba));
    ((Bomba*)tablero[fila][columna])->contador_turnos= b->contador_turnos;
    ((Bomba*)tablero[fila][columna])->tierra_debajo= b->tierra_debajo;
    return;
}


void MostrarTablero(){
    // Su codigo
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if (tipos[i][j] == 1){
                Tierra* tierra = (Tierra*)tablero[i][j];
                if (tierra->vida == 0 && tierra->es_tesoro == 1){
                    printf("*");
                } else {
                    printf("%d",tierra->vida);
                }
                
            } else {
                printf("o");
            }

            if (j < dimension - 1) {
            printf(" | ");  // Imprimir el separador si no es la última columna
            }
            
        }
        printf("\n");
    }
    return;
}


void MostrarBombas(){
    // Su codigo
    return;
}


void VerTesoros(){
    // Su codigo
    return;
}

//Listo
void BorrarTablero(){
    // Su codigo
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (tipos[i][j] == 0){
                free(((Bomba*)tablero[i][j])->tierra_debajo);
            }
            free(tablero[i][j]);
        }
        free(tipos[i]);
        free(tablero[i]);
    }
    free(tipos);
    free(tablero);
    return;
}