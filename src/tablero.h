#pragma once
#include "pieza.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include "Jugador.h"
#include "Casilla.h"
#include "DATOS_DIBUJO.h"
#include <iostream>
#include <cstdlib> // Para std::abs
#include <cmath>   // Para std::abs



class Tablero {

    friend class CasillaSelec;
    friend class Casilla;

private:
    Pieza* casillas[8][8]; //tablero 8x8
    Jugador player1; //Piezas blancas
    Jugador player2; //Piezas negras

public:
    static bool turno;
    Tablero(); //constructor

    Tablero& operator=(const Tablero& tab); //Constructor copia
    ~Tablero();//destructor
    void inicializar(); //se usará para poner las piezas en la posición incial, luego si queremos guardar una partida podremos modificar esta función
    void mostrar(); // solo consola

    bool mover(int FilIni, int ColIni, int FilFin, int ColFin, Jugador& player, DATOS_DIBUJO& dat);
    bool aplicarGravedad(Tablero& tab,Casilla destin0_sinGravedad, Pieza*& posPieza_final_conGrav); //primer intento de gravedad

    Pieza* getCasilla(int x, int y) const 
    { //Getter
        return casillas[x][y];
    }

    Pieza* (*getVectorCasillas())[8] { return casillas; }

    void setCasilla(int x, int y, Pieza* pieza) 
    { //Setter
        casillas[x][y] = pieza;
    }
    void resetCasilla(int x, int y) //Reinicio de casilla
    {
        casillas[x][y] = nullptr;
    }
    bool gestion_turnos(bool& estado_JAQUE, DATOS_DIBUJO& dat, char tecla);
    bool gestion_turnos_con_IA(bool& estado_JAQUE, DATOS_DIBUJO& dat, Tablero& t, char tecla);

    bool gestion_jaque(Jugador defensor, Jugador atacante);
    bool comprobacion_jaque(Jugador turno_activo, Jugador turno_inactivo);
    void comp_coronacion(Casilla cas_final_p);
    Casilla buscar_pieza(Pieza* p);
    bool guardarPartida(const std::string& nombreArchivo);
    bool cargarPartida(const std::string& nombreArchivo);
	void mostrarConCursor(int fila_cursor, int col_cursor); //Muestra el tablero con un cursor en la posición indicada
    friend class Pieza;
    friend class Partida;

    bool generador_de_movimientos(Jugador& jug_humano, Jugador& maq, Tablero& t, DATOS_DIBUJO& datos);
    bool come_pieza_a_IA(Colorpieza color_IA, Tablero& t, int x_fin_p_IA, int y_fin_p_IA);
    bool gestion_jaque_IA(Tablero& t, int& or_mov_x, int& or_mov_y, int& fin_mov_x, int& fin_mov_y, DATOS_DIBUJO& datos);

    Jugador& getPlayer1();
    Jugador& getPlayer2();
};

