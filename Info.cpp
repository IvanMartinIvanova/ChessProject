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






//#include "ETSIDI.h"
//#include "freeglut.h"
//#include "mundo.h"
//#include "tablero.h"
//
//void OnDraw(void);
//void OnTimer(int value);
//void OnKeyboardDown(unsigned char key, int x, int y);
//
//Tablero tablero;
//Mundo mundo;
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(800, 600);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA | GLUT_MULTISAMPLE);
//	glutCreateWindow("Esfera 3D");
//
//	// Habilitar luces y perspectiva
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//
//	// Configurar perspectiva
//	glMatrixMode(GL_PROJECTION);
//	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
//
//	// Callbacks
//	glutDisplayFunc(OnDraw);
//	glutTimerFunc(25, OnTimer, 0);
//	glutKeyboardFunc(OnKeyboardDown);
//
//	glutMainLoop();
//	return 0;
//}
//
//void OnDraw(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//Para definir el punto de vista
//	glMatrixMode(GL_MODELVIEW);
//	glEnable(GLUT_MULTISAMPLE);
//	glLoadIdentity();
//
//	mundo.dibuja();
//
//	//no borrar esta linea ni poner nada despues
//	glutSwapBuffers();
//}
//
//void OnKeyboardDown(unsigned char key, int x, int y)
//{
//	if (key == 27) // ESC para salir
//		exit(0);
//}
//
//void OnTimer(int value)
//{
//	glutTimerFunc(25, OnTimer, 0);
//	glutPostRedisplay(); // Redibujar la pantalla
//}
//#include "Partida.h"
//
//int main() {
//    Partida p;
//    p.escoger_player();
//    if (p.Progress_Partida()) //Si devuelve True - se ha acabado la partida / Si devuelve FALSE - todavía no ha acabado la partida
//    {
//        return 0;
//    }
//}

// main.cpp
#include <iostream>
#include <string>
#include "Menu.h"
#include "Partida.h"
#include "DATOS_DIBUJO.h"



std::string Conversor(TipoPieza tipo)
{
    switch (tipo)
    {
    case TipoPieza::ALFIL:
    {
        return "alfil";
        break;
    }
    case TipoPieza::CABALLO:
    {
        return "caballo";
        break;
    }
    case TipoPieza::REINA:
    {
        return "reina";
        break;
    }
    case TipoPieza::REY:
    {
        return "rey";
        break;
    }
    case TipoPieza::PEON:
    {
        return "peon";
        break;
    }
    case TipoPieza::TORRE:
    {
        return "torre";
        break;
    }
    default:
    {
        return "vacia";
        break;
    }
    }
}

std::string Conversor2(Colorpieza& color)
{
    switch (color)
    {
    case Colorpieza::BLANCO:
    {
        return "blanco";
        break;
    }

    case Colorpieza::NEGRO:
    {
        return "negro";
        break;
    }
    default:
    {
        return "ninguno";
        break;
    }

    }
}



int main() {
    Menu menu;
    bool salir = false;
    DATOS_DIBUJO datos;
    Casilla pieza_ini, pieza_fin_sG, pieza_fin_cG;
    string tipo_pieza_ini, color_pieza_ini, tipo_pieza_fin_sG, color_pieza_fin_sG, tipo_pieza_fin_cG, color_pieza_fin_cG;
    Partida partida;
    Tablero& tablero = partida.getTablero();
    using namespace std;

    while (!salir) {
        menu.mostrarPrincipal();
        int opcion = menu.obtenerOpcion();
		menu.limpiarPantalla();

        switch (opcion) {
        case 1: {
            partida.inicializar();       //Solo nueva partida lo usa
            partida.escoger_player();
            while (partida.Progress_Partida(datos))
            {
               
                pieza_ini = tablero.buscar_pieza(datos.pieza_origen);
                pieza_fin_sG = tablero.buscar_pieza(datos.pieza_fin_sinGrav);
                pieza_fin_cG = tablero.buscar_pieza(datos.pieza_fin_conGrav);

                if (datos.pieza_origen != nullptr)
                {
                    tipo_pieza_ini = Conversor(datos.pieza_origen->getTipo());
                    color_pieza_ini = Conversor2(datos.pieza_origen->getColor());
                }
                if (datos.pieza_fin_sinGrav != nullptr)
                {
                    tipo_pieza_fin_sG = Conversor(datos.pieza_fin_sinGrav->getTipo());
                    color_pieza_fin_sG = Conversor2(datos.pieza_fin_sinGrav->getColor());
                }
                if (datos.pieza_fin_conGrav != nullptr)
                {
                    tipo_pieza_fin_cG = Conversor(datos.pieza_fin_conGrav->getTipo());
                    color_pieza_fin_cG = Conversor2(datos.pieza_fin_conGrav->getColor());

                }

                cout << "\n Pieza de origen seleccionada " << tipo_pieza_ini << " " << color_pieza_ini << endl;
                cout << "\n Pieza de destino seleccionada antes de aplicar gravedad " << tipo_pieza_fin_sG << " " << color_pieza_fin_sG << endl;
               // cout << "\n Pieza de destino seleccionada despues de aplicar gravedad" << tipo_pieza_fin_cG << " " << color_pieza_fin_cG << endl;
                
            }

            cout << "¿Deseas guardar la partida? (s/n): ";
            char resp; cin >> resp;
            if (resp == 's' || resp == 'S') {
                if (partida.getTablero().guardarPartida("partida_guardada.txt"))
                    cout << "Partida guardada exitosamente.\n";
                else
                    cout << "Error al guardar la partida.\n";
            }

            break;
        }
        case 2: {
            Partida partida;
            if (partida.cargarDesdeArchivo("partida_guardada.txt")) {
                cout << "Partida cargada exitosamente.\n";
                while (partida.Progress_Partida(datos))
                {
                    //Aqui se pondria lo de los datos de dibujo
                }

            }
            else {
                cout << "No se pudo cargar la partida.\n";
            }
            break;
        }
        case 3:
            cout << "Gracias por jugar.\n";
            salir = true;
            break;
        default:
            cout << "Opción invalida. Intenta otra vez.\n";
            break;
        }
    }

    return 0;
}
