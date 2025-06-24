// TEST UNITARIO DE LA CLASE TABLERO
#include <iostream>
#include "tablero.h"
#include <iostream>
#include <string>
#include "Menu.h"
#include "Partida.h"
#include "DATOS_DIBUJO.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "mundo.h"

enum EstadoApp { MENU, SEL_JUG, JUEGO};
EstadoApp estadoActual = MENU;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);


Partida partida;
Mundo mundo;
Menu menu;
Menu seleccion_jug;

unsigned char tecla_;
bool nombre_Player1ok = false;
string nomb1;
string nomb2;
int main(int argc, char* argv[])
{


	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA | GLUT_MULTISAMPLE);
	glutCreateWindow("Gravitacional Chess");

	glEnable(0x809D);

	// Habilitar luces y perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	// Configurar perspectiva
	glMatrixMode(GL_PROJECTION);
	//gluPerspective(40.0, 800 / 600.0f, 0.1, 2000);

	mundo.inicializa();
	// Callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	//Menu m;
	//m.Menu_Progress();
	glutMainLoop();



	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Configura la matriz de proyección según el estado
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (estadoActual)
	{
	case EstadoApp::MENU:
	{
		// Proyección 2D ortogonal para el menú
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_JUG:
	{
		// Proyección 2D ortogonal para el menú
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	
	case EstadoApp::JUEGO:
	{
		// Proyección 3D perspectiva para el juego
		gluPerspective(40.0, 800.0 / 600.0, 0.1, 2000);
		break;
	}
	}
	

	// Cambia a matriz de modelo y la resetea
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (estadoActual)
	{
	case EstadoApp::MENU:
	{
		menu.dibujarMenu();
		break;
	}
	case EstadoApp::SEL_JUG:
	{
		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = mundo.partida.getTablero().getPlayer2().get_Name();
		seleccion_jug.dibujarTexto(-0.6f, 0.2f, "Nombre player1 - Piezas BLANCAS: ");
		seleccion_jug.dibujarCadena_Caract(0.2f, 0.2f, nomb1);
		seleccion_jug.dibujarTexto(-0.6f, -0.2f, "Nombre player2 - Piezas NEGRAS");
		seleccion_jug.dibujarCadena_Caract(0.2f, -0.2f, nomb2);
		break;
	}
	case EstadoApp::JUEGO:
	{
		mundo.dibuja();
		break;
	}
	}

	glutSwapBuffers();
}


void OnKeyboardDown(unsigned char key, int x, int y) {

	mundo.tecla(key); //Pasamos la tecla seleccionado a mundo.cpp
	switch(estadoActual)
	{
		case EstadoApp::MENU: 
		{
			switch (key)
			{
				case '1':
				{
					estadoActual = SEL_JUG;
					break;
				}
				case '3':
				{
					exit(0);
					break;
				}
			}
				break;
		}
		case EstadoApp::SEL_JUG:
		{
			if (!nombre_Player1ok)
			{
				if (mundo.partida.escoger_player(key, mundo.partida.getTablero().getPlayer1()))
				{
					nombre_Player1ok = true;
				}
			}
			else
				if (mundo.partida.escoger_player(key, mundo.partida.getTablero().getPlayer2()))
				{
					mundo.partida.inicializar();
					estadoActual = JUEGO;
				}
			break;
		}
		case EstadoApp::JUEGO:
		{
			if (key == 27) exit(0); // ESC
			mundo.tecla(key); //Pasamos la tecla seleccionada a mundo.cpp
			mundo.key_tecla = key;
			break;
		}
	}
	

}

void OnTimer(int value)
{
	if (!mundo.update(estadoActual))
		estadoActual = MENU;
	glutPostRedisplay(); // Redibujar la pantalla
	glutTimerFunc(25, OnTimer, 0);
}