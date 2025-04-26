#pragma once
#include "estela.h"
#include "Color.h"
#include "freeglut.h"
#include "cara.h"

class Plataforma
{
public:
	static float counter;
	Vector3D limite1, limite2;
	Vector3D limest1, limest2;
	Cara cara1, cara2, cara3, cara4, cara5, cara6;
	Estela estela{ (limite1.x + limite2.x) / 2,(limite1.y + limite2.y) / 2, limite2.z };
	//Estela estela{ 0,0,0 };
	Color color;


public:
	Plataforma(const Vector3D& lim1, const Vector3D& lim2, const Color& col);
	Plataforma();
	void dibuja();
	void calcidle();
	void setpos();
	void set_color(Color& col);
};

