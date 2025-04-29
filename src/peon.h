#pragma once
#include "pieza.h"
#include "tablero.h"

class peon : public pieza {
public:
    peon(Colorpieza color) : pieza(TipoPieza::PEON, color) {}

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) override;
};
//el override lo que hace es que el m�todo est� sobrescribiendo un m�todo virtual que fue definido en una clase base siendo la clase base pieza.
