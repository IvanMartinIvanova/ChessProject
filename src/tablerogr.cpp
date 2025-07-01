#include "tablerogr.h"

void TableroGr::dibuja(Pieza* (*tableroin)[8])
{
    settablero(tableroin);
    Vector3D posActual = idle();
    fondoTablero.setPos(posActual.x+10, posActual.y+10);
    fondoJuego.setPos(posActual.x, posActual.y);
    fondoTablero.draw();
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

void TableroGr::settablero(Pieza* (*tableroin)[8])
{

    int index = -1;
    for (int j = 0; j < 8; ++j) {
        for (int i = 7; i > -1; --i) {

            index++;
            Pieza* pieza = tableroin[i][j];

            if (tableroin[i][j] == NULL)
                casillas.listacasillas[index].setpieza(new VacioGr());

            if (!pieza) continue;

            if (tableroin[i][j]->getTipo() == TipoPieza::PEON)
                casillas.listacasillas[index].setpieza(new PeonGr(tableroin[i][j]->getColorBool(),tableroin[i][j]->getSkin()));
          
            if (tableroin[i][j]->getTipo() == TipoPieza::CABALLO)
                    casillas.listacasillas[index].setpieza(new CaballoGr(tableroin[i][j]->getColorBool(), tableroin[i][j]->getSkin()));
             
            if (tableroin[i][j]->getTipo() == TipoPieza::TORRE)
                casillas.listacasillas[index].setpieza(new TorreGr(tableroin[i][j]->getColorBool(), tableroin[i][j]->getSkin()));
                    
            if (tableroin[i][j]->getTipo() == TipoPieza::ALFIL)
                casillas.listacasillas[index].setpieza(new AlfilGr(tableroin[i][j]->getColorBool(), tableroin[i][j]->getSkin()));
                       
            if (tableroin[i][j]->getTipo() == TipoPieza::REY)
                casillas.listacasillas[index].setpieza(new ReyGr(tableroin[i][j]->getColorBool(), tableroin[i][j]->getSkin()));
                           
            if (tableroin[i][j]->getTipo() == TipoPieza::REINA)
                casillas.listacasillas[index].setpieza(new ReinaGr(tableroin[i][j]->getColorBool(), tableroin[i][j]->getSkin()));
                         
        }
    }
}