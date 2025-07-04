#pragma once
#include "pieza.h"
#include "tablero.h" 

class Reina : public Pieza 
{
    public:
    // Constructor que recibe el color de la pieza
    Reina(Colorpieza color) : Pieza(TipoPieza::REINA, color) {}
    Pieza* clonar() const override {
        return new Reina(*this);
    }
    // Implementación de movimientoValido, con Tablero
    bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) override;
};

