#pragma once
#include "pieza.h"
#include "tablero.h"

class Caballo : public Pieza {
public:
    Caballo(Colorpieza color) : Pieza(TipoPieza::CABALLO, color) {}
    Pieza* clonar() const override {
        return new Caballo(*this);
    }
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};
