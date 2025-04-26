#include "estela.h"
#include "freeglut.h"
#include "iostream"

Estela::Estela() {}

Estela::Estela(Vector3D pos)
{
    org = pos;
    for (auto i = 0; max - 1 > i; i++)
    {
        circulitos[i].setpos({ pos.x, pos.y - ((float)i / (max - 1)) * dmax, pos.z });
    }
    //org.print();
}

Estela::Estela(float posx, float posy, float posz)
{
    org = { posx,posy,posz };
    for (auto i = 0; max - 1 > i; i++)
    { 
        circulitos[i].setpos({ posx, posy - ((float)i / (max-1)) * dmax, posz });
    }
    //std::cout << posx << posy << posz;
}

void Estela::setorg(const Vector3D& orgin) 
{
    org = orgin;
}

void Estela::dibuja()
{
    int i;
    glPushMatrix();

    for (i = 0; max - 1 > i; i++)
    {
        circulitos[i].drawcirc(org);
    }
   glPopMatrix();
   // std::cout << std::endl;
}