#pragma once
#include <math.h>
#include <iostream>

class Vector3D
{
public:
	float x;
	float y;
	float z;
	Vector3D();
	Vector3D(float inx, float iny, float inz);

	float modulo() const; //modulo del vector
	float argumento() const; //argumento del vector
	Vector3D unitario() const; //devuelve un vector unitario
	Vector3D operator - (const Vector3D&) const; //resta de vectores
	Vector3D operator + (const Vector3D&) const; //suma de vectores
	float operator *(const Vector3D&) const; // producto escalar
	Vector3D operator *(float) const; // producto por un escalar
	void print();

};

