#pragma once
#include "pieza.h"
#include "tablero.h"

class Rey : public Pieza {
public:
	// Constructor que recibe el color de la pieza
    Rey(Colorpieza color) : Pieza(TipoPieza::REY, color) {}
    Pieza* clonar() const override {
        return new Rey(*this);
    }
	// Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
   


};


