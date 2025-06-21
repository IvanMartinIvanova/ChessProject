#include "alfil.h"
#include <cmath>



bool Alfil::movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) {

    //En caso de que se seleccione como casilla final la misma casilla que la inicial -> movimiento no válido
    if (xIni == xFin && yIni == yFin) return false;
    

    int dx = abs(xFin - xIni);
    int dy = abs(yFin - yIni);

    if (dx != dy) return false;  // El Alfil solo se mueve en diagonal

    // Comprobar si el camino está libre
    int xDirection = (xFin - xIni) > 0 ? 1 : -1;
    int yDirection = (yFin - yIni) > 0 ? 1 : -1;

    int x = xIni + xDirection;
    int y = yIni + yDirection;

    while (x != xFin && y != yFin) {
        if (tablero.getCasilla(x, y) != nullptr) {
            return false;  // Si hay una pieza en el camino, no se puede mover
        }
        x += xDirection;
        y += yDirection;
    }

    return true;
}