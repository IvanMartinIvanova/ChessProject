#pragma once
#include "Plataforma.h"
#include "listacasillas.h"

class TableroGr: public Plataforma
{
	Vector3D pos{ -10,-10,0.01 };//esquina inferior izquierda
	float side = 20;
	ListaCasillas casillas;

public:
	void dibuja();
	Vector3D idle();
	void mueve(unsigned char tecla);
};

