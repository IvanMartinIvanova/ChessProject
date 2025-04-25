#pragma once
#include "pieza.h"
#include "peon.h"


class Tablero {
private:
    Pieza* casillas[8][8]; //tablero 8x8

public:
    Tablero(); //constructor
    ~Tablero();//destructor
    void inicializar(); //se usar� para poner las piezas en la posici�n incial, luego si queremos guardar una partida podremos modificar esta funci�n
    void mostrar(); // solo consola
    bool mover(int xIni, int yIni, int xFin, int yFin);// para mover las piezas
    void aplicarGravedad(int columna); //primer intento de gravedad
};

