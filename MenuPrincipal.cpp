#include "lib/freeglut.h"
#include "lib/ETSIDI.h"
#include "math.h"
#include "mundo.h"
#include "tablero.h"
#include <iostream>



//int main() {
//    Tablero tablero;
//    tablero.inicializar();
//    tablero.mostrar();
//
//    int x1, y1, x2, y2;
//    while (true) {
//        std::cout << "\nMover pieza (x1 y1 x2 y2), o -1 para salir: ";
//        std::cin >> x1;
//        if (x1 == -1) break;
//        std::cin >> y1 >> x2 >> y2;
//
//        if (!tablero.mover(x1, y1, x2, y2)) {
//            std::cout << "Movimiento inválido.\n";
//        }
//
//        tablero.mostrar();
//    }
//
//    return 0;
//}