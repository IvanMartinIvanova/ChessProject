#include "Jugador.h"
#include "tablero.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

Jugador::Jugador(): points({0.0,0.0,0.0,0.0}), temp({0,0}), Turno(false)
{

}
Jugador& Jugador::operator=(const Jugador& player) {
    if (this != &player)
    {
        lista_piezas_actuales = player.lista_piezas_actuales;
        lista_piezas_comidas = player.lista_piezas_comidas;
        points = player.points;
        temp = player.temp;
        Nombre = player.Nombre;
        Turno = player.Turno;
    }
    return *this;
}
//bool Jugador::seleccion_casilla(Tablero& tab, DATOS_DIBUJO& dat)
//{
//    string entrada;
//    while (true)
//    {
//        cout << "Introduce el movimiento (Por ejemplo: b2 b3): ";
//        getline(cin, entrada);
//        // NUEVO BLOQUE: permitir guardar
//        if (entrada == "guardar") {
//            if (tab.guardarPartida("partida_guardada.txt")) {
//                cout << "Partida guardada exitosamente.\n";
//            }
//            else {
//                cout << "Error al guardar la partida.\n";
//            }
//            continue; // vuelve a pedir un movimiento
//        }
//        if (entrada == "guardar y salir") {
//            if (tab.guardarPartida("partida_guardada.txt")) {
//                cout << "Partida guardada exitosamente. Cerrando el juego...\n";
//            }
//            else {
//                cout << "Error al guardar la partida. Cerrando de todos modos.\n";
//            }
//            exit(0); // termina el programa
//        }
//
//
//        if (entrada.length() != 5 || entrada[2] != ' ')
//        {
//            cout << "Formato inválido. Usa: b2 b4" << endl;
//
//        }
//        else
//        {
//            int ColumnaIni = entrada[1] - '1'; //Quitamos 1 al numero que introducimos ya que el jugador ve filas/columnas del (1-8) pero el vector de filas/columnas es de (0-7)
//            int FilaIni = entrada[0] - 'a';
//            int ColumnaFin = entrada[4] - '1';
//            int FilaFin = entrada[3] - 'a';
//
//
//            if (FilaIni < 0 || FilaIni >= 8 || ColumnaIni < 0 || ColumnaIni >= 8 ||
//                FilaFin < 0 || FilaFin >= 8 || ColumnaFin < 0 || ColumnaFin >= 8) 
//            {
//                cout << "Coordenadas fuera de rango" << endl;
//
//            }
//            else
//            {
//
//                if (!tab.getCasilla(FilaIni, ColumnaIni)) { //Comprueba si en la casilla seleccionada para mover hay o no una pieza
//                    cout << "No hay pieza en la casilla de origen.\n";
//                }
//                else
//                {
//
//                    for (int i = 0; i < lista_piezas_actuales.lista_piezas.size(); i++)
//                    {
//                        if (lista_piezas_actuales.lista_piezas[i] == tab.getCasilla(FilaIni, ColumnaIni)) //Comprobamos si la casilla que ha seleccionado el jugador para mover hay una pieza suya
//                        {
//                            if (tab.mover(FilaIni, ColumnaIni, FilaFin, ColumnaFin,*this,dat)) //Si se ha realizado correctamente el movimiento, entonces la función mover devuelve true
//                            {
//                                return true;
//                            }
//                           
//                        }
//                    }
//                    cout << "La pieza seleccionada no es del Jugador que tiene el turno" << endl;
//                }
//            }
//      
//        }
//    }
//
//}

void Jugador::actualizar_listas(Jugador& player)
{

    for (int i = 0; i < player.lista_piezas_comidas.size(); i++) //Verificamos la lista de las piezas que ha comido el jugador que se pasa a la función como argumento del jugador que llama a la función
    {
        Pieza* pieza_comida = player.lista_piezas_comidas.obtener_pieza(i);

        for (int j = 0; j < this->lista_piezas_actuales.size(); j++)
        {
            
            if (pieza_comida == lista_piezas_actuales.obtener_pieza(j))
            {
                this->lista_piezas_actuales.eliminar(pieza_comida); //Eliminamos la pieza del jugador que llama a la función que hayan sido comidas por el jugador que se pasa como argumento
                return;
            }
        }
    }
    return;

}

bool Jugador::seleccion_casilla(Tablero& tab, DATOS_DIBUJO& dat)
{
    int fila_cursor = 0, col_cursor = 0;
    int fila_ini = -1, col_ini = -1;
    bool continuar = true;

   // while (continuar)
   // {
        system("cls");
        std::cout << "(WASD para mover, ENTER para seleccionar, T = texto, G = guardar, Q = guardar y salir)\n";
        std::cout << "Turno de " << this->Nombre << endl;
        tab.mostrarConCursor(fila_cursor, col_cursor);

        char tecla = _getch();

        switch (tecla)
        {
        case 'w': if (fila_cursor > 0) fila_cursor--; break;
        case 's': if (fila_cursor < 7) fila_cursor++; break;
        case 'a': if (col_cursor > 0) col_cursor--; break;
        case 'd': if (col_cursor < 7) col_cursor++; break;

        case 'g': {
            if (tab.guardarPartida("partida_guardada.txt"))
                std::cout << "Partida guardada.\n";
            else
                std::cout << "Error al guardar la partida.\n";
            _getch();
            break;
        }

        case 'q': {
            if (tab.guardarPartida("partida_guardada.txt"))
                std::cout << "Guardado y salida exitosa.\n";
            else
                std::cout << "Guardado fallido. Cerrando de todos modos.\n";
            exit(0);
        }

        case 't': {  //  modo texto
            std::string entrada;
            std::cout << "\nIntroduce el movimiento (Ej: b2 b3): ";
            std::getline(std::cin, entrada);

            if (entrada == "guardar") {
                tab.guardarPartida("partida_guardada.txt");
                std::cout << "Partida guardada.\n";
                _getch();
                break;
            }
            if (entrada == "guardar y salir") {
                tab.guardarPartida("partida_guardada.txt");
                std::cout << "Partida guardada. Cerrando...\n";
                exit(0);
            }

            if (entrada.length() == 5 && entrada[2] == ' ') {
                int col_ini = entrada[0] - 'a';
                int fila_ini = entrada[1] - '1';
                int col_fin = entrada[3] - 'a';
                int fila_fin = entrada[4] - '1';

                if (tab.mover(fila_ini, col_ini, fila_fin, col_fin, *this, dat))
                    return true;
                else {
                    std::cout << "Movimiento inválido.\n";
                    _getch();
                }
            }
            break;
        }

        case '\r':  // ENTER para seleccionar
            if (fila_ini == -1) {
                // ORIGEN
                Pieza* seleccion = tab.getCasilla(fila_cursor, col_cursor);
                if (seleccion) {
                    for (Pieza* p : lista_piezas_actuales.lista_piezas) {
                        if (p == seleccion) {
                            fila_ini = fila_cursor;
                            col_ini = col_cursor;
                            break;
                        }
                    }
                }
            }
            else {
                // DESTINO
                if (tab.mover(fila_ini, col_ini, fila_cursor, col_cursor, *this, dat)) {
                    return true;
                }
                else {
                    std::cout << "Movimiento inválido.\n";
                    _getch();
                }
                fila_ini = -1;
                col_ini = -1;
            }
            break;

        default: break;
        }
   // }

    return false;
}


