#include "casilla.h"
#include "Vector3D.h"


Casilla::Casilla(): file(1), row(1), pieza(nullptr){}

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

void Casilla::setpos(int filein, int rowin)
{
	row = rowin;
	file = filein;
}

void Casilla::setpieza(PiezaGr* piezain)
{
		delete pieza;
		pieza = piezain;
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
	glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1);
	glPopMatrix();
}

void Casilla::drawposibl(int side, Vector3D  org)
{
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1);
	glPopMatrix();
}

void Casilla::print()
{
	using namespace std;

	cout << gettipo() << endl;
	cout << getpieza()->color << endl;
	cout << file << " " << row << endl;
}