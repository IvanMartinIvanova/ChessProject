#pragma once
#include "casilla.h"
#include "piezagr.h"
#include "Vector3D.h"
#include <vector>


class ListaCasillas
{	
	std::vector <Casilla> listacasillas;

public:
	ListaCasillas();
	void dibuja(Vector3D org, float side);
};

