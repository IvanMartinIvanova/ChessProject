
#include "Menu.h"
#include <iostream>
#include "freeglut.h"


using namespace std;

void Menu::dibujarPantalla()
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
    dibujarTexto(-0.2f, -0.2f, "3. Jugar contra el ordenador");
    dibujarTexto(-0.2f, -0.4f, "4. Registros");
    dibujarTexto(-0.2f, -0.6f, "5. Salir");

    dibujarTexto(-0.3f, -0.8f, "Pulsa 1, 2, 3, 4 o 5 para elegir.");
    glTranslatef(0, 0, -0.1);
}


Menu::Menu(): Pantalla{"rc/banner.png"}
{
    instancia = this;
    // fondo = new ETSIDI::Sprite("rc/fondo.png", 0, 0, .0f, 2.0f);
    banner = new ETSIDI::Sprite("rc/banner.png", 0, 0, 2, 2);
}

