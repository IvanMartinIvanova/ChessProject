
#include "ETSIDI.h"
#include "freeglut.h"

// Prototipos
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Esfera 3D");

	// Habilitar luces y perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	// Configurar perspectiva
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	// Callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	glutMainLoop();
	return 0;
}

void OnDraw(void)
{
	// Borrar buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Matriz de modelo y vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Cámara
	gluLookAt(10, 10, 10,  // posición del ojo
		0, 0, 0,     // punto al que mira
		0, 1, 0);    // up vector

	// Dibujar esfera
	glColor3f(0.2f, 0.5f, 1.0f); // azul claro
	glutSolidSphere(2.0, 30, 30); // radio = 2.0, resolución

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

