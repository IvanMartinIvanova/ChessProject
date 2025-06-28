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

	if (Tablero::turno)
		glColor3ub(255,255,255);
	if (!Tablero::turno)
		glColor3ub(0, 0, 0);

	glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutWireCube(1.5);
	glPopMatrix();
}

void Casilla::drawposibl(int side, Vector3D  org)
{
	glPushMatrix();

	if (Tablero::turno)
		glColor3ub(100, 255, 155);
	if (!Tablero::turno)
		glColor3ub(155, 0, 100);	

	glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutWireCube(1.5);
	glPopMatrix();
}

void Casilla::print()
{
	using namespace std;

	cout << gettipo() << endl;
	cout << getpieza()->color << endl;
	cout << file << " " << row << endl;
}

void Casilla::dibuja_Jaque(int side, Vector3D org, Color color)
{
	glPushMatrix();
	glColor3ub(color.r, color.b, color.g);
	glTranslated((file+1) / 9.0 * side + org.x, (8 - row) / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutWireCube(1.5);
	glPopMatrix();
}