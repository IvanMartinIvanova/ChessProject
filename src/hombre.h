#pragma once
#include "Vector2D.h"
#include "Color.h"
#include "disparo.h"

using uchar = unsigned char;
class Hombre
{

	friend class Interaccion; //da permiso a todos los metodos de la clase interaccion para acceder a la parte privada de hombre

	char tecla;
	double altura;
	Vector2D posicion{};
	Vector2D velocidad{};
	Vector2D aceleracion{};
	Disparo disparo;
	Color color;


public:
	Hombre();
	void dibuja();
	void set_vel(const Vector2D& vel);
	void mueve(double t);
	void accion(char key);
	void estela(Vector2D pos);
};

