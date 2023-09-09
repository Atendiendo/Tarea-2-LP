#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Tipo es 1 si es tierra
//Tipo es 0 si es bomba
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
    for (int i = 0; i<dimension; i++){
        for (int j = 0; j<dimension; j++){
            if (tipos[i][j]==0){
                TryExplotar(i+1,j+1);
            }
        }
    }
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
    ((Bomba*)tablero[fila][columna])->explotar=b->explotar;
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
    int eje_x,eje_y;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if (tipos[i][j]==0){
                Bomba* bomba = (Bomba*)tablero[i][j];
                printf("Turnos para explotar: %d\n",bomba->contador_turnos);
                eje_x=j+1;
                eje_y=i+1;
                printf("Coordenada: %d %d\n",eje_x,eje_y);
                //codigo dudoso
                if (bomba->explotar == ExplosionPunto){
                    printf("Forma Explosión: ExplosionPunto\n");
                } else if (bomba->explotar == ExplosionX){
                    printf("Forma Explosión: ExplosionX\n");    
                }
                printf("Vida de Tierra Debajo: %d\n\n",bomba->tierra_debajo->vida);
            }
        }
    }
    return;
}


void VerTesoros(){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if (tipos[i][j] == 1){
                Tierra* tierra = (Tierra*)tablero[i][j];
                if (tierra->es_tesoro == 1){
                    printf("*");
                } else {
                    printf("%d",tierra->vida);
                }
                
            } else {
                Bomba* bomba = (Bomba*)tablero[i][j];
                if(bomba->tierra_debajo->es_tesoro == 1){
                    printf("*");
                } else {
                    printf("o");
                }
            }

            if (j < dimension - 1) {
            printf(" | ");  // Imprimir el separador si no es la última columna
            }
            
        }
        printf("\n");
    }
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