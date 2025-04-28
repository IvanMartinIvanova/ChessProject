#pragma once
#include "Vector3D.h"
#include "freeglut.h"
#include "Color.h"
#include "ETSIDI.h"

class Cara
{
public:
	Vector3D esq1, esq2;
	Color color;
	std::string text;

public:
	Cara();
	Cara(Vector3D in1, Vector3D in2, Color col, std::string textin = "-1");
	Cara(float in1x, float in1y, float in1z, float in2x, float in2y, float in2z, Color col, std::string textin = "-1");


	void setpos(const Vector3D& in1, const Vector3D& in2, const Color& cin);
	void dibuja();
	void dibujaxy();
	void dibujaz();
};

