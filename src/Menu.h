#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Partida.h"
#include "DATOS_DIBUJO.h"
#include "tablero.h"
#include <iostream>

    class Menu {

        char tecla_key;
    public:
        void mostrarPrincipal();
        int obtenerOpcion();
        void limpiarPantalla();
        void Menu_Progress(int option, char tecla);
        std::string Conversor(const TipoPieza& tipo);
        std::string Conversor2(const Colorpieza& color);
        void tecla(char key);
    };


