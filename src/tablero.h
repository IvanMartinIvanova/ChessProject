#pragma once
#include "pieza.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include <iostream>
#include <cstdlib> // Para std::abs
#include <cmath>   // Para std::abs



class Tablero {
private:
    Pieza* casillas[8][8]; //tablero 8x8

public:
    Tablero(); //constructor
    ~Tablero();//destructor
    void inicializar(); //se usar� para poner las piezas en la posici�n incial, luego si queremos guardar una partida podremos modificar esta funci�n
    void mostrar(); // solo consola
    bool mover(int xIni, int yIni, int xFin, int yFin);// para mover las piezas
    void aplicarGravedad(); //primer intento de gravedad
    Pieza* getCasilla(int x, int y) const {
        return casillas[x][y];
    }
    void jugabilidad();
    friend class pieza;
};

