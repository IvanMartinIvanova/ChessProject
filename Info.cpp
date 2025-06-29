// TEST UNITARIO DE LA CLASE TABLERO
#include <iostream>
#include "tablero.h"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Pantalla.h"
#include "Partida.h"
#include "DATOS_DIBUJO.h"
#include "ETSIDI.h"
#include "freeglut.h"
#include "mundo.h"

enum EstadoApp { MENU, SEL_JUG, SEL_JUG_IA, JUEGO, JUEGO_VS_IA, FIN_JUG, SEL_SAVE };
EstadoApp estadoActual = MENU;
bool partida_activa = false;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);


Partida partida;
Mundo mundo;
Menu menu;
Pantalla seleccion_jug{"rc/banner.png"};
Pantalla pantalla_juego{ "rc/fondo1.png" };
Pantalla pantalla_fin_partida{ "rc/banner.png" };
unsigned char tecla_;
bool nombre_Player1ok = false;
string nomb1;
string nomb2;
vector<Pieza*> piezas_jaque_p1{};
vector<Pieza*> piezas_jaque_p2{};

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
	case EstadoApp::SEL_SAVE:
	{
		// Proyección 2D ortogonal para el menú de guardado/carga
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_JUG:
	{
		// Proyección 2D ortogonal para el menú
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_JUG_IA:
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

	case EstadoApp::JUEGO_VS_IA:
	{
		// Proyección 3D perspectiva para el juego
		gluPerspective(40.0, 800.0 / 600.0, 0.1, 2000);
		break;
	}
	case EstadoApp::FIN_JUG:
	{
		// Proyección 2D ortogonal para el menú
		gluOrtho2D(-1, 1, -1, 1);
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
		menu.dibujarPantalla();
		break;
	}
	case EstadoApp::SEL_JUG:
	{
		seleccion_jug.dibujarPantalla();
		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = mundo.partida.getTablero().getPlayer2().get_Name();
		seleccion_jug.dibujarTexto(-0.6f, 0.2f, "Nombre player1 - Piezas BLANCAS: ");
		seleccion_jug.dibujarCadena_Caract(0.2f, 0.2f, nomb1);
		seleccion_jug.dibujarTexto(-0.6f, -0.2f, "Nombre player2 - Piezas NEGRAS");
		seleccion_jug.dibujarCadena_Caract(0.2f, -0.2f, nomb2);
		break;
	}
	case EstadoApp::SEL_JUG_IA:
	{
		seleccion_jug.dibujarPantalla();
		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = "IA";
		seleccion_jug.dibujarTexto(-0.6f, 0.2f, "Nombre player1 - Piezas BLANCAS: ");
		seleccion_jug.dibujarCadena_Caract(0.2f, 0.2f, nomb1);
		seleccion_jug.dibujarTexto(-0.6f, -0.2f, "Nombre player2 - Piezas NEGRAS");
		seleccion_jug.dibujarCadena_Caract(0.2f, -0.2f, nomb2);
		break;
	}
	case EstadoApp::SEL_SAVE:
	{
		seleccion_jug.dibujarPantalla();
		seleccion_jug.dibujarTexto(-0.4f, 0.4f, "MENU DE GUARDADO / CARGA");

		if (partida_activa)
			seleccion_jug.dibujarTexto(-0.4f, 0.2f, "1. Guardar partida");

		seleccion_jug.dibujarTexto(-0.4f, 0.0f, "2. Cargar partida");
		seleccion_jug.dibujarTexto(-0.4f, -0.2f, "M. Volver al menu principal");
		break;
	}

	case EstadoApp::JUEGO:
	{
		//Dibujamos el tablero y las piezas
		pantalla_juego.dibujarPantalla();
		mundo.dibuja();
		// Cambiar temporalmente a proyección 2D para dibujar el texto informativo
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		seleccion_jug.dibujarTexto(-0.95f, -0.95f, "Pulsa M para abrir el menu de guardado/carga");

		// Restaurar proyección 3D
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		//Dibujamos los mensajes que hay durantes la partida (Turnos, Jaques, etc.)
		if (mundo.partida.getTablero().getPlayer1().get_Turno())
		{
			seleccion_jug.dibujarTexto(-18.0f, 12.0f, "Turno de ");
			seleccion_jug.dibujarCadena_Caract(-13.0f, 12.0f, nomb1);
			
		}
		if (mundo.partida.getTablero().getPlayer2().get_Turno())
		{
			seleccion_jug.dibujarTexto(-18.0f, 12.0f, "Turno de ");
			seleccion_jug.dibujarCadena_Caract(-13.0f, 12.0f, nomb2);
		}

		//Mensajes evento de jaque
		if (mundo.partida.get_estado_Jaque())
		{
			seleccion_jug.dibujarTexto(12.0f, 12.0f, "JAQUE AL REY");
			piezas_jaque_p1 = mundo.partida.getTablero().get_Piezas_Jaque(mundo.partida.getTablero().getPlayer1(), mundo.partida.getTablero().getPlayer2()); //Piezas de player1 que hacen jaque al player2
			piezas_jaque_p2 = mundo.partida.getTablero().get_Piezas_Jaque(mundo.partida.getTablero().getPlayer2(), mundo.partida.getTablero().getPlayer1()); //Piezas de player2 que hacen jaque al player1
			if (piezas_jaque_p1.size() > 0)
			{
				mundo.partida.getTablero().buscar_posRey(Colorpieza::NEGRO).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,0,0 });
				for (auto p1 : piezas_jaque_p1)
				{
					mundo.partida.getTablero().buscar_pieza(p1).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,255,0 });
				}
			}
			if (piezas_jaque_p2.size() > 0)
			{
				mundo.partida.getTablero().buscar_posRey(Colorpieza::BLANCO).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,0,0 });
				for (auto p2 : piezas_jaque_p2)
				{
					mundo.partida.getTablero().buscar_pieza(p2).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,255,0 });
				}
			}

		}
		
		if (mundo.getFlag() == -1)
		{
			pantalla_juego.dibujarTexto(-20.0, -15.0, "Un peon ha coronado. Escoge la pieza que quieres obtener:");
			pantalla_juego.dibujarTexto(-20.0, -17.0, "TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ");
		}
		break;
	}

	case EstadoApp::JUEGO_VS_IA:
	{
		//Dibujamos el tablero y las piezas
		pantalla_juego.dibujarPantalla();
		mundo.dibuja();
		// Mostrar mensaje de guardado (igual que en modo normal)
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		seleccion_jug.dibujarTexto(-0.95f, -0.95f, "Pulsa M para abrir el menu de guardado/carga");

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		//Dibujamos los mensajes que hay durantes la partida (Turnos, Jaques, etc.)
		if (mundo.partida.getTablero().getPlayer1().get_Turno())
		{
			seleccion_jug.dibujarTexto(-18.0f, 12.0f, "Turno de ");
			seleccion_jug.dibujarCadena_Caract(-13.0f, 12.0f, nomb1);

		}
		if (mundo.partida.getTablero().getPlayer2().get_Turno())
		{
			seleccion_jug.dibujarTexto(-18.0f, 12.0f, "Turno de ");
			seleccion_jug.dibujarCadena_Caract(-13.0f, 12.0f, nomb2);
		}

		//Mensajes evento de jaque
		if (mundo.partida.get_estado_Jaque())
		{
			seleccion_jug.dibujarTexto(12.0f, 12.0f, "JAQUE AL REY");
			piezas_jaque_p1 = mundo.partida.getTablero().get_Piezas_Jaque(mundo.partida.getTablero().getPlayer1(), mundo.partida.getTablero().getPlayer2()); //Piezas de player1 que hacen jaque al player2
			piezas_jaque_p2 = mundo.partida.getTablero().get_Piezas_Jaque(mundo.partida.getTablero().getPlayer2(), mundo.partida.getTablero().getPlayer1()); //Piezas de player2 que hacen jaque al player1
			if (piezas_jaque_p1.size() > 0)
			{
				mundo.partida.getTablero().buscar_posRey(Colorpieza::NEGRO).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,0,0 });
				for (auto p1 : piezas_jaque_p1)
				{
					mundo.partida.getTablero().buscar_pieza(p1).dibuja_Jaque(20, mundo.getTablerogr().idle(),{255,255,0});
				}
			}
			if (piezas_jaque_p2.size() > 0)
			{
				mundo.partida.getTablero().buscar_posRey(Colorpieza::BLANCO).dibuja_Jaque(20, mundo.getTablerogr().idle(), { 255,0,0 });
				for (auto p2 : piezas_jaque_p2)
				{
					mundo.partida.getTablero().buscar_pieza(p2).dibuja_Jaque(20, mundo.getTablerogr().idle(),{255,255,0});
				}
			}

		}

		if (mundo.getFlag() == -1)
		{
			pantalla_juego.dibujarTexto(-20.0, -16.0, "Un peon ha coronado. Escoge la pieza que quieres obtener:");
			pantalla_juego.dibujarTexto(-20.0, -18.0, "TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ");
		}
		break;
	}

	case EstadoApp::FIN_JUG:
	{
		pantalla_fin_partida.dibujarPantalla();
		if (mundo.partida.get_estado_Jaque())
		{
			if (!mundo.partida.getTablero().getPlayer1().get_Turno())
			{
				pantalla_fin_partida.dibujarCadena_Caract(0.4f, 0.2f, nomb1);
			}
			else
			{
				pantalla_fin_partida.dibujarCadena_Caract(0.4f, 0.2f, nomb2);
			}
			pantalla_fin_partida.dibujarTexto(-0.6f, 0.2f, "JAQUE MATE FIN DE PARTIDA - HA GANADO ");
		}
		else
			pantalla_fin_partida.dibujarTexto(-0.6f, 0.2f, "TABLAS - PARTIDA FINALIZADA EN EMPATE");

		pantalla_fin_partida.dibujarCadena_Caract(-0.8f, 0.0f, nomb1);
		pantalla_fin_partida.dibujarCadena_Caract(0.0f, 0.0f, nomb2);
		pantalla_fin_partida.dibujarTexto(-0.8f, -0.2f, "Puntos: ");
		pantalla_fin_partida.dibujarTexto(0.0f, -0.2f, "Puntos: ");
		pantalla_fin_partida.dibujarNumero(-0.4f, -0.2f, mundo.partida.getTablero().getPlayer1().get_Punt());
		pantalla_fin_partida.dibujarNumero(0.6f, -0.2f, mundo.partida.getTablero().getPlayer2().get_Punt());
		pantalla_fin_partida.dibujarTexto(-0.8f, -0.4f, "Movimientos: ");
		pantalla_fin_partida.dibujarTexto(0.0f, -0.4f, "Movimientos: ");
		pantalla_fin_partida.dibujarNumero(-0.4f, -0.4f, mundo.partida.getTablero().getPlayer1().get_nMov());
		pantalla_fin_partida.dibujarNumero(0.6f, -0.4f, mundo.partida.getTablero().getPlayer2().get_nMov());
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
				case '2':
				{
					estadoActual = SEL_SAVE;
					break;
				}
				case '3':
				{
					estadoActual = SEL_JUG_IA;
					break;
				}
				case '4':
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
					mundo.inicializa();
					partida_activa = true;
					estadoActual = JUEGO;
				}
			break;
		}
		case EstadoApp::SEL_SAVE:
		{
			if (key == 'm') {
				partida_activa = false;   // Al volver al menú, desactivamos la flag
				estadoActual = MENU;
			}
			else if (key == '1') {
				if (partida_activa) {
					mundo.partida.guardar_partida();
					std::cout << "Partida guardada correctamente." << std::endl;
				}
				else {
					std::cout << "No se puede guardar sin partida activa." << std::endl;
				}
			}
			else if (key == '2') {
				mundo.partida.cargar_partida();
				std::cout << "Partida cargada correctamente." << std::endl;
				partida_activa = true;  // Activamos la flag tras cargar
				estadoActual = JUEGO;
			}
			break;
		}
		case EstadoApp::SEL_JUG_IA:
		{
			if (mundo.partida.escoger_player(key, mundo.partida.getTablero().getPlayer1()))
			{
				mundo.inicializa();
				partida_activa = true;
				estadoActual = JUEGO_VS_IA;
			
			}
			break;
		}
		case EstadoApp::JUEGO:
		{
			if (key == 27) exit(0); // ESC
			mundo.tecla(key); //Pasamos la tecla seleccionada a mundo.cpp
			mundo.key_tecla = key;
			if (key == 'm') {
				estadoActual = SEL_SAVE;
				break;
			}
			break;
		}
		case EstadoApp::JUEGO_VS_IA:
		{
			if (key == 27) exit(0); // ESC
			mundo.tecla(key); //Pasamos la tecla seleccionada a mundo.cpp
			mundo.key_tecla = key;
			break;
		}
		case EstadoApp::FIN_JUG:
		{
			if (key == 27)
			{
				estadoActual = MENU;
			}
		}
	}
	

}

void OnTimer(int value)
{
	if (!mundo.update(estadoActual))
		estadoActual = FIN_JUG;
	
	glutPostRedisplay(); // Redibujar la pantalla
	glutTimerFunc(25, OnTimer, 0);
}