#include "lib/freeglut.h"
#include "lib/ETSIDI.h"

#include "math.h"

struct Esfera
{
	float radio;
	float x_traslado;
	float y_traslado;
	float z_traslado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};

struct Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
	float x_p;
	float y_p;
	float z_p;
	float eje_y_1;
	float eje_y_2;
	float eje_y_3;
};

Esfera esfera_cian = { 3,3,0,0,0,255,255 };
Esfera esfera2 = { 2,0,2,0,255,0,0 };

Mundo val_mund = { 7.0, 10, -20, 0.0, 0, 0.0, 0.0, 1.0, 0.0 };

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla

void dibuja_esfera_cian(Esfera esfera_cian)
{
	glTranslatef(esfera_cian.x_traslado, esfera_cian.y_traslado, esfera_cian.z_traslado);
	glColor3ub(esfera_cian.rojo, esfera_cian.azul, esfera_cian.verde);
	glutSolidSphere(esfera_cian.radio, 20, 20);
	glTranslatef(-3, 0, 0);
}

void dibuja_esfera_2(Esfera esfera2)
{
	glTranslatef(esfera2.x_traslado, esfera2.y_traslado, esfera2.z_traslado);
	glColor3ub(esfera2.rojo, esfera2.verde, esfera2.azul);
	glutSolidSphere(esfera2.radio, 20, 20);
	glTranslatef(esfera2.x_traslado, -esfera2.y_traslado, esfera2.z_traslado);
}

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(val_mund.x_ojo, val_mund.y_ojo, val_mund.z_ojo,  // posicion del ojo
		val_mund.x_p, val_mund.y_p, val_mund.z_p,      // hacia que punto mira  (0,0,0) 
		val_mund.eje_y_1, val_mund.eje_y_2, val_mund.eje_y_3);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo

	//Plano
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glEnd();

	//Toro
	glColor3ub(0, 255, 0);
	glutSolidTorus(1, 5.09, 20, 20);

	//Esfera1
	dibuja_esfera_cian(esfera_cian);

	//Esfera2
	dibuja_esfera_2(esfera2);


	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Control esfera cian
	if (key == '+' && esfera_cian.radio < 3)
		esfera_cian.radio += 0.5f;
	if (key == '-' && esfera_cian.radio > 1)
		esfera_cian.radio -= 0.5f;

	//Control esfera2
	if (key == 'e' && esfera2.radio < 2.5)
		esfera2.radio += 0.5f;
	if (key == 'r' && esfera2.radio > 1)
		esfera2.radio -= 0.5f;

	if (key == 'd')
		esfera2.x_traslado -= 0.1f;
	if (key == 'a')
		esfera2.x_traslado += 0.1f;
	if (key == 's')
		esfera2.y_traslado -= 0.1f;
	if (key == 'w')
		esfera2.y_traslado += 0.1f;

	if (key == '1')
	{
		esfera2.rojo = 0;
	}
	if (key == '2')
	{
		esfera2.rojo = 255;
	}
	if (key == '3')
	{
		esfera2.verde = 0;
	}
	if (key == '4')
	{
		esfera2.verde = 255;
	}
	if (key == '5')
	{
		esfera2.azul = 0;
	}
	if (key == '6')
	{
		esfera2.azul = 255;
	}

	glutPostRedisplay();
}

void OnTimer(int value)
{
	float dist_eje_y, angulo_plano;

	dist_eje_y = sqrt((val_mund.x_ojo) * (val_mund.x_ojo) + (val_mund.z_ojo) * (val_mund.z_ojo));

	angulo_plano = atan2(val_mund.z_ojo, val_mund.x_ojo);

	angulo_plano = angulo_plano + 0.1;

	val_mund.x_ojo = dist_eje_y * cos(angulo_plano);
	val_mund.z_ojo = dist_eje_y * sin(angulo_plano);

	glutTimerFunc(50, OnTimer, 0);
	glutPostRedisplay();
}



