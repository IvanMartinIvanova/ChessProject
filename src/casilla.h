#pragma once
#include <map>
#include <vector>
#include <string>
#include "piezagr.h"

using namespace std;

class Casilla
{
	int file; //columna
	int row; //fila
	PiezaGr* pieza;

public:
	Casilla();
	Casilla(int fin, int rin, PiezaGr* pie);

	void setpos(int rowin, int filein);
	void setpieza(PiezaGr* piezain);
	int getrow();
	int getfile();


	void draw();
};

