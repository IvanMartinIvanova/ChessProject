#pragma once
#include "pieza.h"

class Peon : public Pieza {//importante!! es una clase que hereda de pieza PEON en el ambito PIEZA
public:
	Peon(Color color) : Pieza(TipoPieza::PEON, color) {}//constructor de la clase peon, inicializa el tipo de pieza y el color

    bool movimientoValido(int xIni, int yIni, int xFin, int yFin) override {
        int dy = (color == Color::BLANCO) ? -1 : 1;//el pe�n se mueve una casilla hacia adelante (hacia arriba si es blanco, abajo si es negro).
        return (xIni == xFin) && (yFin - yIni == dy);
    }//todav�a falta capturas, es un codigo INICIAL
};
//el override lo que hace es que el m�todo est� sobrescribiendo un m�todo virtual que fue definido en una clase base siendo la clase base pieza.
