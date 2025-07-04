#include "peon.h"
#include <cmath> 


bool Peon::movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) {

    //En caso de que se seleccione como casilla final la misma casilla que la inicial -> movimiento no v�lido
    if (xIni == xFin && yIni == yFin) return false;

    // Verifica si el pe�n est� movi�ndose hacia adelante
    if (color == Colorpieza::BLANCO) {
        if (xIni == xFin && yFin == yIni + 1 && tablero.getCasilla(xFin, yFin) == nullptr) {
            return true;  // Avance de una casilla hacia adelante
        }
        if (xIni == xFin && yIni == 1 && yFin == 3 && tablero.getCasilla(xFin, yFin) == nullptr && tablero.getCasilla(xIni, yIni + 1) == nullptr) {
            return true;  // Avance de dos casillas hacia adelante
        }
        if (abs(xFin - xIni) == 1 && yFin == yIni + 1 && tablero.getCasilla(xFin, yFin) != nullptr) {
            return true;  // Captura en diagonal
        }
    }
    else if (color == Colorpieza::NEGRO) {
        if (xIni == xFin && yFin == yIni - 1 && tablero.getCasilla(xFin, yFin) == nullptr) {
            return true;  // Avance de una casilla hacia adelante
        }
        if (xIni == xFin && yIni == 6 && yFin == 4 && tablero.getCasilla(xFin, yFin) == nullptr && tablero.getCasilla(xIni, yIni - 1) == nullptr) {
            return true;  // Avance de dos casillas hacia adelante
        }
        if (abs(xFin - xIni) == 1 && yFin == yIni - 1 && tablero.getCasilla(xFin, yFin) != nullptr) {
            return true;  // Captura en diagonal
        }
    }

    return false;  // Si ninguna de las condiciones anteriores se cumple, el movimiento no es v�lido
}
