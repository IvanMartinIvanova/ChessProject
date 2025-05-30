#pragma once
#include <iostream>
#include <string>
#include "Menu.h"
#include "Partida.h"
#include "DATOS_DIBUJO.h"
#include "tablero.h"
#include <iostream>

    class Menu {
    public:
        void mostrarPrincipal();
        int obtenerOpcion();
        void limpiarPantalla();
        void Menu_Progress();
        std::string Conversor(const TipoPieza& tipo);
        std::string Conversor2(const Colorpieza& color);
    };


