#include "Mundo.h"
#include "freeglut.h"
#include <iostream>
#include <cmath>

#define xorg 0
#define yorg 7.5
#define zorg 30
#define t0 40

Mundo::Mundo()
{
	x_ojo = 0;

	y_ojo = 0;
	z_ojo = 40;

	//y_ojo = 20;
	//z_ojo = 40;

	xmira = 0.0;
	ymira = 0;
	zmira = 0.0;

	/*sprite = new Sprite("imagenes/Bubble_Big.png", 0.05, 0.05, 10, 10);
	Sprite(const char *texturePath, float x=0, float y=0, float width = ‐1, float height = ‐1);*/
}

void Mundo::rotarOjo()
{
	double dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	double ang = atan2(z_ojo, x_ojo);
	ang += 0.05;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		xmira, ymira, zmira,				 // 0.0, y_ojo, 0.0, 
		0.0, 1.0, 0.0);
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	//glDisable(GL_LIGHTING);


	tablero.dibuja();
	piezas1.dibuja();
	piezas2.dibuja();
	//fondo->dibuja(0);
	tablerogr.dibuja(); 

	//glTranslated(0, 0, 0);
	//glutSolidSphere(1, 10, 10);
	//fondo.dibuja();
	tablero.counter += 0.05;

	//fondo.dibujaxy();
	glEnd();
//	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{
}

void Mundo::inicializa()
{
	/*fondo->setCenter()*/
}

void Mundo::tecla(char key)
{
	if (key == GLUT_KEY_LEFT)
	if (key == 'c')
	{
	}
	tablerogr.mueve(key);
}

