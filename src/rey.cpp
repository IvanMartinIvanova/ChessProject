#include "rey.h"
#include <cmath>


bool Rey::movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) {

    //En caso de que se seleccione como casilla final la misma casilla que la inicial -> movimiento no v�lido
    if (xIni == xFin && yIni == yFin) return false;
   

    int dx = abs(xFin - xIni);
    int dy = abs(yFin - yIni);
    return (dx <= 1 && dy <= 1 && (dx + dy > 0));
}