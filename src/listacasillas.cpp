#include "listacasillas.h"
#include <iostream>

ListaCasillas::ListaCasillas()
{
    listacasillas.resize(64);
    selec.getlista(&listacasillas);
    int index = 0;
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            listacasillas[index].setpos(i, j);
            ++index;
        }
    }

   /* for (auto i = 0; listacasillas.size() > i; i++)
    {
        bool color;
        if (listacasillas[i].getfile() < 4)
            color = 1;
        else
            color = 0;

        listacasillas[i].setpieza(new VacioGr());

        if (listacasillas[i].getfile() == 2 || listacasillas[i].getfile() == 7)
        {
            listacasillas[i].setpieza(new PeonGr(color));
        }

        if (listacasillas[i].getfile() == 1 || listacasillas[i].getfile() == 8)
        {
            if (listacasillas[i].getrow() == (1) || listacasillas[i].getrow() == 8)
                listacasillas[i].setpieza(new TorreGr(color));
            if (listacasillas[i].getrow() == (2) || listacasillas[i].getrow() == 7)
                listacasillas[i].setpieza(new CaballoGr(color));
            if (listacasillas[i].getrow() == 3 || listacasillas[i].getrow() == 6)
                listacasillas[i].setpieza(new AlfilGr(color));
            if (listacasillas[i].getrow() == 4)
                listacasillas[i].setpieza(new ReyGr(color));
            if (listacasillas[i].getrow() == 5)
                listacasillas[i].setpieza(new ReinaGr(color));
        }
    }*/
}
void ListaCasillas::dibuja(Vector3D org, float side)
{
    for (auto i = 0; listacasillas.size() > i; i++)
    {
        listacasillas[i].draw(side, org);
    }
    selec.draw(side, org);
    selec.resalta(side, org);
}

PiezaGr* ListaCasillas::getpieza(int rowin, int filein)
{
    return listacasillas[(rowin - 1) * 8 + (filein - 1)].getpieza();
}

void ListaCasillas::move(unsigned char tecla)
{
    selec.move(tecla);
}

void ListaCasillas::setpieza(int rowin, int filein, PiezaGr* piezain)
{
    listacasillas[(rowin - 1) * 8 + (filein - 1)].setpieza(piezain);
}

string ListaCasillas::gettipo(int rowin, int filein)
{
    return getpieza(rowin, filein)->gettipo();
}