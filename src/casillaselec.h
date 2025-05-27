#pragma once
#include "casilla.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector3D.h"

class CasillaSelec
{
	int file, row;
	std::vector<Casilla>* lista = nullptr;

public:
	CasillaSelec();
	void move(unsigned char tecla);
	void getlista(vector<Casilla>* listain);
	void resalta();
	void draw(float side, Vector3D org);
	PiezaGr* getpieza(int rowin, int filein);
	std::string gettipo(int rowin, int filein);
};

