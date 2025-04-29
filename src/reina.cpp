#include "reina.h"
#include <cmath> // Para usar abs()




// Implementación de movimientoValido, con Tablero
bool reina::movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) {
    // La reina puede moverse en línea recta o diagonal
    int dx = abs(xFin - xIni);
    int dy = abs(yFin - yIni);

    // Verificamos si el movimiento es en línea recta o en diagonal
    if (dx == 0 || dy == 0 || dx == dy) {
        // Movimiento en línea recta (horizontal o vertical) o en diagonal
        // Verificamos si hay piezas en el camino
        int xStep = (xFin - xIni != 0) ? (xFin - xIni) / abs(xFin - xIni) : 0;
        int yStep = (yFin - yIni != 0) ? (yFin - yIni) / abs(yFin - yIni) : 0;

        int x = xIni + xStep;
        int y = yIni + yStep;

        while (x != xFin || y != yFin) {
            if (tablero.getCasilla(x, y) != nullptr) {
                // Hay una pieza en el camino, no se puede mover
                return false;
            }
            x += xStep;
            y += yStep;
        }

        // Si el destino tiene una pieza, podemos comerla (propia o enemiga)
        return true;
    }

    return false;
}
