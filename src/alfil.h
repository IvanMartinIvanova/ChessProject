#pragma once
#include "pieza.h"
#include "tablero.h"  // Aseg�rate de incluir Tablero.h si lo necesitas

class Alfil : public Pieza {
public:
    // Constructor que recibe el color de la pieza
    Alfil(Colorpieza color) : Pieza(TipoPieza::ALFIL, color) {}
    Pieza* clonar() const override {
        return new Alfil(*this); //Copia por valor
    }
    // Implementaci�n de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};


