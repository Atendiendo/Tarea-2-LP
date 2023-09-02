#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

int main(int argc, char const *argv[]) {
    int tamaño_tablero;

    printf("¡Bienvenido a TreasureFinder!\n");
    printf("Indique el tamaño del tablero a jugar:\n");

    printf("1.7x7  2.10x10  3.12x12\n");
    printf("Su input: ");
    scanf("%d",&tamaño_tablero);


    switch (tamaño_tablero) {
    case 1:
        tamaño_tablero = 7;
        break;
    case 2:
        tamaño_tablero = 10;
        break;
    case 3:
        tamaño_tablero = 12;
        break;
    
    default:
    printf("Valor invalido\n");
        break;
    }

    IniciarTablero(tamaño_tablero);

    printf("\nEmpezando juego... ¡listo!\n");
    bool programa_en_curso = true;
    int turno = 1,accion = 0, fila, columna, tipo_bomba;
    while(programa_en_curso){
        printf("Tablero (Turno %d)\n",turno);
        MostrarTablero();

        
        printf("Seleccione una accion:\n");
        printf("1.Colocar Bomba  2.Mostrar Bombas  3.Mostrar Tesoros  4.Borrar bomba  5.Cerrar juego\n");
        printf("Escoja una opcion: ");
        scanf("%d",&accion);
        printf("\n");
        switch (accion) {
        case 1:
            /*
            Debo crear la bomba y insertarla y borrarla
            */
           printf("Indique coordenadas de la bomba\n");
           printf("Fila: ");
           scanf("%d",&fila);
           printf("\nColumna: ");
           scanf("%d",&columna);
           printf("\nIndique forma en que explota la bomba\n");
           printf("1.Punto  2.X\n");
           printf("Su input: ");
           scanf("%d",&tipo_bomba);
           printf("\n");
           switch (tipo_bomba) {
           case 1:
            Bomba bomba_punto;
            bomba_punto.contador_turnos = 1;
            ColocarBomba(&bomba_punto,fila,columna);
            break;
           case 2:
            Bomba bomba_cruz;
            bomba_cruz.contador_turnos = 3;
            ColocarBomba(&bomba_cruz,fila,columna);
            break;
           }

           
            break;
        case 2:
            /*
            Falta MostrarBombas
            */
            break;
        case 3:
            /*
            Falta MostrarTesoros
            */
            break;
        
        case 4:
            printf("Indique coordenadas de la bomba\n");
            printf("Fila: ");
            scanf("%d",&fila);
            printf("\nColumna: ");
            scanf("%d",&columna);
            printf("\n");
            BorrarBomba(fila,columna);

            break;
        case 5:
            programa_en_curso = false;
            break;
        }


    }
    BorrarTablero();

    // IniciarTablero(7);
    // MostrarTablero();
    // BorrarTablero();
    return 0;
}

/* EJEMPLOS DE RANDOM PARA FACILITAR SU USO.
*
*   srand(time(0)); // Setea la seed del random.
*   int ejemplo_vida = (rand() % 3) + 1; // Obtiene al azar la vida de Tierra a asignar.
*/

/*
    Valgrind:
    gcc -g -o nombreprograma arch1.c arch2.c -Wall
    valgrind --leak-check=yes ./nombreprograma
    o --leak-check=full
*/