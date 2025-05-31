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
    dibujarTexto(-0.25f, 0.2f, "1. Nueva partida");
    dibujarTexto(-0.25f, 0.0f, "2. Cargar partida");
    dibujarTexto(-0.25f, -0.2f, "3. Salir");

    dibujarTexto(-0.3f, -0.6f, "Pulsa 1, 2 o 3 para elegir.");
    glTranslatef(0, 0, -0.1);
}

void Menu::procesarTecla(unsigned char key) {
    if (key >= '1' && key <= '3') {
        opcionSeleccionada = key - '0';
        exit(0);  // Sale del programa, o usa glutLeaveMainLoop si tu FreeGLUT lo soporta
    }
}

Menu::Menu()
{
    instancia = this;
   // fondo = new ETSIDI::Sprite("rc/fondo.png", 0, 0, .0f, 2.0f);
    banner = new ETSIDI::Sprite("rc/banner.png", -0.4, -0.4, 4.0f, 4.0f);
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