#include "tablerogr.h"

void TableroGr::dibuja(Pieza* tableroin[8][8])
{ 
    //settablero(tableroin);
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

void TableroGr::settablero(Pieza* tableroin[8][8])
{
    int index = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tableroin[i][j]->getTipo()== TipoPieza::VACIA)
                casillas.listacasillas[index].setpieza(new VacioGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::PEON)
                casillas.listacasillas[index].setpieza(new PeonGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::CABALLO)
                casillas.listacasillas[index].setpieza(new CaballoGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::TORRE)
                casillas.listacasillas[index].setpieza(new TorreGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::ALFIL)
                casillas.listacasillas[index].setpieza(new AlfilGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::REY)
                casillas.listacasillas[index].setpieza(new ReyGr(tableroin[i][j]->getColorBool()));
            if (tableroin[i][j]->getTipo() == TipoPieza::REINA)
                casillas.listacasillas[index].setpieza(new ReinaGr(tableroin[i][j]->getColorBool()));
            ++index;
        }
    }
}
