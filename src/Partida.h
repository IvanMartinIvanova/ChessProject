#pragma once
#include "tablero.h"
#include "DATOS_DIBUJO.h"

class Partida
{
	Tablero tablero;
	bool estado_JAQUE;
public:
	Partida();
	void inicializar();  // Método para nueva partida
	void inicializar_IA();

	bool escoger_player(char key, Jugador& player);
	bool Progress_Partida(DATOS_DIBUJO& dat, char key);
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo método
	Tablero& getTablero();
	bool get_estado_Jaque();
	~Partida() = default;
	bool Progress_Partida_IA(DATOS_DIBUJO& dat, char key);
	bool guardar_partida();
	bool guardar_partida(const std::string& nombreArchivo);
	bool cargar_partida(const std::string& nombreArchivo);

	
};

