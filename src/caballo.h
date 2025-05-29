#pragma once
#include "pieza.h"
#include "tablero.h"
#include "listacasillas.h"

class Caballo : public Pieza {
public:
    Caballo(Colorpieza color) : Pieza(TipoPieza::CABALLO, color) {}

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin);
};
// El caballo se mueve en forma de "L": dos casillas en una dirección y una en la otra.