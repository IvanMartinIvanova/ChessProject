#pragma once
#include "pieza.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include "Jugador.h"
#include <iostream>
#include <cstdlib> // Para std::abs
#include <cmath>   // Para std::abs



class Tablero {
private:
    Pieza* casillas[8][8]; //tablero 8x8
    Jugador player1; //Piezas blancas
    Jugador player2; //Piezas negras

public:
    Tablero(); //constructor
    ~Tablero();//destructor
    void inicializar(); //se usará para poner las piezas en la posición incial, luego si queremos guardar una partida podremos modificar esta función
    void mostrar(); // solo consola
    void aplicarGravedad(); //primer intento de gravedad
    Pieza* getCasilla(int x, int y) const { //Getter
        return casillas[x][y];
    }
    void setCasilla(int x, int y, Pieza* pieza) { //Setter
        casillas[x][y] = pieza;
    }
    void resetCasilla(int x, int y) //Reinicio de casilla
    {
        casillas[x][y] = nullptr;
    }
    void gestion_turnos();
    bool guardarPartida(const std::string& nombreArchivo);
    bool cargarPartida(const std::string& nombreArchivo);
    friend class Pieza;
    friend class Partida;
};

