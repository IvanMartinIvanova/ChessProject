#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"
#include "freeglut.h"

class Sprite3D
{
	char dir[255];
	char dirc;
	Vector3D pos;

public:
	Sprite3D();
	Sprite3D(Vector3D posin, ETSIDI::Sprite* dirin);	
	
	void draw();
};


