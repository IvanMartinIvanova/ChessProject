#pragma once

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY }; // vacia en caso de contrario a las categorias
enum class Colorpieza { NINGUNO, BLANCO, NEGRO }; //ninguno, igual para evitar 

class Pieza {
protected:
    TipoPieza tipo; //atributos
    Colorpieza color;

public:
    Pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color) {} //constructor de las piezas
    virtual ~Pieza() = default; // destructor de las piezas hijas

    TipoPieza getTipo() const { return tipo; } //como los gets de los labs
    Colorpieza getColor() const { return color; }

    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin) = 0; // obliga a las clases hijas a definir cómo se mueven.
};

