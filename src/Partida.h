#pragma once
#include "tablero.h"
class Partida
{
	Tablero tablero;
	bool estado_JAQUE;
public:
	Partida();
	void inicializar();  // Método para nueva partida
	void escoger_player();
	bool Progress_Partida();
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo método
	Tablero getTablero();
	~Partida() = default;
	
};

