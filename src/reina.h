#pragma once
#include "pieza.h"
#include "tablero.h"  // Necesario para usar el tablero

class Reina : public Pieza {
public:
    // Constructor que recibe el color de la pieza
    Reina(Colorpieza color) : Pieza(TipoPieza::REINA, color) {}

    // Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};

