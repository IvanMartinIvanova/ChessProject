#pragma once
#include "pieza.h"
#include "tablero.h"  // Asegúrate de incluir Tablero.h si lo necesitas
#include "listacasillas.h"

class Alfil : public Pieza {
public:
    // Constructor que recibe el color de la pieza
    Alfil(Colorpieza color) : Pieza(TipoPieza::ALFIL, color) {}

    // Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin);

};

