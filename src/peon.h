#pragma once
#include "pieza.h"
#include "tablero.h"

class Peon : public Pieza {
public:
    Peon(Colorpieza color) : Pieza(TipoPieza::PEON, color) {}
    Pieza* clonar() const override {
        return new Peon(*this);
    }
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};
//el override lo que hace es que el m�todo est� sobrescribiendo un m�todo virtual que fue definido en una clase base siendo la clase base pieza.
