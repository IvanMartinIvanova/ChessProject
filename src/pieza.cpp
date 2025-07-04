#include "pieza.h"

bool Pieza::getColorBool() const
{
    if (color == Colorpieza::BLANCO)
        return 1;
    if (color == Colorpieza::NEGRO || color == Colorpieza::NINGUNO)
        return 0;
}