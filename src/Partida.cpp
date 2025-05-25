#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida()
{
	tablero.inicializar();
	tablero.mostrar();
	tablero.player1.Turno = true;
	tablero.player2.Turno = false;
}

void Partida::escoger_player()
{
	char intro;
	cout << "Jugador 1 (Blancas) inserte su nombre:" << endl;
	getline(cin, tablero.player1.Nombre);

	cout << "Jugador 2 (Negras) inserte su nombre:" << endl;
	getline(cin, tablero.player2.Nombre);
}

bool Partida::Progress_Partida()
{
	tablero.gestion_turnos();
	return false;
}