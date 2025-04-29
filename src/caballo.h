#pragma once
#include "pieza.h"
#include "tablero.h"

class caballo : public pieza {
public:
    caballo(Colorpieza color) : pieza(TipoPieza::CABALLO, color) {}

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;
};
// El caballo se mueve en forma de "L": dos casillas en una dirección y una en la otra.