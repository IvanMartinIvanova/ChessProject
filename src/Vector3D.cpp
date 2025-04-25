#include "Vector3D.h"

Vector3D::Vector3D()
{}

Vector3D::Vector3D(float inx, float iny, float inz) :

	x{ inx },
	y{ iny },
	z{ inz }
{
}

float Vector3D::modulo() const
{
	return sqrt(x * x + y * y);
}

float Vector3D::argumento() const
{
	return atan2(y, x);
}

Vector3D Vector3D::unitario() const
{
	float mod = modulo();
	if (mod > 0.00001)
		return { x / mod, y / mod, z / mod };
	return { x,y,z };
}

Vector3D operator*(float e, const Vector3D& v)
{
	return v * e;
}

Vector3D Vector3D::operator - (const Vector3D& v) const //resta de vectores
{
	return { x - v.x,y - v.y, z-v.z };
}

Vector3D Vector3D::operator + (const Vector3D& v) const //suma de vectores
{
	return { x + v.x,y + v.y,z + v.z };
}

float Vector3D::operator *(const Vector3D& v) const // producto escalar
{
	return { x * v.x + y * v.y + z * v.z };
}


Vector3D Vector3D::operator *(float e) const // producto por un escalar
{
	return{ x * e , y + e, z + e };
}

void Vector3D::print()
{
	std::cout << x << " " << y << " " << z << std::endl;
}