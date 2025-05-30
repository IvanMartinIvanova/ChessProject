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
	void escoger_player();
	bool Progress_Partida(DATOS_DIBUJO& dat);
	bool Progress_Partida_IA(DATOS_DIBUJO& dat);
	bool cargarDesdeArchivo(const std::string& nombreArchivo);
	void mostrarTablero();  // Nuevo método
	Tablero& getTablero();
	~Partida() = default;
	
};

