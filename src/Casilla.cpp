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

void Casilla::draw(int side, Vector3D org)
{
	if (pieza != nullptr)
	{
		glPushMatrix();
		glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);
		pieza->dibuja();
		glPopMatrix();
	}
	else
		std::cout << "error casilla->draw null ptr" << std::endl;
}

void Casilla::drawselec(int side, Vector3D  org)
{
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (Tablero::turno)
		glColor4f(0.392f, 0.0f, 1.0f, 0.5f);
	if (!Tablero::turno)
		glColor4f(0.392f, 0.588f, 1.0f, 0.5f);

	glTranslated(file / 9.0 * side + org.x, row / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1.5);
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

void Casilla::dibuja_Jaque(int side, Vector3D org, Color color)
{
	glPushMatrix();
	//glColor3ub(color.r, color.b, color.g);
	glColor4f(1, 0, 0, 0.5);
	glTranslated((file + 1) / 9.0 * side + org.x, (8 - row) / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1.5);
	glPopMatrix();
}

void Casilla::print()
{
	using namespace std;

	cout << gettipo() << endl;
	cout << getpieza()->color << endl;
	cout << file << " " << row << endl;
}

