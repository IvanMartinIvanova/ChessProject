#pragma once
#include "tablero.h"
class Partida
{
	Tablero tablero;
public:
	Partida();
	void escoger_player();
	bool Progress_Partida();
	~Partida() = default;
};

