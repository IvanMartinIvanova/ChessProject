#pragma once

class Tablero;

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY, REINA };
enum class Colorpieza { NINGUNO, NEGRO, BLANCO };

class Pieza {
protected:
    TipoPieza tipo;
    Colorpieza color;
   
public:
    Pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color) {}
    Pieza(const Pieza& otra) : tipo(otra.tipo), color(otra.color){} //Constructor Copia
    virtual ~Pieza() = default;
    virtual Pieza* clonar() const = 0; //Para clonar piezas
    TipoPieza getTipo() const { return tipo; }
    Colorpieza getColor() const { return color; }
    void dibuja();
    
    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) = 0;
    friend class Tablero;
    friend class Jugador;
};