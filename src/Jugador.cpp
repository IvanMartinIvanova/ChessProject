#include "Jugador.h"
#include "tablero.h"
#include <iostream>
#include <string>

using namespace std;


bool Jugador::seleccion_casilla(Tablero& tab)
{
    string entrada;
    while (true)
    {
        cout << "Introduce el movimiento (Por ejemplo: b2 b3): ";
        getline(cin, entrada);
        // NUEVO BLOQUE: permitir guardar
        if (entrada == "guardar") {
            if (tab.guardarPartida("partida_guardada.txt")) {
                cout << "Partida guardada exitosamente.\n";
            }
            else {
                cout << "Error al guardar la partida.\n";
            }
            continue; // vuelve a pedir un movimiento
        }
        if (entrada == "guardar y salir") {
            if (tab.guardarPartida("partida_guardada.txt")) {
                cout << "Partida guardada exitosamente. Cerrando el juego...\n";
            }
            else {
                cout << "Error al guardar la partida. Cerrando de todos modos.\n";
            }
            exit(0); // termina el programa
        }


        if (entrada.length() != 5 || entrada[2] != ' ')
        {
            cout << "Formato inválido. Usa: b2 b4\n";

        }
        else
        {
            int ColumnaIni = entrada[1] - '1'; //Quitamos 1 al numero que introducimos ya que el jugador ve filas/columnas del (1-8) pero el vector de filas/columnas es de (0-7)
            int FilaIni = entrada[0] - 'a';
            int ColumnaFin = entrada[4] - '1';
            int FilaFin = entrada[3] - 'a';


            if (FilaIni < 0 || FilaIni >= 8 || ColumnaIni < 0 || ColumnaIni >= 8 ||
                FilaFin < 0 || FilaFin >= 8 || ColumnaFin < 0 || ColumnaFin >= 8) {
                cout << "Coordenadas fuera de rango.\n";

            }
           
            for (int i = 0; i < lista_piezas_actuales.lista_piezas.size(); i++)
            {
                if (lista_piezas_actuales.lista_piezas[i] == tab.getCasilla(FilaIni, ColumnaIni)) //Comprobamos si la casilla que ha seleccionado el jugador para mover hay una pieza suya
                {
                    if (mover(FilaIni, ColumnaIni, FilaFin, ColumnaFin, tab)) //Si se ha realizado correctamente el movimiento, entonces la función mover devuelve true
                    {
                        return true;
                    }
                }
            }
            cout << "La pieza seleccionada no es del Jugador que tiene el turno" << endl;
      
        }
    }

}


bool Jugador::mover(int FilIni, int ColIni, int FilFin, int ColFin, Tablero& tab) {

    if (!tab.getCasilla(FilIni,ColIni)) { //Comprueba si en la casilla seleccionada para mover hay o no una pieza
        cout << "No hay pieza en la casilla de origen.\n";
        return false;
    }

    Pieza* pieza = tab.getCasilla(FilIni, ColIni);
    for (int i = 0; i < lista_piezas_actuales.lista_piezas.size(); i++) //Verificamos la seleccion de casilla
    {
        if (lista_piezas_actuales.lista_piezas[i] == pieza) //Comprobamos si la casilla que ha seleccionado el jugador para mover hay una pieza suya
        {
            if (pieza->movimientoValido(FilIni, ColIni, FilFin, ColFin, tab)) { //Comprobamos si el movimiento de la pieza seleccionado es correcto
                tab.resetCasilla(FilFin, ColFin);
                tab.setCasilla(FilFin, ColFin, pieza); //Aplicamos el movimiento
                //Hay que llamar a una función para que guarde qué pieza se ha comido
                tab.resetCasilla(FilIni, ColIni);
                return true;
            }
        }
    }
    return false;
}