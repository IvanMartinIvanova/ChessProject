#pragma once
#include "pieza.h"
#include "tablero.h"

class torre : public pieza {
public:
    torre(Colorpieza color) : pieza(TipoPieza::TORRE, color) {}

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;
};
