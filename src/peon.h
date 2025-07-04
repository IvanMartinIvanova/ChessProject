#pragma once
#include "pieza.h"
#include "tablero.h"

class Peon : public Pieza {
public:
	// Constructor que recibe el color de la pieza
    Peon(Colorpieza color) : Pieza(TipoPieza::PEON, color) {}
    Pieza* clonar() const override {
        return new Peon(*this);
    }
	// Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};

