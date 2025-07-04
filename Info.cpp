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
#include "Registros.h"

enum EstadoApp { MENU, SEL_JUG, SEL_JUG_IA, JUEGO, JUEGO_VS_IA, FIN_JUG, SEL_SAVE, REGISTROS };
EstadoApp estadoActual = MENU;
bool partida_activa = false;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);


Partida partida;
Mundo mundo;
Menu menu;
Pantalla seleccion_jug{"rc/Seleccion_Jugador.png"};
Pantalla pantalla_juego{"rc/space.png"};
Pantalla pantalla_fin_partida{ "rc/banner.png" };
Pantalla pantalla_regis{ "rc/fondo.png" };
Pantalla seleccion_op{ "rc/banner.png" };
unsigned char tecla_;
bool nombre_Player1ok = false;
bool nombre_Player2ok = false;
bool num_skin_player1ok = false;
bool flag_regis = false;
string nomb1;
string nomb2;
vector<Pieza*> piezas_jaque_p1{};
vector<Pieza*> piezas_jaque_p2{};
Registro reg;
Registro* reg2 = nullptr;
int skin_player1 = 1;
int skin_player2 = 1;

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

	glutMainLoop();



	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Configura la matriz de proyecci�n seg�n el estado
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (estadoActual)
	{
	case EstadoApp::MENU:
	{
		// Proyecci�n 2D ortogonal para el men�
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_SAVE:
	{
		// Proyecci�n 2D ortogonal para el men� de guardado/carga
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_JUG:
	{
		// Proyecci�n 2D ortogonal para pantalla de selecci�n de jugador
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::SEL_JUG_IA:
	{
		// Proyecci�n 2D ortogonal para pantalla de selecci�n de jugador
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::JUEGO:
	{
		// Proyecci�n 3D perspectiva para el juego
		gluPerspective(40.0, 800.0 / 600.0, 0.1, 2000);
		break;
	}
	case EstadoApp::JUEGO_VS_IA:
	{
		// Proyecci�n 3D perspectiva para el juego
		gluPerspective(40.0, 800.0 / 600.0, 0.1, 2000);
		break;
	}
	case EstadoApp::REGISTROS:
	{
		// Proyecci�n 2D ortogonal para pantalla de registros de partidas
		gluOrtho2D(-1, 1, -1, 1);
		break;
	}
	case EstadoApp::FIN_JUG:
	{
		// Proyecci�n 2D ortogonal para pantalla de fin de partida
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
		seleccion_jug.dibujarTexto(-0.4f, 0.2f, "Nombre player1 - Piezas BLANCAS: ");
		seleccion_jug.dibujarCadena_Caract(0.4f, 0.2f, nomb1);
		seleccion_jug.dibujarTexto(-0.4f, 0.0f, "Elija la skin para las piezas (1, 2 o 3): ");
		seleccion_jug.dibujarNumero(0.4f, 0.0f, skin_player1);
		seleccion_jug.dibujarTexto(-0.4f, -0.2f, "Nombre player2 - Piezas NEGRAS");
		seleccion_jug.dibujarCadena_Caract(0.4f, -0.2f, nomb2);
		seleccion_jug.dibujarTexto(-0.4f, -0.4f, "Elija la skin para las piezas (1, 2 o 3): ");
		seleccion_jug.dibujarNumero(0.4f, -0.4f, skin_player2);
		break;
	}
	case EstadoApp::SEL_JUG_IA:
	{
		seleccion_jug.dibujarPantalla();
		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = "IA";
		skin_player2 = 1;
		seleccion_jug.dibujarTexto(-0.4f, 0.2f, "Nombre player1 - Piezas BLANCAS: ");
		seleccion_jug.dibujarCadena_Caract(0.6f, 0.2f, nomb1);
		seleccion_jug.dibujarTexto(-0.4f, 0.0f, "Elija la skin para las piezas (1, 2 o 3): ");
		seleccion_jug.dibujarNumero(0.6f, 0.0f, skin_player1);
		seleccion_jug.dibujarTexto(-0.4f, -0.2f, "Nombre player2 - Piezas NEGRAS");
		seleccion_jug.dibujarCadena_Caract(0.6f, -0.2f, nomb2);
		seleccion_jug.dibujarTexto(-0.4f, -0.4f, "Elija la skin para las piezas (1, 2 o 3): ");
		seleccion_jug.dibujarNumero(0.6f, -0.4f, skin_player2);
		break;
	}
	case EstadoApp::SEL_SAVE:
	{
		seleccion_op.dibujarPantalla();
		seleccion_op.dibujarTexto(-0.4f, 0.4f, "MENU DE GUARDADO / CARGA");

		if (partida_activa)
			seleccion_op.dibujarTexto(-0.4f, 0.2f, "1. Guardar partida actual");

		seleccion_op.dibujarTexto(-0.4f, 0.0f, "2. Cargar partida 1 vs 1");
		seleccion_op.dibujarTexto(-0.4f, -0.2f, "3. Cargar partida vs IA");
		seleccion_op.dibujarTexto(-0.4f, -0.4f, "M. Volver al menu principal");
		seleccion_op.dibujarTexto(-0.95f, -0.8f, "Nota: Solo se guarda la partida que estas jugando actualmente");

		break;
	}


	case EstadoApp::JUEGO:
	{
		//Dibujamos el tablero y las piezas
		mundo.dibuja();
		// Cambiar temporalmente a proyecci�n 2D para dibujar el texto informativo
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		pantalla_juego.dibujarTexto(-0.95f, -0.95f, "Pulsa M para abrir el menu de guardado/carga");

		// Restaurar proyecci�n 3D
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = mundo.partida.getTablero().getPlayer2().get_Name();

		//Dibujamos los mensajes que hay durantes la partida (Turnos, Jaques, etc.)
		if (mundo.partida.get_gana_p1() == false && mundo.partida.get_gana_p2() == false)
		{
			if (mundo.partida.getTablero().getPlayer1().get_Turno())
			{
				pantalla_juego.dibujarTexto(-18.0f, 12.0f, "Turno de ");
				pantalla_juego.dibujarCadena_Caract(-13.0f, 12.0f, nomb1);

			}
			if (mundo.partida.getTablero().getPlayer2().get_Turno())
			{
				pantalla_juego.dibujarTexto(-18.0f, 12.0f, "Turno de ");
				pantalla_juego.dibujarCadena_Caract(-13.0f, 12.0f, nomb2);
			}
		}
		else
		{
			pantalla_juego.dibujarTexto(-18.0f, 12.0f, "FIN PARTIDA - PRESS ENTER ");
		}

		//Mensajes evento de jaque
		if (mundo.partida.get_estado_Jaque())
		{
			if (mundo.partida.get_gana_p1() == false && mundo.partida.get_gana_p2() == false)
			{
				pantalla_juego.dibujarTexto(12.0f, 12.0f, "JAQUE AL REY");
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
			else
			{
				pantalla_juego.dibujarTexto(8.0f, 12.0f, "JAQUE MATE");
			}

		}
		else
		{
			if (mundo.partida.get_gana_p1() == true && mundo.partida.get_gana_p2() == true)
				pantalla_juego.dibujarTexto(8.0f, 12.0f, "TABLAS");
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
		mundo.dibuja();
		// Mostrar mensaje de guardado (igual que en modo normal)
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(-1, 1, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		pantalla_juego.dibujarTexto(-0.95f, -0.95f, "Pulsa M para abrir el menu de guardado/carga");

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();

		nomb1 = mundo.partida.getTablero().getPlayer1().get_Name();
		nomb2 = mundo.partida.getTablero().getPlayer2().get_Name();

		//Dibujamos los mensajes que hay durantes la partida (Turnos, Jaques, etc.)
		if (mundo.partida.get_gana_p1() == false && mundo.partida.get_gana_p2() == false)
		{
			if (mundo.partida.getTablero().getPlayer1().get_Turno())
			{
				pantalla_juego.dibujarTexto(-18.0f, 12.0f, "Turno de ");
				pantalla_juego.dibujarCadena_Caract(-13.0f, 12.0f, nomb1);

			}
			if (mundo.partida.getTablero().getPlayer2().get_Turno())
			{
				pantalla_juego.dibujarTexto(-18.0f, 12.0f, "Turno de ");
				pantalla_juego.dibujarCadena_Caract(-13.0f, 12.0f, nomb2);
			}
		}
		else
		{
			pantalla_juego.dibujarTexto(-18.0f, 12.0f, "FIN PARTIDA - PRESS ENTER ");
		}

		//Mensajes evento de jaque
		if (mundo.partida.get_estado_Jaque())
		{
			if (mundo.partida.get_gana_p1() == false && mundo.partida.get_gana_p2() == false)
			{
				pantalla_juego.dibujarTexto(12.0f, 12.0f, "JAQUE AL REY");
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
			else
			{
				pantalla_juego.dibujarTexto(8.0f, 12.0f, "JAQUE MATE");
			}

		}
		else
		{
			if (mundo.partida.get_gana_p1() == true && mundo.partida.get_gana_p2() == true)
				pantalla_juego.dibujarTexto(8.0f, 12.0f, "TABLAS");
		}

		if (mundo.getFlag() == -1)
		{
			pantalla_juego.dibujarTexto(-20.0, -16.0, "Un peon ha coronado. Escoge la pieza que quieres obtener:");
			pantalla_juego.dibujarTexto(-20.0, -18.0, "TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ");
		}
		break;
	}
	case EstadoApp::REGISTROS:
	{
		
		
		if (!flag_regis && reg2 == nullptr)
		{
			reg2 = reg.LeeRegistros();
			flag_regis = true;
		}

		if (reg2 != nullptr)
		{
			pantalla_regis.dibujarPantalla();
			float salto_linea = 0;
			for (int i = 0; i < reg2->getNumReg(); i++)
			{
				const char* nombre1 = reg2[i].nombre1;
				const char* nombre2 = reg2[i].nombre2;
				
				pantalla_regis.dibujarNumero(-0.9f, 0.8f - salto_linea, (i + 1));
				pantalla_regis.dibujarTexto(-0.7f, 0.8f - salto_linea, nombre1);
				pantalla_regis.dibujarTexto(-0.55f, 0.8f - salto_linea, "(Puntos: ");
				pantalla_regis.dibujarNumero(-0.35f, 0.8f - salto_linea, reg2[i].p1.Puntos_totales);
				pantalla_regis.dibujarTexto(-0.2f, 0.8f - salto_linea, ")   VS");
				pantalla_regis.dibujarTexto(-0.05f, 0.8f - salto_linea, nombre2);
				pantalla_regis.dibujarTexto(0.15f, 0.8f - salto_linea, "(Puntos: ");
				pantalla_regis.dibujarNumero(0.35f, 0.8f - salto_linea, reg2[i].p2.Puntos_totales);
				pantalla_regis.dibujarTexto(0.50f, 0.8f - salto_linea, ")");

				if(salto_linea <= 1.4)
				salto_linea += 0.2;
			}

		}
		pantalla_regis.dibujarTexto(-0.9f, -0.8f, "Presione B para borrar todos los registros");
		pantalla_regis.dibujarTexto(-0.9f, -0.9f, "Presione ESC para volver al menu principal");
		break;
	}
	case EstadoApp::FIN_JUG:
	{
		pantalla_fin_partida.dibujarPantalla();
		
		if (mundo.partida.get_gana_p1() != mundo.partida.get_gana_p2())
		{
			pantalla_fin_partida.dibujarTexto(-0.6f, 0.2f, "JAQUE MATE FIN DE PARTIDA - HA GANADO ");

			if (mundo.partida.get_gana_p1() == true && mundo.partida.get_gana_p2() == false)
			{
				pantalla_fin_partida.dibujarCadena_Caract(0.4f, 0.2f, nomb1);
			}
			else
			{
				pantalla_fin_partida.dibujarCadena_Caract(0.4f, 0.2f, nomb2);
			}
			
		}
		else
			pantalla_fin_partida.dibujarTexto(-0.6f, 0.2f, "TABLAS - PARTIDA FINALIZADA EN EMPATE");

		pantalla_fin_partida.dibujarCadena_Caract(-0.8f, 0.0f, nomb1);
		pantalla_fin_partida.dibujarCadena_Caract(0.0f, 0.0f, nomb2);
		pantalla_fin_partida.dibujarTexto(-0.8f, -0.2f, "Puntos: ");
		pantalla_fin_partida.dibujarTexto(0.0f, -0.2f, "Puntos: ");
		pantalla_fin_partida.dibujarNumero(-0.4f, -0.2f, mundo.partida.getTablero().getPlayer1().get_Punt().Puntos_totales);
		pantalla_fin_partida.dibujarNumero(0.6f, -0.2f, mundo.partida.getTablero().getPlayer2().get_Punt().Puntos_totales);
		pantalla_fin_partida.dibujarTexto(-0.8f, -0.4f, "Movimientos: ");
		pantalla_fin_partida.dibujarTexto(0.0f, -0.4f, "Movimientos: ");
		pantalla_fin_partida.dibujarNumero(-0.4f, -0.4f, mundo.partida.getTablero().getPlayer1().get_nMov());
		pantalla_fin_partida.dibujarNumero(0.6f, -0.4f, mundo.partida.getTablero().getPlayer2().get_nMov());
	}
	pantalla_fin_partida.dibujarTexto(-0.9f, -0.9f, "Presione ESC para volver al menu principal");

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
					estadoActual = REGISTROS;
					break;
				}
				case '5':
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
			{
				if (!num_skin_player1ok)
				{
					if (mundo.partida.escoger_skin(key, skin_player1))
					{
						num_skin_player1ok = true;
					}
				}
				else
				{
					if (!nombre_Player2ok)
					{
						if (mundo.partida.escoger_player(key, mundo.partida.getTablero().getPlayer2()))
						{
							nombre_Player2ok = true;
						}
					}
					else
					{
						if (mundo.partida.escoger_skin(key, skin_player2))
						{
							mundo.inicializa(skin_player1, skin_player2);
							partida_activa = true;
							nombre_Player1ok = false;
							nombre_Player2ok = false;
							num_skin_player1ok = false;
							skin_player1 = 1; //Lo dejamos en 1 para la siguiente vez que entremos en seleccion de jugador (no afecta a la partida en curso porque ya hemos pasado los valores elegidos por el player antes)
							skin_player2 = 1;
							estadoActual = JUEGO;

						}
					}

				}
			}
			break;
		}
		case EstadoApp::SEL_SAVE:
		{
			if (key == 'm' || key == 'M') {
				partida_activa = false;
				estadoActual = MENU;
			}
			else if (key == '1') {
				if (partida_activa) {
					std::string archivo =
						(mundo.partida.getTablero().getPlayer2().get_Name() == "IA")
						? "partida_ia.txt" : "partida_1v1.txt";

					mundo.partida.guardar_partida(archivo);
					std::cout << "Partida guardada correctamente en: " << archivo << std::endl;
				}
				else {
					std::cout << "No se puede guardar sin partida activa." << std::endl;
				}
			}

			else if (key == '2') {  // cargar 1v1
				mundo.partida.cargar_partida("partida_1v1.txt");
				std::cout << "Partida 1 vs 1 cargada correctamente." << std::endl;
				partida_activa = true;
				estadoActual = JUEGO;
			}
			else if (key == '3') {  // cargar IA
				mundo.partida.cargar_partida("partida_ia.txt");
				std::cout << "Partida contra IA cargada correctamente." << std::endl;
				partida_activa = true;
				estadoActual = JUEGO_VS_IA;
			}
			
			break;
		}

		case EstadoApp::SEL_JUG_IA:
		{
			if (!nombre_Player1ok)
			{
				if (mundo.partida.escoger_player(key, mundo.partida.getTablero().getPlayer1()))
				{
					nombre_Player1ok = true;
				}
				
			}
			else
			{
				if (mundo.partida.escoger_skin(key, skin_player1))
				{
					mundo.inicializa(skin_player1, 1);
					partida_activa = true;
					nombre_Player1ok = false;
					skin_player1 = 1; //Lo dejamos en 1 para la siguiente vez que se entre en seleccion de juagador
					estadoActual = JUEGO_VS_IA;
				}
			}
			break;
		}
		case EstadoApp::JUEGO:
		{
			
			if (key == 27) exit(0); // ESC
			mundo.tecla(key); //Pasamos la tecla seleccionada a mundo.cpp
			mundo.key_tecla = key;
			if (key == 'm' || key == 'M') {
				estadoActual = SEL_SAVE;
				break;
			}
			break;
		}
		case EstadoApp::JUEGO_VS_IA:
		{
			if (key == 27) exit(0); // ESC

			if (key == 'm' || key == 'M') {
				estadoActual = SEL_SAVE;
				break;
			}

			mundo.tecla(key);
			mundo.key_tecla = key;
			break;
		}

		case EstadoApp::REGISTROS:
		{
			if (key == 27)
			{
				estadoActual = MENU;
				flag_regis = false;
				reg2 = nullptr;
			}
			if (key == 'B' || key == 'b')
			{
				reg.BorraRegistros(&reg);
			}
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
	if (!mundo.update(estadoActual,reg))
		estadoActual = FIN_JUG;
	
	glutPostRedisplay(); // Redibujar la pantalla
	glutTimerFunc(25, OnTimer, 0);
}