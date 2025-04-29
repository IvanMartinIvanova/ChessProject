#include "torre.h"
#include <cmath> // Para usar abs()


bool torre::movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) {
    if (xIni != xFin && yIni != yFin) return false;

    int dx = (xFin > xIni) ? 1 : (xFin < xIni) ? -1 : 0;
    int dy = (yFin > yIni) ? 1 : (yFin < yIni) ? -1 : 0;

    int x = xIni + dx;
    int y = yIni + dy;

    while (x != xFin || y != yFin) {
        if (tablero.getCasilla(x, y) != nullptr)
            return false;
        x += dx;
        y += dy;
    }

    return true;
}