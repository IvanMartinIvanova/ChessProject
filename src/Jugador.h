#pragma once

class Tablero; //Declaración anticipada para poder usar el puntero a la clase  Tablero llamada tab en los métodos de Jugador
#include "ListaPiezas.h"
#include "Puntuacion.h"
#include "DATOS_DIBUJO.h"
#include "Tiempo.h"
#include <string>

using namespace std;
class Jugador
{
protected:
	ListaPiezas lista_piezas_actuales;
	ListaPiezas lista_piezas_comidas;
	Puntuacion points;
	Tiempo temp;
	string Nombre;
	bool Turno; //True - si es el turno del jugador / False - si no es el turno del jugador

public:
	Jugador();
	Jugador& operator=(const Jugador& player);
	bool seleccion_casilla(Tablero& tab, DATOS_DIBUJO& dat);
	void actualizar_listas(Jugador& player);
	~Jugador() = default;
	friend class Tablero;
	friend class Partida;
	friend class ListaPiezas;
	

};

