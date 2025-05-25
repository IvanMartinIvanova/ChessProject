#pragma once

class Tablero; //Declaración anticipada para poder usar el puntero a la clase  Tablero llamada tab en los métodos de Jugador
#include "ListaPiezas.h"
#include "Puntuacion.h"
#include "Tiempo.h"
#include <string>

using namespace std;
class Jugador
{
protected:
	ListaPiezas lista_piezas_actuales;
	ListaPiezas lista_piezas_eliminadas;
	Puntuacion points;
	Tiempo temp;
	string Nombre;
	bool Turno; //True - si es el turno del jugador / False - si no es el turno del jugador

public:
	Jugador() = default;
	bool seleccion_casilla(Tablero& tab);
	bool mover(int FilIni, int ColIni, int FilFin, int ColFin, Tablero& tab);
	friend class Tablero;
	friend class Partida;
	~Jugador() = default;
};

