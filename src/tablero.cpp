#include "tablero.h"
#include <iostream>

Tablero::Tablero() {
    for (int y = 0; y < 8; y++)//constructor base de matrices en general
        for (int x = 0; x < 8; x++)
            casillas[y][x] = nullptr;
}

Tablero::~Tablero() {
    for (int y = 0; y < 8; y++)//destructor base de matrices en general
        for (int x = 0; x < 8; x++)
            delete casillas[y][x];
}

void Tablero::inicializar() {
    // Solo algunos peones para empezar
    for (int x = 0; x < 8; x++) {
        casillas[1][x] = new Peon(Color::NEGRO);//crea los peones blancos sin mas
        casillas[6][x] = new Peon(Color::BLANCO);//crea los peones negros sin mas
    }
}

void Tablero::mostrar() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (casillas[y][x] == nullptr)
                std::cout << ". ";
            else
                std::cout << (casillas[y][x]->getColor() == Color::BLANCO ? "B " : "N ");//comparador, lo unico que hace es ver si es blanco, si es blanco devuelbe B si no devuelve N
        }
        std::cout << std::endl;
    }
}

bool Tablero::mover(int xIni, int yIni, int xFin, int yFin) {
    if (!casillas[yIni][xIni]) return false;//Mira si hay una pieza en la posición inicial del movimiento (yIni, xIni),Si no hay pieza (es nullptr), el movimiento no tiene sentido, así que devuelve false.

    Pieza* pieza = casillas[yIni][xIni];
    if (pieza->movimientoValido(xIni, yIni, xFin, yFin)) {
        // Puede comerse piezas propias y enemigas
        delete casillas[yFin][xFin]; // comer
        casillas[yFin][xFin] = pieza;
        casillas[yIni][xIni] = nullptr;

		aplicarGravedad(xFin); // Aplicar gravedad en la columna de destino
        return true;
    }

    return false;
}

void Tablero::aplicarGravedad(int columna) {
    for (int fila = 6; fila >= 0; fila--) {//empieza desde abajo para comprobar si hay pieza
        if (casillas[fila][columna] != nullptr) {
            int destino = fila;
			while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr)//si destino +1 es menor a 8 y la casilla esta vacia destino aumenta 
                destino++;

            if (destino != fila) {//esto es para que vaya cayendo gradual, de 1 a 1
                casillas[destino][columna] = casillas[fila][columna];
                casillas[fila][columna] = nullptr;
            }
        }
    }
}
