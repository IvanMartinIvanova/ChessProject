#include "tablerogr.h"

void TableroGr::dibuja()
{ 
	casillas.dibuja(TableroGr::idle(), side);
}

Vector3D TableroGr::idle()
{
	return { pos.x,pos.y + osci * sin(counter),pos.z };
}

void TableroGr::mueve(unsigned char tecla)
{
	casillas.move(tecla);
}
