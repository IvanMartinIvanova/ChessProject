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

enum EstadoApp{MENU,JUEGO};
EstadoApp estadoActual = MENU;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

Tablero tablero;
Mundo mundo;
Menu menu;


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

	if (estadoActual == MENU) {
		// Proyección 2D ortogonal para el menú
		gluOrtho2D(-1, 1, -1, 1);
	}
	else if (estadoActual == JUEGO) {
		// Proyección 3D perspectiva para el juego
		gluPerspective(40.0, 800.0 / 600.0, 0.1, 2000);
	}

	// Cambia a matriz de modelo y la resetea
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (estadoActual == MENU) {
		menu.dibujarMenu();
	}
	else if (estadoActual == JUEGO) {
		mundo.dibuja();
	}

	glutSwapBuffers();
}


void OnKeyboardDown(unsigned char key, int x, int y) {
	if (estadoActual == MENU) {
		if (key == '1') {
			estadoActual = JUEGO;
		}
		else if (key == '3') {
			exit(0);
		}
	}
	else if (estadoActual == JUEGO) {
		if (key == 27) exit(0); // ESC
		mundo.tecla(key);
		mundo.key_tecla = key;
	}
}

void OnTimer(int value)
{
	mundo.update();
	glutPostRedisplay(); // Redibujar la pantalla
	glutTimerFunc(25, OnTimer, 0);
}