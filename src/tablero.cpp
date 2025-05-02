//#include "tablero.h"
//#include <iostream>
//
//tablero::tablero() {
//    // Inicializa todas las casillas a nullptr
//    for (int y = 0; y < 8; y++) {
//        for (int x = 0; x < 8; x++) {
//            casillas[y][x] = nullptr;
//        }
//    }
//}
//
//tablero::~tablero() {
//    // Elimina todas las piezas en el tablero
//    for (int y = 0; y < 8; y++) {
//        for (int x = 0; x < 8; x++) {
//            delete casillas[y][x];
//        }
//    }
//}
//
//void tablero::inicializar() {
//    // Inicializar las piezas negras (fila 0 y 1)
//    casillas[0][0] = new torre(Colorpieza::NEGRO);
//    casillas[0][1] = new caballo(Colorpieza::NEGRO);
//    casillas[0][2] = new alfil(Colorpieza::NEGRO);
//    casillas[0][3] = new reina(Colorpieza::NEGRO);
//    casillas[0][4] = new rey(Colorpieza::NEGRO);
//    casillas[0][5] = new alfil(Colorpieza::NEGRO);
//    casillas[0][6] = new caballo(Colorpieza::NEGRO);
//    casillas[0][7] = new torre(Colorpieza::NEGRO);
//
//    for (int i = 0; i < 8; i++) {
//        casillas[1][i] = new peon(Colorpieza::NEGRO);  // Peones negros
//    }
//
//    // Inicializar las piezas blancas (fila 6 y 7)
//    casillas[7][0] = new torre(Colorpieza::BLANCO);
//    casillas[7][1] = new caballo(Colorpieza::BLANCO);
//    casillas[7][2] = new alfil(Colorpieza::BLANCO);
//    casillas[7][3] = new reina(Colorpieza::BLANCO);
//    casillas[7][4] = new rey(Colorpieza::BLANCO);
//    casillas[7][5] = new alfil(Colorpieza::BLANCO);
//    casillas[7][6] = new caballo(Colorpieza::BLANCO);
//    casillas[7][7] = new torre(Colorpieza::BLANCO);
//
//    for (int i = 0; i < 8; i++) {
//        casillas[6][i] = new peon(Colorpieza::BLANCO);  // Peones blancos
//    }
//}
//
//void tablero::mostrar() {
//    for (int y = 7; y >= 0; y--) {
//        std::cout << y + 1 << " ";
//        for (int x = 0; x < 8; x++) {
//            char simbolo = '.';
//            if (casillas[y][x]) {
//                switch (casillas[y][x]->getTipo()) {
//                case TipoPieza::PEON: simbolo = 'P'; break;
//                case TipoPieza::TORRE: simbolo = 'T'; break;
//                case TipoPieza::CABALLO: simbolo = 'C'; break;
//                case TipoPieza::ALFIL: simbolo = 'A'; break;
//                case TipoPieza::REINA: simbolo = 'Q'; break;
//                case TipoPieza::REY: simbolo = 'K'; break;
//                default: simbolo = '?'; break;
//                }
//
//                if (casillas[y][x]->getColor() == Colorpieza::NEGRO)
//                    simbolo = tolower(simbolo);
//            }
//            std::cout << simbolo << ' ';
//        }
//        std::cout << '\n';
//    }
//    std::cout << "  a b c d e f g h\n";
//}
//
//bool tablero::mover(int xIni, int yIni, int xFin, int yFin) {
//    // Verifica si la casilla de inicio está ocupada por una pieza
//    if (!casillas[yIni][xIni]) return false;
//
//    pieza* pieza = casillas[yIni][xIni];
//
//    // Verifica si el movimiento es válido para esa pieza
//    if (pieza->movimientoValido(xIni, yIni, xFin, yFin, *this)) {
//        // Si el movimiento es válido, realizamos la captura (si corresponde)
//        delete casillas[yFin][xFin];  // Se come la pieza que estaba en la casilla destino
//        casillas[yFin][xFin] = pieza; // Movemos la pieza a la nueva casilla
//        casillas[yIni][xIni] = nullptr; // Limpiamos la casilla de origen
//
//        aplicarGravedad(xFin); // Aplicar la gravedad en la columna de destino
//        return true;
//    }
//
//    return false;
//}
//
//void tablero::aplicarGravedad(int columna) {
//    // Aplica la gravedad en la columna especificada
//    for (int fila = 6; fila >= 0; fila--) {
//        if (casillas[fila][columna] != nullptr) {
//            int destino = fila;
//            while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr) {
//                destino++;  // Desciende la pieza
//            }
//
//            if (destino != fila) {
//                // Mueve la pieza hacia abajo hasta la casilla vacía
//                casillas[destino][columna] = casillas[fila][columna];
//                casillas[fila][columna] = nullptr;
//            }
//        }
//    }
//}
//
