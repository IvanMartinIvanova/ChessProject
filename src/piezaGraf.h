#pragma once
#include "vectabl.h"
#include "ETSIDI.h"
#include <map>
#include <string>

class PiezaGraf
{
	std::string pieza;
	VecTabl pos;

	PiezaGraf();
	PiezaGraf(std::string pie, VecTabl pos);
};


