#pragma once
#include "pieza.h"
#include "tablero.h"

class Torre : public Pieza {
public:
    Torre(Colorpieza color) : Pieza(TipoPieza::TORRE, color) {}
    Pieza* clonar() const override {
        return new Torre(*this);
    }
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};
