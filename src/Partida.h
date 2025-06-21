#pragma once
#include "tablero.h"
#include "DATOS_DIBUJO.h"

class Partida
{
	Tablero tablero;
	bool estado_JAQUE;
public:
	Partida();
	void inicializar();  // M�todo para nueva partida
	void inicializar_IA();

	void escoger_player();
	bool Progress_Partida(DATOS_DIBUJO& dat, char key);
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo m�todo
	Tablero& getTablero();
	~Partida() = default;
	
};

