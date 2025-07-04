#pragma once
#include "personaje.h"
#include "plataforma.h"
class PlataformaPer : Plataforma
{
	Personaje* personaje;

public:
	PlataformaPer();
	PlataformaPer(const bool color, const Vector3D& lim1, const Vector3D& lim2, const Color& col);
	void dibuja();

	void setstate(Personaje* statein);
	int getstage() { return personaje->getstage(); }
};

