#pragma once
class Tablero;

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY, REINA };
enum class Colorpieza { NINGUNO, BLANCO, NEGRO };

class Pieza {
protected:
    TipoPieza tipo;
    Colorpieza color;

public:
    Pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color) {}
    virtual ~Pieza() = default;

    TipoPieza getTipo() const { return tipo; }
    Colorpieza getColor() const { return color; }

    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) = 0;
    friend class tablero;
};