#include "listacasillas.h"
#include <iostream>

ListaCasillas::ListaCasillas()
{
    listacasillas.resize(64);
    int index = 0;
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            listacasillas[index].setpos(i, j);
            ++index;
        }
    }

    for (auto e : listacasillas)
    {
        bool color;
        if (e.getfile() < 3)
            color = 1;
        else
            color = 0;

        if (e.getfile() == (2 || 7))
        {
            e.setpieza(new PeonGr(color));
        }
       

        if (e.getfile() == (1 || 8))
        {
            if(e.getrow()==(1||8))
                e.setpieza(new TorreGr(color));
            if(e.getrow()==(2||7))
                e.setpieza(new CaballoGr(color));
            if(e.getrow()==(3||6))
                e.setpieza(new AlfilGr(color));
            if(e.getrow()==4)
                e.setpieza(new ReyGr(color));
            if(e.getrow()==5)
                e.setpieza(new ReinaGr(color));
        }
    }
}

void ListaCasillas::dibuja(Vector3D org, float side)
{
    for (auto e : listacasillas)
    {       
        glPopMatrix();
        glTranslated(e.getfile()/1 * side + org.x, e.getrow()/8 * side + org.y, org.z);//org se supone q es la esquina inferior izquierda del tablero (donde se juega no el marco)
        e.draw();
        glPushMatrix();
    }
}