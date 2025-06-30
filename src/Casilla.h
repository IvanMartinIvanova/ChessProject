#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <Vector3D.h>
#include "tablero.h"
#include "piezagr.h"
#include "Color.h"
#include "freeglut.h"

using namespace std;

class Casilla
{
	int file; //columna
	int row; //fila

protected:
	PiezaGr* pieza;

public:
	Casilla();
	Casilla(int fila, int columna);
	Casilla(int fin, int rin, PiezaGr* pie);

	void setpos(int rowin, int filein);
	void setpieza(PiezaGr* piezain);
	float getrow();
	float getfile();
	PiezaGr* getpieza();
	string gettipo();
	void drawselec(int side, Vector3D org);
	void drawposibl(int side, Vector3D org);
	void print();
	void dibuja_Jaque(int side, Vector3D org, Color color);

	virtual void draw();
	friend class Tablero;
};


