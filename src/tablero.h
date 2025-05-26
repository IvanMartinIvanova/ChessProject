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
    void inicializar(); //se usará para poner las piezas en la posición incial, luego si queremos guardar una partida podremos modificar esta función
    void mostrar(); // solo consola
    bool mover(int xIni, int yIni, int xFin, int yFin);// para mover las piezas
    void aplicarGravedad(int columna); //primer intento de gravedad
    Pieza* getCasilla(int x, int y) const {
        return casillas[y][x];
    }
    friend class pieza;

    bool com_dentro_tablero(int xFin, int yFin);
    void comp_coronacion(int, int);
    int generador_de_movimientos(Tablero& t);
    bool comp_jaque(int xFin, int yFin, Tablero& t);
    bool comp_jaque_mate(int xFin, int yFin, Tablero& t);

    //Funciones auxiliares para jaque mate
    Pieza* buscar_rey(int xFin, int yFin, int& pos_rey_x, int& pos_rey_y);
    // 1 - ATACADA  /  0 - SIN ATACAR / 2 - LA CASILLA ESTÁ OCUPADA O NO PERTENECE AL TABLERO / 3 - PIEZA DEL MISMO COLOR QUE EL REY
    bool conocer_casilla_atacada(Colorpieza color, Tablero& t, int& cas_atacada_x, int& cas_atacada_y);
    bool pieza_mismo_color_cerca_rey(Colorpieza color, Tablero& t, int& cas_atacada_x, int& cas_atacada_y);
    int numero_atacantes(Colorpieza c, int xFin, int yFin, Tablero& t); 
    int posicion_atacante(int& pos_atac_x, int& pos_atac_y, Colorpieza c, int xFin, int yFin, Tablero& t);
    Pieza* crearPieza(TipoPieza tipo, Colorpieza color);
};

