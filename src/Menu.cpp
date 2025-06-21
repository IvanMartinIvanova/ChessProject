//#include "Menu.h"
//#include <limits>
//
//#ifdef max
//#undef max
//#endif
//
//using namespace std;

//void Menu::mostrarPrincipal() {
//    cout << "\n=== MENU PRINCIPAL ===\n";
//    cout << "1. Nueva partida\n";
//    cout << "2. Cargar partida \n";
//    cout << "3. Salir\n";
//	cout << "\n\n\n Para guardar partidas, escribir 'g' en cualquier momento.\n\n Para guardar y salir, escribir 'q'.\n\n\n";
//}
//
//using namespace std;
//int Menu::obtenerOpcion() {
//    int opcion;
//    while (true) {
//        cout << "Selecciona una opcion: ";
//        cin >> opcion;
//
//        if (cin.fail()) {
//            // falló la entrada: el usuario escribió letras u otra cosa
//            cin.clear(); // limpia el estado de error
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia la línea
//            cout << "Entrada invalida. Por favor, introduce un numero.\n";
//        }
//        else {
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpia cualquier cosa que haya quedado
//            return opcion;
//        }
//    }
//}
//
//void Menu::limpiarPantalla() {
//    system("cls"); 
//}
//
//std::string Menu::Conversor(const TipoPieza& tipo)
//{
//    
//        switch (tipo)
//        {
//        case TipoPieza::ALFIL:
//        {
//            return "alfil";
//            break;
//        }
//        case TipoPieza::CABALLO:
//        {
//            return "caballo";
//            break;
//        }
//        case TipoPieza::REINA:
//        {
//            return "reina";
//            break;
//        }
//        case TipoPieza::REY:
//        {
//            return "rey";
//            break;
//        }
//        case TipoPieza::PEON:
//        {
//            return "peon";
//            break;
//        }
//        case TipoPieza::TORRE:
//        {
//            return "torre";
//            break;
//        }
//        default:
//        {
//            return "vacia";
//            break;
//        }
//        }
//}
//
//std::string Menu::Conversor2(const Colorpieza& color)
//{
//    switch (color)
//    {
//    case Colorpieza::BLANCO:
//    {
//        return "blanco";
//        break;
//    }
//
//    case Colorpieza::NEGRO:
//    {
//        return "negro";
//        break;
//    }
//    default:
//    {
//        return "ninguno";
//        break;
//    }
//
//    }
//}
//
//void Menu::tecla(char key)
//{
//    tecla_key = key;
//}
//
//void Menu::Menu_Progress(int option, char tecla)
//{
//
//    bool salir = false;
//    DATOS_DIBUJO datos;
//    Casilla pieza_ini, pieza_fin_sG, pieza_fin_cG;
//    string tipo_pieza_ini, color_pieza_ini, tipo_pieza_fin_sG, color_pieza_fin_sG, tipo_pieza_fin_cG, color_pieza_fin_cG;
//    Partida partida;
//    Tablero& tablero = partida.getTablero();
//    using namespace std;
//
//          int opcion = option;
//
//            switch (opcion) {
//            case 1: {
//                
//                while (partida.Progress_Partida(datos, tecla))
//                {
//
//                    /*pieza_ini = tablero.buscar_pieza(datos.pieza_origen);
//                    pieza_fin_sG = tablero.buscar_pieza(datos.pieza_fin_sinGrav);
//                    pieza_fin_cG = tablero.buscar_pieza(datos.pieza_fin_conGrav);
//
//                    if (datos.pieza_origen != nullptr)
//                    {
//                        tipo_pieza_ini = Conversor(datos.pieza_origen->getTipo());
//                        color_pieza_ini = Conversor2(datos.pieza_origen->getColor());
//                        cout << "\n Pieza de origen seleccionada " << tipo_pieza_ini << " " << color_pieza_ini << endl;
//                    }
//                    if (datos.pieza_fin_sinGrav != nullptr)
//                    {
//                        tipo_pieza_fin_sG = Conversor(datos.pieza_fin_sinGrav->getTipo());
//                        color_pieza_fin_sG = Conversor2(datos.pieza_fin_sinGrav->getColor());
//                        cout << "\n Pieza de destino seleccionada antes de aplicar gravedad " << tipo_pieza_fin_sG << " " << color_pieza_fin_sG << endl;
//                    }
//                    if (datos.pieza_fin_conGrav != nullptr)
//                    {
//                        tipo_pieza_fin_cG = Conversor(datos.pieza_fin_conGrav->getTipo());
//                        color_pieza_fin_cG = Conversor2(datos.pieza_fin_conGrav->getColor());
//                        cout << "\n Pieza de destino seleccionada despues de aplicar gravedad " << tipo_pieza_fin_cG << " " << color_pieza_fin_cG << endl;
//                    }*/
//
//
//                }
//
//                /*cout << "¿Deseas guardar la partida? (s/n): ";
//                char resp; cin >> resp;
//                if (resp == 's' || resp == 'S') {
//                    if (partida.getTablero().guardarPartida("partida_guardada.txt"))
//                        cout << "Partida guardada exitosamente.\n";
//                    else
//                        cout << "Error al guardar la partida.\n";
//                }*/
//
//                break;
//            }
//            case 2: {
//                Partida partida;
//                if (partida.cargarDesdeArchivo("partida_guardada.txt")) {
//                    cout << "Partida cargada exitosamente.\n";
//                    while (partida.Progress_Partida(datos,tecla))
//                    {
//                        //Aqui se pondria lo de los datos de dibujo
//                    }
//
//                }
//                else {
//                    cout << "No se pudo cargar la partida.\n";
//                }
//                break;
//            }
//            case 3:
//                cout << "Gracias por jugar.\n";
//                salir = true;
//                break;
//            default:
//            case 4: {
 //           partida.inicializar_IA();
//
//            bool turnoIA = false, turno_jug = true, aux;
//            Jugador& jug_hum = tablero.getPlayer1();
//            Jugador& IA = tablero.getPlayer2();
//
//            while (partida.Progress_Partida_IA(datos))
//            {
//                if (turno_jug == true) {
//                    pieza_ini = tablero.buscar_pieza(datos.pieza_origen);
//                    pieza_fin_sG = tablero.buscar_pieza(datos.pieza_fin_sinGrav);
//                    pieza_fin_cG = tablero.buscar_pieza(datos.pieza_fin_conGrav);
//
//
//                    if (datos.pieza_origen != nullptr && datos.pieza_origen->getColor() == Colorpieza::BLANCO)
//                    {
//                        tipo_pieza_ini = Conversor(datos.pieza_origen->getTipo());
//                        color_pieza_ini = Conversor2(datos.pieza_origen->getColor());
//                        cout << "\n Pieza de origen seleccionada " << tipo_pieza_ini << " " << color_pieza_ini << endl;
//                    }
//                    if (datos.pieza_fin_sinGrav != nullptr && datos.pieza_origen->getColor() == Colorpieza::BLANCO)
//                    {
//                        tipo_pieza_fin_sG = Conversor(datos.pieza_fin_sinGrav->getTipo());
//                        color_pieza_fin_sG = Conversor2(datos.pieza_fin_sinGrav->getColor());
//                        cout << "\n Pieza de destino seleccionada antes de aplicar gravedad " << tipo_pieza_fin_sG << " " << color_pieza_fin_sG << endl;
//                    }
//                    if (datos.pieza_fin_conGrav != nullptr && datos.pieza_origen->getColor() == Colorpieza::BLANCO)
//                    {
//                        tipo_pieza_fin_cG = Conversor(datos.pieza_fin_conGrav->getTipo());
//                        color_pieza_fin_cG = Conversor2(datos.pieza_fin_conGrav->getColor());
//                        cout << "\n Pieza de destino seleccionada despues de aplicar gravedad " << tipo_pieza_fin_cG << " " << color_pieza_fin_cG << endl;
//                        tablero.comp_coronacion(pieza_fin_cG);
//                    }
//                }
//
//            }
//            break;
//           }
// 
//                cout << "Opción invalida. Intenta otra vez.\n";
//                break;
//            }
//      
//        return;
//}

#include "Menu.h"
#include <iostream>
#include "freeglut.h"

using namespace std;
/*
void Menu::mostrarPrincipal() {
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1. Nueva partida\n";
    cout << "2. Cargar partida \n";
    cout << "3. Salir\n";
    cout << "\n\n\n Para guardar partidas, escribir 'g' en cualquier momento.\n\n Para guardar y salir, escribir 'q'.\n\n\n";
}*/

void Menu::dibujarTexto(float x, float y, const char* texto)
{
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    while (*texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto++);
}

void Menu::dibujarMenuStatic()
{
    if (instancia) instancia->dibujarMenu();
}

void Menu::tecladoStatic(unsigned char key, int, int)
{
    if (instancia) instancia->procesarTecla(key);
}

void Menu::dibujarMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Dibuja fondo y banner
   // fondo->draw();
    banner->draw();
    glTranslatef(0, 0, 0.1);
    // Dibuja texto opciones (coordenadas adaptables)
    dibujarTexto(-0.2f, 0.2f, "1. Nueva partida");
    dibujarTexto(-0.2f, 0.0f, "2. Cargar partida");
    dibujarTexto(-0.2f, -0.2f, "3. Salir");
    dibujarTexto(-0.2f, -0.2f, "4. Jugar contra el ordenador");

    dibujarTexto(-0.3f, -0.6f, "Pulsa 1, 2, 3 o 4 para elegir.");
    glTranslatef(0, 0, -0.1);
}

void Menu::procesarTecla(unsigned char key) {
    if (key >= '1' && key <= '4') {
        opcionSeleccionada = key - '0';
        exit(0);  // Sale del programa, o usa glutLeaveMainLoop si tu FreeGLUT lo soporta
    }
}

Menu::Menu()
{
    instancia = this;
    // fondo = new ETSIDI::Sprite("rc/fondo.png", 0, 0, .0f, 2.0f);
    banner = new ETSIDI::Sprite("rc/banner.png", 0, 0, 2, 2);
}
/*
void Menu::iniciar(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Menu - Ajedrez Gravitacional");

    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

   // glutDisplayFunc(dibujarMenuStatic);
    //glutIdleFunc(dibujarMenuStatic);
    glutKeyboardFunc(tecladoStatic);

    //glutMainLoop();
}*/
int Menu::obtenerOpcion() {
    return opcionSeleccionada;
}

Menu* Menu::instancia = nullptr;

/*
int Menu::obtenerOpcion() {
    int opcion;
    while (true) {
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            // falló la entrada: el usuario escribió letras u otra cosa
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia la línea
            cout << "Entrada invalida. Por favor, introduce un numero.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia cualquier cosa que haya quedado
            return opcion;
        }
    }
}
*/
void Menu::limpiarPantalla() {
    system("cls");
}
