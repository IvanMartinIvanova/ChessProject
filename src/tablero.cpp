#include "tablero.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Tablero::Tablero() {
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col< 8; col++)
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

    for (int i = 7; i >= 6; i--) //Agregamos las piezas del player 2 a la lista de sus piezas sobre el tablero (Guarda primero la columna de figuras y luego la de peones)
    {
        for (int j = 0; j < 8; j++)
            player2.lista_piezas_actuales.agregar(casillas[j][i]);
    }

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

    for (int i = 0; i <= 1; i++) //Agregamos las piezas del player 2 a la lista de sus piezas sobre el tablero (Guarda primero la columna de figuras y luego la de peones)
    {
        for (int j = 0; j < 8; j++)
            player1.lista_piezas_actuales.agregar(casillas[j][i]);
    }
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

//bool Tablero::mover(int FilIni, int ColIni, int FilFin, int ColFin) {
//    if (!casillas[FilIni][ColIni]) { //Comprueba si en la casilla seleccionada para mover hay o no una pieza
//        cout << "No hay pieza en la casilla de origen.\n";
//        return false;
//    }
//
//    Pieza* pieza = casillas[FilIni][ColIni];
//    if (pieza->movimientoValido(FilIni, ColIni, FilFin, ColFin, *this)) {
//        delete casillas[FilFin][ColFin];
//        casillas[FilFin][ColFin] = pieza;
//        //Hay que llamar a una función para que guarde qué pieza se ha comido
//        casillas[FilIni][ColIni] = nullptr;
//        aplicarGravedad();
//        return true;
//    }
//    return false;
//}

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

void Tablero::gestion_turnos() {
    string entrada;

    while(true)
    {
        if (player1.Turno)
        {
            cout << "Turno de Jugador 1:" << endl;
            if (player1.seleccion_casilla(*this)) //TRUE si el movimiento se ha realizado correctamente
            {
                aplicarGravedad(); //Aplicamos la gravedad al movimiento
                mostrar();
                player1.Turno = false;
                player2.Turno = true;
            }
               
        }
        else
        {
            cout << "Turno de Jugador 2:" << endl;
            if (player2.seleccion_casilla(*this))
            {
                aplicarGravedad();
                mostrar();
                player2.Turno = false;
                player1.Turno = true;
            } 
        }

    }
}

bool Tablero::guardarPartida(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) return false;

    archivo << "JUGADOR1: " << player1.Nombre << "\n";
    archivo << "JUGADOR2: " << player2.Nombre << "\n";
    archivo << "TURNO: " << (player1.Turno ? 1 : 2) << "\n";
    archivo << "TABLERO:\n";

    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            Pieza* pieza = casillas[fila][col];
            if (pieza) {
                archivo << static_cast<int>(pieza->getTipo()) << " "
                    << static_cast<int>(pieza->getColor()) << " "
                    << fila << " " << col << "\n";
            }
        }
    }

    archivo.close();
    return true;
}

bool Tablero::cargarPartida(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return false;

    string linea;
    int turno;
    getline(archivo, linea); player1.Nombre = linea.substr(10);
    getline(archivo, linea); player2.Nombre = linea.substr(10);
    getline(archivo, linea); turno = stoi(linea.substr(7));
    player1.Turno = (turno == 1);
    player2.Turno = !player1.Turno;

    // Limpiar tablero actual
    for (int f = 0; f < 8; ++f)
        for (int c = 0; c < 8; ++c)
            casillas[f][c] = nullptr;

    player1.lista_piezas_actuales = ListaPiezas();
    player2.lista_piezas_actuales = ListaPiezas();

    getline(archivo, linea); // "TABLERO:"
    int tipo, color, fila, col;

    while (archivo >> tipo >> color >> fila >> col) {
        Pieza* nueva = nullptr;
        Colorpieza colP = static_cast<Colorpieza>(color);

        switch (static_cast<TipoPieza>(tipo)) {
        case TipoPieza::PEON: nueva = new Peon(colP); break;
        case TipoPieza::TORRE: nueva = new Torre(colP); break;
        case TipoPieza::CABALLO: nueva = new Caballo(colP); break;
        case TipoPieza::ALFIL: nueva = new Alfil(colP); break;
        case TipoPieza::REINA: nueva = new Reina(colP); break;
        case TipoPieza::REY: nueva = new Rey(colP); break;
        default: break;
        }

        if (nueva) {
            casillas[fila][col] = nueva;
            if (colP == Colorpieza::BLANCO)
                player1.lista_piezas_actuales.agregar(nueva);
            else
                player2.lista_piezas_actuales.agregar(nueva);
        }
    }

    return true;
}