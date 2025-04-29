#pragma once
class tablero;

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY, REINA };
enum class Colorpieza { NINGUNO, BLANCO, NEGRO };

class pieza {
protected:
    TipoPieza tipo;
    Colorpieza color;

public:
    pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color) {}
    virtual ~pieza() = default;

    TipoPieza getTipo() const { return tipo; }
    Colorpieza getColor() const { return color; }

    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin, tablero& tablero) = 0;
    friend class tablero;
};