#pragma once
#include "Vector3D.h"
#include "math.h"
#include "circulos.h"

constexpr int max_circulitos = 150;
class Estela
{
	static int counter;
	Vector3D org;
	Circulos circulitos[max_circulitos];

public:
	Estela();
	Estela(Vector3D pos);
	Estela(float pos, float posy, float posz);

	void setorg(const Vector3D& orgin);
	void dibuja();
};

