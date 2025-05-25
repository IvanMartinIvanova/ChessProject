#include "casilla.h"

Casilla::Casilla()
{ 
	file = 0;
	row = 0;
	pieza = nullptr;
}

Casilla::Casilla(int fin, int rin, PiezaGr* pie)
{
	file = fin;
	row = rin;
	pieza = pie;
}

void Casilla::setpos(int rowin, int filein)
{
	row = rowin;
	file = filein;
}

void Casilla::setpieza(PiezaGr* piezain)
{
	if (pieza == nullptr)
	{
		pieza = piezain;
	}
	else if (pieza != piezain)
	{
		delete pieza;
		pieza = piezain;
	}
}

void Casilla::draw()
{
	pieza->dibuja();
}

int Casilla::getfile()
{
	return file;
}

int Casilla::getrow()
{
	return row;
}