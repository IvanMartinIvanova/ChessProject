#pragma once
#include "Vector3D.h"
#include "math.h"
#include "circulos.h"


class Estela
{
	static int counter;
	Vector3D org;
	Circulos circulitos[max];

public:
	Estela();
	Estela(Vector3D pos);
	Estela(float pos, float posy, float posz);

	void setorg(const Vector3D& orgin);
	void dibuja();
};

