#include "casilla.h"
#include "Vector3D.h"


Casilla::Casilla(): file(0), row(0), pieza(nullptr){}

Casilla::Casilla(int fila, int columna)
{
	file = columna;
	row = fila;
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
	if (pieza != nullptr)
	{
		pieza->dibuja();
	}
	else
		std::cout << "error casilla->draw null ptr" << std::endl;
}

float Casilla::getfile()
{
	return file;
}

float Casilla::getrow()
{
	return row;
}

PiezaGr* Casilla::getpieza()
{
	return pieza;
}

string Casilla::gettipo()
{
	return pieza->gettipo();
}

void Casilla::drawselec(int side, Vector3D  org)
{
	glPushMatrix();
	glColor3ub(100, 255, 155);
	glTranslated(row / 9.0 * side + org.x, file / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1);
	glPopMatrix();
}

void Casilla::drawposibl(int side, Vector3D  org)
{
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslated(row / 9.0 * side + org.x, file / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1);
	glPopMatrix();
}