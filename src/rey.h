#pragma once
#include "pieza.h"
#include "tablero.h"

class rey : public pieza {
public:
    rey(Colorpieza color) : pieza(TipoPieza::REY, color) {}

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;

};


