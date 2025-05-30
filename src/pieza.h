#pragma once
class Tablero;
#include <vector>
#include "casilla.h"

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY, REINA };
enum class Colorpieza { NINGUNO, BLANCO, NEGRO };

class Pieza {
protected:
    TipoPieza tipo;
    Colorpieza color;
    std::vector<Casilla>* lista;

public:
    Pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color), lista{ nullptr } {}
    virtual ~Pieza() = default;

    TipoPieza getTipo() const { return tipo; }
    Colorpieza getColor() const { return color; }
    bool getColorBool() const
    {
        if (color == Colorpieza::BLANCO)
            return 1;
        if (color == Colorpieza::NEGRO || color==Colorpieza::NINGUNO)
            return 0;
    }
    void getlista(vector<Casilla>* listain) { lista = listain; }

    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) = 0;
    friend class tablero;
};