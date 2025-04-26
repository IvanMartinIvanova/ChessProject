#pragma once
#include "Vector3D.h"
#include "freeglut.h"
#include "Color.h"

class Cara
{
public:
	Vector3D esq1, esq2;
	Color color;

public:
	Cara();
	Cara(Vector3D in1, Vector3D in2, Color col);
	Cara(float in1x, float in1y, float in1z, float in2x, float in2y, float in2z, Color col);


	void setpos(const Vector3D& in1, const Vector3D& in2, const Color& cin);
	void dibuja();
	void dibujaxy();
	void dibujaz();
};

