#include "tablero.h"
#include <iostream>
#include <string>
using namespace std;

Tablero::Tablero() {
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            casillas[fila][col] = nullptr;
}

Tablero::~Tablero() {
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            delete casillas[fila][col];
}

void Tablero::inicializar() {
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            casillas[fila][col] = nullptr;

    // Negras derecha (columna 6 y 7)
    casillas[0][7] = new Torre(Colorpieza::NEGRO);
    casillas[1][7] = new Caballo(Colorpieza::NEGRO);
    casillas[2][7] = new Alfil(Colorpieza::NEGRO);
    casillas[3][7] = new Reina(Colorpieza::NEGRO);
    casillas[4][7] = new Rey(Colorpieza::NEGRO);
    casillas[5][7] = new Alfil(Colorpieza::NEGRO);
    casillas[6][7] = new Caballo(Colorpieza::NEGRO);
    casillas[7][7] = new Torre(Colorpieza::NEGRO);

    for (int i = 0; i < 8; i++)
        casillas[i][6] = new Peon(Colorpieza::NEGRO);

    // Blancas izquierda (columna 0 y 1)
    for (int i = 0; i < 8; i++)
        casillas[i][1] = new Peon(Colorpieza::BLANCO);

    casillas[0][0] = new Torre(Colorpieza::BLANCO);
    casillas[1][0] = new Caballo(Colorpieza::BLANCO);
    casillas[2][0] = new Alfil(Colorpieza::BLANCO);
    casillas[3][0] = new Reina(Colorpieza::BLANCO);
    casillas[4][0] = new Rey(Colorpieza::BLANCO);
    casillas[5][0] = new Alfil(Colorpieza::BLANCO);
    casillas[6][0] = new Caballo(Colorpieza::BLANCO);
    casillas[7][0] = new Torre(Colorpieza::BLANCO);
}

void Tablero::mostrar() {
    cout << "  ";
    for (int col = 0; col <= 7; col++) cout << col + 1 << " "; //Imprime los numeros de columnas
    cout << "\n";

    for (int fila = 0; fila <= 7; fila++) {
        cout << char('a' + fila) << " "; //Imprime las letras de las filas
        for (int col = 0; col <= 7; col++) {
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

bool Tablero::mover(int FilIni, int ColIni, int FilFin, int ColFin) {
    if (!casillas[FilIni][ColIni]) { //Comprueba si en la casilla seleccionada para mover hay o no una pieza
        cout << "No hay pieza en la casilla de origen.\n";
        return false;
    }

    Pieza* pieza = casillas[FilIni][ColIni];
    if (pieza->movimientoValido(FilIni, ColIni, FilFin, ColFin, *this)) {
        delete casillas[FilFin][ColFin];
        casillas[FilFin][ColFin] = pieza;
        //Hay que llamar a una función para que guarde qué pieza se ha comido
        casillas[FilIni][ColIni] = nullptr;
        aplicarGravedad();
        return true;
    }
    return false;
}

void Tablero::aplicarGravedad() {
    for (int columna = 0; columna <= 7; columna++)
    {
        for (int fila = 7; fila >= 0; fila--) {
            if (casillas[fila][columna] != nullptr) {
                int destino = fila; //Destino es un flag que nos ayudará a saber si hay hueco libre debajo de una pieza y almacenar la posición hasta la que puede bajar una pieza

                while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr) { //Hay espacio debajo de la pieza
                    destino++;
                }
                if (destino != fila) { //Ha cambiado el flag por lo que hay espacio debajo de la pieza

                    casillas[destino][columna] = casillas[fila][columna]; //Movemos la pieza
                    casillas[fila][columna] = nullptr; //Dejamos libre el sitio en el que estaba
                }
            }
        }
    }
}

void Tablero::jugabilidad() {
    inicializar();
    mostrar();
    string entrada;

    while (true) {
        cout << "Introduce el movimiento (Por ejemplo: b2 b3) o 'salir': ";
        getline(cin, entrada);

        if (entrada == "salir") break;

        if (entrada.length() != 5 || entrada[2] != ' ') {
            cout << "Formato inválido. Usa: b2 b4\n";
            continue;
        }

        int ColumnaIni = entrada[1] - '1'; //Quitamos 1 al numero que introducimos ya que el jugador ve filas/columnas del (1-8) pero el vector de filas/columnas es de (0-7)
        int FilaIni = entrada[0] - 'a';
        int ColumnaFin = entrada[4] - '1';
        int FilaFin = entrada[3] - 'a';

        if (FilaIni < 0 || FilaIni >= 8 || ColumnaIni < 0 || ColumnaIni >= 8 ||
            FilaFin < 0 || FilaFin >= 8 || ColumnaFin < 0 || ColumnaFin >= 8) {
            cout << "Coordenadas fuera de rango.\n";
            continue;
        }

        if (mover(FilaIni, ColumnaIni, FilaFin, ColumnaFin)) {
            mostrar();
        }
        else {
            cout << "Movimiento inválido.\n";
        }
    }
}