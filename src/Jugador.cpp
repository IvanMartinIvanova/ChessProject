#include "Jugador.h"
#include "tablero.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;




int Jugador::fila_cursor = 0;
int Jugador::col_cursor = 0;
int Jugador::fila_ini = -1;
int Jugador::col_ini = -1;


Jugador::Jugador(): points({0.0,0.0,0.0,0.0}), temp({0,0}), Turno{false}, Movimientos{0}
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

string Jugador::get_Name()
{
    return this->Nombre;
}

void Jugador::reset_Name()
{
    this->Nombre = "";
}

bool Jugador::get_Turno()
{
    return this->Turno;
}

int Jugador::get_nMov()
{
    return this->Movimientos;
}

Puntuacion Jugador::get_Punt()
{
    return this->points;
}
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
            }
        }
    }
    return;

}

bool Jugador::seleccion_casilla(Tablero& tab, DATOS_DIBUJO& dat, char key, Jugador& player_turnoInactivo)
{
    bool continuar = true;

   // while (continuar)
   // {
        /*system("cls");
        std::cout << "(WASD para mover, ENTER para seleccionar, T = texto, G = guardar, Q = guardar y salir)\n";
        std::cout << "Turno de " << this->Nombre << endl;*/
        //tab.mostrarConCursor(fila_cursor, col_cursor);


        switch (key)
        {
        case 'w': if (fila_cursor > 0) fila_cursor--; break;
        case 's': if (fila_cursor < 7) fila_cursor++; break;
        case 'a': if (col_cursor > 0) col_cursor--; break;
        case 'd': if (col_cursor < 7) col_cursor++; break;

        case ' ':  // ESPACIO para seleccionar
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
                if (tab.mover(fila_ini, col_ini, fila_cursor, col_cursor, *this, player_turnoInactivo, dat)) {
                    fila_ini = -1;
                    col_ini = -1;
                    return true;
                }
                else {
                    std::cout << "Movimiento inválido.\n";
                    //_getch();
                }
                fila_ini = -1;
                col_ini = -1;
            }
            break;

        default: break;
        }
   // }
    tab.mostrarConCursor(fila_cursor, col_cursor);
    return false;
}

void Jugador::calc_punt(Colorpieza Color)
{
    float puntuacion1 = 0.0;
    float puntuacion2 = 0.0;
    for (int i = 0; i < this->lista_piezas_actuales.lista_piezas.size(); i++)
    {
        if (this->lista_piezas_actuales.lista_piezas[i]->color == Color)
        {
            switch (this->lista_piezas_actuales.lista_piezas[i]->getTipo())
            {
            case TipoPieza::PEON:
                puntuacion1 += 1.0;
                break;
            case TipoPieza::ALFIL:
                puntuacion1 += 3.0;
                break;
            case TipoPieza::CABALLO:
                puntuacion1 += 3.0;
                break;
            case TipoPieza::TORRE:
                puntuacion1 += 5.0;
                break;
            case TipoPieza::REINA:
                puntuacion1 += 9.0;
                break;
            }
        }
    }
    this->points.Puntos_remaining_piezas = puntuacion1;

    for (int i = 0; i < this->lista_piezas_comidas.lista_piezas.size(); i++)
    {
        if (this->lista_piezas_comidas.lista_piezas[i]->color != Color) //No se tiene en cuenta para la puntuación las piezas del mismo color comidas, solo las piezas del otro jugador
        {
            switch (this->lista_piezas_comidas.lista_piezas[i]->getTipo())
            {
            case TipoPieza::PEON:
                puntuacion2 += 1.0;
                break;
            case TipoPieza::ALFIL:
                puntuacion2 += 3.0;
                break;
            case TipoPieza::CABALLO:
                puntuacion2 += 3.0;
                break;
            case TipoPieza::TORRE:
                puntuacion2 += 5.0;
                break;
            case TipoPieza::REINA:
                puntuacion2 += 9.0;
                break;
            }
        }
    }
    this->points.Puntos_piezas_comidas = puntuacion2;

    this->points.Puntos_totales = puntuacion1 + puntuacion2;
}



