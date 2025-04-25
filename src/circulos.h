#pragma once
#include "Vector3D.h"

constexpr float dmax = 5;
constexpr int max = 7;
constexpr float ddif = 0.1;

class Circulos
{
	Vector3D pos;
	float radio;

public:
	void setpos(Vector3D posin);
	float calcrad(Vector3D posin);
	void drawcirc(Vector3D posin);
	void calcpos(Vector3D posin);
};

