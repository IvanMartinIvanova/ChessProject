#include "caballo.h"
#include <cmath>

bool caballo::movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) {
    int dx = abs(xFin - xIni);
    int dy = abs(yFin - yIni);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}