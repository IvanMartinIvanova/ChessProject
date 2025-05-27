#include "casillaselec.h"

CasillaSelec::CasillaSelec()
{
	file = 4;
	row = 4;
}

void CasillaSelec::move(unsigned char tecla)
{
	if ((tecla == 'w') && (file < 8))
		file += 1;
	if (tecla == 's' && file > 1)
		file -= 1;
	if (tecla == 'd' && row < 8)
		row += 1;
	if (tecla == 'a' && row > 1)
		row -= 1;

	std::cout << row << " " << file << std::endl;
	std::cout << CasillaSelec::gettipo(file, row) << std::endl;
}


void CasillaSelec::draw(float side, Vector3D org)
{
	glPushMatrix();
	glTranslated(row / 9.0 * side + org.x, file / 9.0 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
	glutSolidCube(1);
	glPopMatrix();
	//std::cout << file << " " << row << " " << endl;
}

void CasillaSelec::getlista(vector<Casilla>* listain)
{
	lista = listain;
}

PiezaGr* CasillaSelec::getpieza(int rowin, int filein)
{
	Casilla casilla = (*lista)[(rowin - 1) * 8 + (filein - 1)];
	return casilla.getpieza();
}

string CasillaSelec::gettipo(int rowin, int filein)
{
	return getpieza(rowin, filein)->gettipo();
}

