#pragma once
#include "tablero.h"
#include "DATOS_DIBUJO.h"
#include "personaje.h"

class Partida
{
	Tablero tablero;
	bool estado_JAQUE;
	bool gana_player1;
	bool gana_player2;

public:
	Partida();
	void inicializar(const int& skin_p1, const int& skin_p2);  // Método para nueva partida

	bool escoger_player(char key, Jugador& player);
	bool escoger_skin(char key, int& skin);
	bool Progress_Partida(DATOS_DIBUJO& dat, char key);
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo método
	Tablero& getTablero();
	bool get_estado_Jaque();
	bool get_gana_p1();
	bool get_gana_p2();
	void set_estado_Jaque(bool jaque);
	~Partida() = default;
	bool Progress_Partida_IA(DATOS_DIBUJO& dat, char key);
	bool guardar_partida();
	bool guardar_partida(const std::string& nombreArchivo);
	bool cargar_partida(const std::string& nombreArchivo);

	
};

