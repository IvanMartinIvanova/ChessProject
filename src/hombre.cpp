#include "freeglut.h"
#include "hombre.h"

Hombre::Hombre()
{
	posicion = { 0,0 };
}

void Hombre::accion(char key)
{
	if (key == 'w')
	{
		velocidad = { 0,1 };
	}
	if (key == 'a')
	{
		velocidad = { -1,0 };
	}
	if (key == 's')
	{
		velocidad = { 0,-1 };
	}
	if (key == 'd')
	{
		velocidad = { 0,1 };
	}
	if (key == 'g')
	{
		//estela(posicion);
	}
}

void Hombre::estela(Vector2D pos)
{

}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslated(posicion.x, posicion.y, 0);
	glColor3d(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void Hombre::set_vel(const Vector2D& vel)
{
	velocidad = vel;
}

void Hombre::mueve(double t)
{
	posicion = posicion + velocidad * t + aceleracion * t * t;
	velocidad = velocidad + aceleracion * t;
}