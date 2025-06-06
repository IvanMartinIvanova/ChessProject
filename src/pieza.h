#pragma once

#include <vector>

class Casilla;
class Tablero;

enum class TipoPieza { VACIA, PEON, TORRE, CABALLO, ALFIL, REY, REINA };
enum class Colorpieza { NINGUNO, NEGRO, BLANCO };

using namespace std;
class Pieza {
protected:
    TipoPieza tipo;
    Colorpieza color;
    std::vector<Casilla>* lista;
   
public:
    Pieza(TipoPieza t) : tipo(t) {};
    Pieza(TipoPieza tipo, Colorpieza color) : tipo(tipo), color(color), lista{ nullptr } {}
    Pieza(const Pieza& otra) : tipo(otra.tipo), color(otra.color){} //Constructor Copia
    virtual ~Pieza() = default;
    virtual Pieza* clonar() const = 0; //Para clonar piezas
    TipoPieza& getTipo()  { return tipo;  }
    Colorpieza& getColor()  { return color; }
    bool getColorBool() const;
    void getlista(vector<Casilla>* listain) { lista = listain; }
    void dibuja();
    virtual bool movimientoValido(int xIni, int yIni, int xFin, int yFin, Tablero& tablero) = 0;
    friend class Tablero;
    friend class Jugador;
    friend class DATOS_DIBUJO;
};