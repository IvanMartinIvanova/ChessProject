

#pragma once
#include "ETSIDI.h"
#include "Pantalla.h"
#include <freeglut.h>
#include <string>
class Menu : public Pantalla{
private:

    ETSIDI::Sprite* fondo;
    ETSIDI::Sprite* banner;
    int opcionSeleccionada = 0;

   public:
    void dibujarPantalla() override;
    Menu();

    /*void iniciar(int argc, char* argv[]);
    int obtenerOpcion();*/

};



