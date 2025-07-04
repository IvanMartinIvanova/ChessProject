#pragma once
#include "Partida.h"
#include "tablero.h"
#include "plataformaper.h"

class GestionPers
{
	PlataformaPer blanco{ 1, {-17,-5,0},{-13,-6,-5},{180,0,240} };
	PlataformaPer negro{ 0, {13,-5,0},{17,-6,-5},{0,0,240} };

public:
	void dibuja();
	void gestion();
};

