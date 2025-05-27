#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida() {
	// no inicializo para el guardado de partidas
}

void Partida::inicializar() {
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
	cout << "¿Deseas guardar la partida? (s/n): ";
	char resp; cin >> resp;
	if (resp == 's' || resp == 'S') {
		if (tablero.guardarPartida("partida_guardada.txt"))
			cout << "Partida guardada exitosamente.\n";
		else
			cout << "Error al guardar la partida.\n";
	}
	return false;
}
bool Partida::cargarDesdeArchivo(const std::string& nombreArchivo) {
	return tablero.cargarPartida(nombreArchivo);
}
void Partida::mostrarTablero() {
	tablero.mostrar();
}

