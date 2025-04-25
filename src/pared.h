#pragma once
#include "Color.h"
#include "Vector3D.h"

class Pared
{	
	friend class Interaccion;
private:
	Vector3D limite1,limite2;
	Color color;


public:
	Pared(const Vector3D& lim1, const Vector3D& lim2, const Color& col);
	Pared();
	void dibuja();
	void dibuja2();
	void set_color(Color& col);
	void cchange();
};


