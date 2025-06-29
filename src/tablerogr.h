#pragma once
#include "Plataforma.h"
#include "tablero.h"
#include "pieza.h"
#include "listacasillas.h"

class TableroGr : public Plataforma
{
	Vector3D pos{ -10,-10,0.01 };//esquina inferior izquierda
	float side = 20;
	ListaCasillas casillas;
	ETSIDI::Sprite fondoTablero{ "rc/board.png", pos.x, pos.y, 20, 20};
	ETSIDI::Sprite fondoJuego{ "rc/fondo1.png", 0,0,400,400};


public:
	void dibuja(Pieza* (*tableroin)[8]);
	Vector3D idle();
	void settablero(Pieza* (*tableroin)[8]);
	void mueve(unsigned char tecla);
};

