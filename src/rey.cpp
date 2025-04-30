#include "rey.h"
#include <cmath>


bool Rey::movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) {
    int dx = abs(xFin - xIni);
    int dy = abs(yFin - yIni);
    return (dx <= 1 && dy <= 1 && (dx + dy > 0));
}