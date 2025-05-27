#pragma once
#include "tablero.h"
class Partida
{
	Tablero tablero;
	bool estado_JAQUE;
public:
	Partida();
	void inicializar();  // M�todo para nueva partida
	void escoger_player();
	bool Progress_Partida();
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo m�todo
	Tablero getTablero();
	~Partida() = default;
	
};

