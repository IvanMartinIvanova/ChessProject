#pragma once
#include <math.h>
class Vector2D //clase con todo public = struct
{
public:
	double x;
	double y;
	double z;
	Vector2D normalizar(double x, double y);

	double modulo() const; //modulo del vector
	double argumento() const; //argumento del vector
	Vector2D unitario() const; //devuelve un vector unitario
	Vector2D operator - (const Vector2D&) const; //resta de vectores
	Vector2D operator + (const Vector2D&) const; //suma de vectores
	double operator *(const Vector2D&) const; // producto escalar
	Vector2D operator *(double) const; // producto por un escalar
};