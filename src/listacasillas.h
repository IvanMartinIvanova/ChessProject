#pragma once
#include "casilla.h"
#include "piezagr.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "plataforma.h"
#include "casillaselec.h"
#include <vector>


class ListaCasillas:public Plataforma
{	
	CasillaSelec selec;
protected:
	std::vector <Casilla> listacasillas;
	std::vector <Casilla>* blancas;
	std::vector <Casilla>* negra;

public:
	ListaCasillas();
	void dibuja(Vector3D org, float side);
	PiezaGr* getpieza(int row, int file);
	void move(unsigned char tecla);
	void setpieza(int row, int file, PiezaGr* piezain);
};

