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
#include <cstdlib>
#include <cmath>  



class Tablero {

    friend class CasillaSelec;
    friend class GestionPers;
    friend class Casilla;

private:
    Pieza* casillas[8][8]; //tablero 8x8
    Jugador player1; //Piezas blancas
    Jugador player2; //Piezas negras

public:

    static bool turno;
    static bool wwins;
    static bool bwins;

    Tablero(); //constructor

    Tablero& operator=(const Tablero& tab); //Constructor copia
    ~Tablero();//destructor
    void inicializar(int skin_player1, int skin_player2); //se usará para poner las piezas en la posición incial, luego si queremos guardar una partida podremos modificar esta función
    void mostrar(); // solo consola

    bool mover(int FilIni, int ColIni, int FilFin, int ColFin, Jugador& player_turnoActivo, Jugador& player_turnoInactivo, DATOS_DIBUJO& dat);
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
    bool gestion_turnos(bool& estado_JAQUE, bool& gana_p1, bool& gana_p2,  DATOS_DIBUJO& dat, char tecla);
    bool gestion_turnos_con_IA(bool& estado_JAQUE, bool& gana_p1, bool& gana_p2, DATOS_DIBUJO& dat, Tablero& t, char tecla);

    bool gestion_jaque(Jugador& defensor, Jugador& atacante, DATOS_DIBUJO& datos);
    bool comprobacion_jaque(Jugador& turno_activo, Jugador& turno_inactivo);
    bool comp_tablas(Jugador& turno_activo, Jugador& turno_inactivo, DATOS_DIBUJO& datos);
    bool comp_coronacion(Pieza*& pieza, unsigned char key);
    Casilla buscar_pieza(Pieza* p);
    Casilla buscar_posRey(Colorpieza c);
    bool guardarPartida(const std::string& nombreArchivo);
    bool cargarPartida(const std::string& nombreArchivo);
	void mostrarConCursor(int fila_cursor, int col_cursor); //Muestra el tablero con un cursor en la posición indicada
    Pieza* reconstruirPieza(int tipo, int color);
    friend class Pieza;
    friend class Partida;

    bool generador_de_movimientos(Jugador& jug_humano, Jugador& maq, Tablero& t, DATOS_DIBUJO& datos, unsigned char key);
    bool come_pieza_a_IA(Colorpieza color_IA, Tablero& t, int x_fin_p_IA, int y_fin_p_IA, DATOS_DIBUJO& datos);
    bool gestion_jaque_IA(Tablero& t, int& or_mov_x, int& or_mov_y, int& fin_mov_x, int& fin_mov_y, DATOS_DIBUJO& datos);

    Jugador& getPlayer1();
    Jugador& getPlayer2();
    vector<Pieza*> get_Piezas_Jaque(Jugador& p1, Jugador& p2);
};

