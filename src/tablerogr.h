#pragma once
#include "listacasillas.h"

class TableroGr
{
	Vector3D pos{ 0,0,0 };//esquina inferior izquierda
	float side = 20;
	ListaCasillas casillas;

public:
	void dibuja();
};

