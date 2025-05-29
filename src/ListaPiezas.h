#pragma once
#include "pieza.h"
#include <iostream>
#include <vector>
using std::vector;
class ListaPiezas
{

	vector<Pieza*> lista_piezas; //Lista de piezas

public:
	ListaPiezas() = default; //Constructor Predefinido
	void dibuja();
	void agregar(Pieza* p);
	void eliminar(Pieza* p);
	int size() { return static_cast<int>(lista_piezas.size()); } //Me devuelve el número de piezas de un jugador que hay en una lista (de piezas actuales o eliminadas, por ejemplo)
	Pieza* obtener_pieza(int index) const;
	void limpiar();
	~ListaPiezas();
	friend class Jugador;
	friend class Tablero;

};


