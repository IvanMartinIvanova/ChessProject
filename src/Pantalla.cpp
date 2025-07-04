#include "Pantalla.h"
#include <iostream>
#include "freeglut.h"
#include <sstream>
#include <iomanip>

using namespace std;

Pantalla* Pantalla::instancia = nullptr;

void Pantalla::dibujarTexto(float x, float y, const char* texto)
{
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    while (*texto)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto++);
}

void Pantalla::dibujarCadena_Caract(float x, float y, const std::string& texto)
{
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    for (char c : texto)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void Pantalla::dibujarNumero(float x, float y, float numero)
{
    string num;
    ostringstream stream;
    stream << std::fixed << std::setprecision(2) << numero; //Ajustamos el n�mero de decimales del float
    dibujarCadena_Caract(x, y, stream.str()); //Pasamos el n�mero con los decimales ajustados convertido a una string
}

void Pantalla::dibujarPantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Dibuja fondo y banner
    //espacio->draw();
    imagen->draw();
    glTranslatef(0, 0, 0.1);
}

void Pantalla::tecladoStatic(unsigned char key, int, int)
{
    if (instancia) instancia->procesarTecla(key);
}


void Pantalla::procesarTecla(unsigned char key) {
    if (key >= '1' && key <= '4') {
        opcionSeleccionada = key - '0';
        exit(0);  // Sale del programa, o usa glutLeaveMainLoop si tu FreeGLUT lo soporta
    }
}

Pantalla::Pantalla(const char* png)
{
    instancia = this;
    // fondo = new ETSIDI::Sprite("rc/fondo.png", 0, 0, .0f, 2.0f);
    imagen = new ETSIDI::Sprite(png, 0, 0, 2, 2);
}


int Pantalla::obtenerOpcion() {
    return opcionSeleccionada;
}

void Pantalla::limpiarPantalla() {
    system("cls");
}