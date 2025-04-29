#pragma once
#include "pieza.h"
#include "tablero.h"  // Necesario para usar el tablero

class reina : public pieza {
public:
    // Constructor que recibe el color de la pieza
    reina(Colorpieza color) : pieza(TipoPieza::REINA, color) {}

    // Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;
};

