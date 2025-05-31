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
	z_ojo = 50;

	//y_ojo = 20;
	//z_ojo = 40;

	xmira = 0.0;
	ymira = 0;
	zmira = 0;

	opcion_modo = 0;
	estado = EstadoJuego::MENU;
	key_tecla = NULL;


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

	//dibuja el tablero hay q pasarle el *Pieza[8][8] contenido en tablero para que se dibuje EN CADA ITERACION IMPORTANTE
	tablerogr.dibuja(nullptr);

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
	
}

void Mundo::update() {
	cout << key_tecla << endl;
	int opcion = opcion_modo;
	switch (estado)
	{
	case EstadoJuego::MENU:
	{
		menu_juego.dibujarMenu();
		if (key_tecla >= '1' && key_tecla <= '9')
		{
			opcion = key_tecla - '0';
			if (opcion == 1)
			{
				opcion_modo = opcion;
				partida.inicializar();       //Solo nueva partida lo usa
				//partida.escoger_player();
				estado = EstadoJuego::JUGANDO;
				key_tecla = 0;
			}
		}
		break;
	}
	case EstadoJuego::ESPERANDO_INPUT:
	{
		if (opcion == 1)
		{
			partida.inicializar();       //Solo nueva partida lo usa
			//partida.escoger_player();
			estado = EstadoJuego::JUGANDO;
		}
		break;
	}
	case EstadoJuego::JUGANDO:
	{
		if (partida.Progress_Partida(datos, key_tecla))
		{
			key_tecla = 0;
		}
		else
		{
			opcion_modo = -1;
			estado = EstadoJuego::FIN_PARTIDA;
			break;
		}
	}
	case EstadoJuego::FIN_PARTIDA:
	{
		cout << "Partida Finalizada" << endl;
		break;
	}
	}
}

void Mundo::tecla(char key)
{
	key_tecla = key;

	if (key == GLUT_KEY_LEFT)
		if (key == 'c')
		{
		}
	tablerogr.mueve(key);
}

