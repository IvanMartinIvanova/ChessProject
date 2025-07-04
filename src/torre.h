#pragma once
#include "pieza.h"
#include "tablero.h"

class Torre : public Pieza {
public:
	// Constructor que recibe el color de la pieza
    Torre(Colorpieza color) : Pieza(TipoPieza::TORRE, color) {}
    Pieza* clonar() const override {
        return new Torre(*this);
    }
	// Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};
