#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"

class Sprite3D
{
	ETSIDI::Sprite* dir;
	Vector3D pos;

	void draw();

};

