#include "tablero.h"
#include <iostream>
#include <string>
using namespace std;

Tablero::Tablero() {
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            casillas[y][x] = nullptr;
}

Tablero::~Tablero() {
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            delete casillas[y][x];
}

void Tablero::inicializar() {
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            casillas[y][x] = nullptr;

    // Negras arriba (columna 0 y 1)
    casillas[0][0] = new Torre(Colorpieza::NEGRO);
    casillas[1][0] = new Caballo(Colorpieza::NEGRO);
    casillas[2][0] = new Alfil(Colorpieza::NEGRO);
    casillas[3][0] = new Reina(Colorpieza::NEGRO);
    casillas[4][0] = new Rey(Colorpieza::NEGRO);
    casillas[5][0] = new Alfil(Colorpieza::NEGRO);
    casillas[6][0] = new Caballo(Colorpieza::NEGRO);
    casillas[7][0] = new Torre(Colorpieza::NEGRO);
    for (int i = 0; i < 8; i++)
        casillas[i][1] = new Peon(Colorpieza::NEGRO);

    // Blancas abajo (columna 6 y 7)
    for (int i = 0; i < 8; i++)
        casillas[i][6] = new Peon(Colorpieza::BLANCO);
    casillas[0][7] = new Torre(Colorpieza::BLANCO);
    casillas[1][7] = new Caballo(Colorpieza::BLANCO);
    casillas[2][7] = new Alfil(Colorpieza::BLANCO);
    casillas[3][7] = new Reina(Colorpieza::BLANCO);
    casillas[4][7] = new Rey(Colorpieza::BLANCO);
    casillas[5][7] = new Alfil(Colorpieza::BLANCO);
    casillas[6][7] = new Caballo(Colorpieza::BLANCO);
    casillas[7][7] = new Torre(Colorpieza::BLANCO);
}

void Tablero::mostrar() {
    cout << "  ";
    for (int fila = 7; fila >= 0; fila--) cout << fila + 1 << " ";
    cout << "\n";

    for (int col = 0; col < 8; col++) {
        cout << char('a' + col) << " ";
        for (int fila = 7; fila >= 0; fila--) {
            char simbolo = '.';
            Pieza* pieza = casillas[fila][col];
            if (pieza) {
                switch (pieza->getTipo()) {
                case TipoPieza::PEON: simbolo = 'P'; break;
                case TipoPieza::TORRE: simbolo = 'T'; break;
                case TipoPieza::CABALLO: simbolo = 'C'; break;
                case TipoPieza::ALFIL: simbolo = 'A'; break;
                case TipoPieza::REINA: simbolo = 'Q'; break;
                case TipoPieza::REY: simbolo = 'K'; break;
                default: simbolo = '?'; break;
                }
                if (pieza->getColor() == Colorpieza::BLANCO)
                    simbolo = tolower(simbolo);
            }
            cout << simbolo << ' ';
        }
        cout << "\n";
    }
}

bool Tablero::mover(int xIni, int yIni, int xFin, int yFin) {
    if (!casillas[xIni][yIni]) {
        cout << "No hay pieza en la casilla de origen.\n";
        return false;
    }
    Pieza* pieza = casillas[xIni][yIni];
    if (pieza->movimientoValido(yIni, xIni, yFin, xFin, *this)) {
        delete casillas[xFin][yFin];
        casillas[xFin][yFin] = pieza;
        casillas[xIni][yIni] = nullptr;
        aplicarGravedad(yFin);
        return true;
    }
    return false;
}

void Tablero::aplicarGravedad(int columna) {
    for (int fila = 6; fila >= 0; fila--) {
        if (casillas[fila][columna] != nullptr) {
            int destino = fila;
            while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr) {
                destino++;
            }
            if (destino != fila) {
                casillas[destino][columna] = casillas[fila][columna];
                casillas[fila][columna] = nullptr;
            }
        }
    }
}

void Tablero::jugabilidad() {
    inicializar();
    mostrar();
    string entrada;

    while (true) {
        cout << "Introduce el movimiento (ej. a2 a4) o 'salir': ";
        getline(cin, entrada);

        if (entrada == "salir") break;

        if (entrada.length() != 5 || entrada[2] != ' ') {
            cout << "Formato inválido. Usa: a2 a4\n";
            continue;
        }

        int xIni = entrada[1] - '1';
        int yIni = entrada[0] - 'a';
        int xFin = entrada[4] - '1';
        int yFin = entrada[3] - 'a';

        if (xIni < 0 || xIni >= 8 || yIni < 0 || yIni >= 8 ||
            xFin < 0 || xFin >= 8 || yFin < 0 || yFin >= 8) {
            cout << "Coordenadas fuera de rango.\n";
            continue;
        }

        if (mover(xIni, yIni, xFin, yFin)) {
            mostrar();
        }
        else {
            cout << "Movimiento inválido.\n";
        }
    }
}
