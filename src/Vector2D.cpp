#include "Vector2D.h"
#include <math.h>

Vector2D Vector2D::normalizar(double x, double y)
{
	return { x / sqrt(x * x + y * y), y / sqrt(x * x + y * y) };
}

inline double Vector2D::modulo() const
{
	return sqrt(x * x + y * y);
}

inline double Vector2D::argumento() const
{
	return atan2(y, x);
}

inline Vector2D Vector2D::unitario() const
{
	auto mod = modulo();
	if (mod > 0.00001)
		return { x / mod, y / mod };
	return { x,y };
}

inline Vector2D operator*(double e, const Vector2D& v)
{
	return v * e;
}

inline Vector2D Vector2D::operator - (const Vector2D& v) const //resta de vectores
{
	return { x - v.x,y - v.y };
}

inline Vector2D Vector2D::operator + (const Vector2D& v) const //suma de vectores
{
	return { x + v.x,y + v.y };
}

inline double Vector2D::operator *(const Vector2D& v) const // producto escalar
{
	return { x * v.x + y * v.y };
}


inline Vector2D Vector2D::operator *(double e) const // producto por un escalar
{
	return{ x * e , y + e };
}