#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida() {
	// no inicializo para el guardado de partidas
}

void Partida::inicializar() {
	tablero.inicializar();
	tablero.mostrar();
	estado_JAQUE = false;
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

bool Partida::Progress_Partida(DATOS_DIBUJO& dat)
{
	DATOS_DIBUJO datos;
	tablero.mostrar();
	return tablero.gestion_turnos(this->estado_JAQUE, datos);
	
}
bool Partida::cargarDesdeArchivo(const std::string& nombreArchivo) {
	return tablero.cargarPartida(nombreArchivo);
}
void Partida::mostrarTablero() {
	tablero.mostrar();
}

Tablero& Partida::getTablero()
{
	return this->tablero;
}

