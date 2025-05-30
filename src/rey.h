#pragma once
#include "pieza.h"
#include "tablero.h"

class Rey : public Pieza {
public:
    Rey(Colorpieza color) : Pieza(TipoPieza::REY, color) {}
    Pieza* clonar() const override {
        return new Rey(*this);
    }
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
   


};


