#include "circulos.h"
#include "freeglut.h"
#include "math.h"

void Circulos::setpos(Vector3D posin)
{
    pos.x = posin.x;
    pos.y = posin.y;
    pos.z = posin.z;
}

float Circulos::calcrad(Vector3D posin)
{
    //pos.print();
    //std::cout << 0.3 * (dmax - (posin.y - pos.y)) << std::endl;
    return 0.3*(dmax - (posin.y - pos.y));
}

void Circulos::drawcirc(Vector3D posin)
{
    Circulos::calcpos(posin);

    glTranslated(pos.x, pos.y, pos.z);

    glRotated(90, 1, 0, 0);

    //std::cout << posin.x << " " << pos.x << std::endl;// << posin.y << posin.z;
    //drawDisk(2, 6, 6,64);
    glutSolidTorus(0.1, Circulos::calcrad(posin), 60, 60);

    //glutSolidTorus(0.1, 3, 60, 60);


    glRotated(-90, 1, 0, 0);
    glTranslated(-pos.x, -pos.y, -pos.z);
}

void Circulos::calcpos(Vector3D posin)
{
    pos.y -= ddif;
    if (fabs(posin.y - pos.y) > dmax)
    {
        pos.y = posin.y;
    }
   // std::cout << pos.z << " ";
}