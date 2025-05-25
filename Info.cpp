// TEST UNITARIO DE LA CLASE TABLERO
#include <iostream>
#include "tablero.h"

//int main() {
//	Tablero t;
//	t.inicializar();  // Coloca las piezas iniciales
//	std::cout << "=== Ajedrez Gravitacional ===\n";
//	t.mostrar();  // Dibuja el tablero
//
//	int x1, y1, x2, y2;
//
//	while (true) {
//		std::cout << "\nIntroduce movimiento (x1 y1 x2 y2) o -1 para salir: ";
//		std::cin >> x1;
//
//		if (x1 == -1) break;
//
//		std::cin >> y1 >> x2 >> y2;
//
//		if (!t.mover(x1, y1, x2, y2)) {
//			std::cout << "Movimiento inválido. Intenta de nuevo.\n";
//		}
//
//		t.mostrar();
//	}
//
//	std::cout << "Juego terminado.\n";
//	return 0;
//}

//Cambio zsxdcfgvbhjnkm




#include "ETSIDI.h"
#include "freeglut.h"
#include "mundo.h"
#include "tablero.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

Tablero tablero;
Mundo mundo;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA | GLUT_MULTISAMPLE);
	glutCreateWindow("Esfera 3D");

	// Habilitar luces y perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	// Configurar perspectiva
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	mundo.inicializa();
	// Callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glEnable(GLUT_MULTISAMPLE);
	glLoadIdentity();

	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
	if (key == 27) // ESC para salir
		exit(0);
}

void OnTimer(int value)
{
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay(); // Redibujar la pantalla
}