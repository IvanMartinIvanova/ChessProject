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



class tablero {
private:
    pieza* casillas[8][8]; //tablero 8x8

public:
    tablero(); //constructor
    ~tablero();//destructor
    void inicializar(); //se usará para poner las piezas en la posición incial, luego si queremos guardar una partida podremos modificar esta función
    void mostrar(); // solo consola
    bool mover(int xIni, int yIni, int xFin, int yFin);// para mover las piezas
    void aplicarGravedad(int columna); //primer intento de gravedad
    pieza* getCasilla(int x, int y) const {
        return casillas[y][x];
    }
    friend class pieza;
};

