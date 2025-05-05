#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"
#include "freeglut.h"

class Sprite3D
{
	ETSIDI::Sprite* dir;
	Vector3D pos;

public:
	Sprite3D();
	Sprite3D(Vector3D posin, ETSIDI::Sprite* dirin);	
	
	void draw();
};


