//#pragma once
//#include <iostream>
//#include <string>
//#include "Menu.h"
//#include "Partida.h"
//#include "DATOS_DIBUJO.h"
//#include "tablero.h"
//#include <iostream>
//
//    class Menu {
//
//        char tecla_key;
//    public:
//        void mostrarPrincipal();
//        int obtenerOpcion();
//        void limpiarPantalla();
//        void Menu_Progress(int option, char tecla);
//        std::string Conversor(const TipoPieza& tipo);
//        std::string Conversor2(const Colorpieza& color);
//        void tecla(char key);
//    };

#pragma once
#include "ETSIDI.h"
#include <freeglut.h>
#include <string>
class Menu {
private:
    ETSIDI::Sprite* fondo;
    ETSIDI::Sprite* banner;
    int opcionSeleccionada = 0;

    static Menu* instancia;

    static void dibujarMenuStatic();

    static void tecladoStatic(unsigned char key, int, int);



    void procesarTecla(unsigned char key);

public:
    void mostrarPrincipal();
    void dibujarMenu();
    //int obtenerOpcion();
    void limpiarPantalla();
    void dibujarTexto(float x, float y, const char* texto);
    void dibujarCadena_Caract(float x, float y, const std::string& texto);
    Menu();
    void iniciar(int argc, char* argv[]);
    int obtenerOpcion();

};



