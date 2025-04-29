#pragma once
#include "pieza.h"
#include "tablero.h"  // Asegúrate de incluir Tablero.h si lo necesitas

class alfil : public pieza {
public:
    // Constructor que recibe el color de la pieza
    alfil(Colorpieza color) : pieza(TipoPieza::ALFIL, color) {}

    // Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;
};

