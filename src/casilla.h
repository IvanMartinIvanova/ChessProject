#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "piezagr.h"

using namespace std;

class Casilla
{
	int file; //columna
	int row; //fila

protected:
	PiezaGr* pieza;

public:
	Casilla();
	Casilla(int fin, int rin, PiezaGr* pie);

	void setpos(int rowin, int filein);
	void setpieza(PiezaGr* piezain);
	float getrow();
	float getfile();
	PiezaGr* getpieza();
	string gettipo();


	virtual void draw();
};

