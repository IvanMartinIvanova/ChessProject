#pragma once
#include "ETSIDI.h"
#include <freeglut.h>
#include <string>
class Menu {
private:
    ETSIDI::Sprite* fondo;
    ETSIDI::Sprite* banner;
    int opcionSeleccionada = 0;

    void dibujarTexto(float x, float y, const char* texto);

    static Menu* instancia;

    static void dibujarMenuStatic();

    static void tecladoStatic(unsigned char key, int, int);



    void procesarTecla(unsigned char key);

public:
    void mostrarPrincipal();
    void dibujarMenu();
    //int obtenerOpcion();
    void limpiarPantalla();
    Menu();

    void iniciar(int argc, char* argv[]);
    int obtenerOpcion();

};