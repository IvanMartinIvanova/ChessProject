#include "pieza.h"

void Pieza::dibuja()
{

}

bool Pieza::getColorBool() const
{
    if (color == Colorpieza::BLANCO)
        return 1;
    if (color == Colorpieza::NEGRO || color == Colorpieza::NINGUNO)
        return 0;
}