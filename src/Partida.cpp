#include "Partida.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

Partida::Partida() {
	// no inicializo para el guardado de partidas
}

void Partida::inicializar(const int& skin_p1, const int& skin_p2) {
	tablero.inicializar(skin_p1, skin_p2);
	estado_JAQUE = false;
	tablero.player1.Turno = true;
	tablero.player2.Turno = false;
	tablero.player1.Nombre.clear();
	tablero.player2.Nombre.clear();
	
}

//void Partida::inicializar_IA() {
//
//	tablero.inicializar();
//	tablero.mostrar();
//	estado_JAQUE = false;
//	bool turnoIA = false, turno_jug = true;
//	Jugador& jug_hum = tablero.getPlayer1();
//	Jugador& IA = tablero.getPlayer2();
//}


bool Partida::escoger_player(char key, Jugador& player)
{
	char tecla = key;
	
		if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
		{
			player.Nombre.push_back(key);
		}
		else if (key == '\b')
		{
			if (player.Nombre.size() > 0)
			player.Nombre.pop_back(); //Para eliminar el último caracter de la cadena
		}
		else if (key == '\r')
		{
		return true;
		}
		
		return false;
			
}

bool Partida::escoger_skin(char key, int& skin)
{
	char tecla = key;
	if (key >= '1' && key <= '3')
	{
			skin = key - '0';
			return true;
	}
	return false;
}


bool Partida::Progress_Partida(DATOS_DIBUJO& dat, char key)
{
	char tecla = key;
	system("cls");
	if (tablero.player1.Turno)
	{
		cout << "Turno de " << tablero.player1.Nombre << endl;
	}
	else
	{
		cout << "Turno de " << tablero.player2.Nombre << endl;
	}
	return tablero.gestion_turnos(this->estado_JAQUE, dat, tecla);
}

bool Partida::Progress_Partida_IA(DATOS_DIBUJO& dat, char key)
{
	char tecla = key;
	system("cls");
	if (tablero.player1.Turno)
	{
		cout << "Turno de " << tablero.player1.Nombre << endl;
	}
	else
	{
		cout << "Turno de " << tablero.player2.Nombre << endl;
	}
	return tablero.gestion_turnos_con_IA(this->estado_JAQUE, dat, tablero, tecla);
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

bool Partida::get_estado_Jaque()
{
	return this->estado_JAQUE;
}

bool Partida::guardar_partida(const std::string& nombreArchivo) {
	return tablero.guardarPartida(nombreArchivo);
}

bool Partida::cargar_partida(const std::string& nombreArchivo) {
	return tablero.cargarPartida(nombreArchivo);
}

