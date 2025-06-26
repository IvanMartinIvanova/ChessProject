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
	flag = 0;
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
	tablerogr.dibuja(partida.getTablero().getVectorCasillas());
	
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
	partida.inicializar();
}

bool Mundo::update(int estado) {
	cout << key_tecla << endl;
	int opcion = opcion_modo;
	Tablero tab;
	tab = partida.getTablero();
	switch (estado)
	{
	case 0:
	{
		//opcion_modo = opcion;
		//partida.inicializar();       //Solo nueva partida lo usa
		//key_tecla = 0;

		break;
	}
	
	case 2:
	{
		tablerogr.mueve(key_tecla);

		if (flag == 1 || flag == -1)
		{
			if (datos.pieza_fin_conGrav != nullptr)
			{
				TipoPieza tipo = datos.pieza_fin_conGrav->getTipo();
				Colorpieza color = datos.pieza_fin_conGrav->getColor();

				if (tipo == TipoPieza::PEON)
				{
					Casilla pos = partida.getTablero().buscar_pieza(datos.pieza_fin_conGrav);
					if ((color == Colorpieza::BLANCO && pos.getfile() == 7) || (color == Colorpieza::NEGRO && pos.getfile() == 0))
					{

						if (partida.getTablero().comp_coronacion(datos.pieza_fin_conGrav, key_tecla)) //True si puede continuar porque se ha elegido pieza o porque no había coronación
						{
							flag = 1;

						}
						else //False si hay coronación pero no se ha elegido pieza, por tanto, no puede continuar hasta que se elija pieza
						{

							flag = -1;
							return true;

						}

					}
				}
				
			}

		}
		
		if (flag == 0 || flag == 1)
		{
			if (partida.Progress_Partida(datos, key_tecla))
			{
				/*TipoPieza p = datos.pieza_fin_conGrav->getTipo();
				switch (p)
				{
				case TipoPieza::PEON:
					cout << "Peon"
				}*/
				key_tecla = 0;
				flag = 1;
				return true;
			}
			else
			{
				key_tecla = 0;
				datos.pieza_fin_conGrav = nullptr;
				return false; //Fin partida

			}
		}
		
		
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
	
}

TableroGr& Mundo::getTablerogr()
{
	return this->tablerogr;
}

int Mundo::getFlag()
{
	return this->flag;
}



