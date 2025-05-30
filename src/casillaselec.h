#pragma once
#include "casilla.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector3D.h"

class CasillaSelec
{
	int file, row, filein, rowin;
	Casilla casillaselec;
	std::vector<Casilla>* lista = nullptr;

public:
	CasillaSelec();
	void move(unsigned char tecla);
	void resalta(int side, Vector3D org);
	void draw(float side, Vector3D org);

	bool reina(Casilla casillap, Casilla casillacheck);
	bool peon(Casilla casillap, Casilla casillacheck);
	bool torre(Casilla casillap, Casilla casillacheck);
	bool alfil(Casilla casillap, Casilla casillacheck);
	bool caballo(Casilla casillap, Casilla casillacheck);
	bool rey(Casilla casillap, Casilla casillacheck);

	void getlista(vector<Casilla>* listain);
	PiezaGr* getpieza(int rowin, int filein);
	std::string gettipo(int rowin, int filein);
	Casilla getcasilla();
	Casilla getcasilla(int row, int file);
};

