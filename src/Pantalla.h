#pragma once
#include "ETSIDI.h"
#include <freeglut.h>
#include <string>

class Pantalla
{
protected:
   // ETSIDI::Sprite* espacio;
    ETSIDI::Sprite* imagen;
    int opcionSeleccionada = 0;

    static Pantalla* instancia;
    static void tecladoStatic(unsigned char key, int, int);

    void procesarTecla(unsigned char key);

public:
   virtual void dibujarPantalla();
    void limpiarPantalla();
    void dibujarTexto(float x, float y, const char* texto);
    void dibujarCadena_Caract(float x, float y, const std::string& texto);
    void dibujarNumero(float x, float y, float numero);
    Pantalla();
    Pantalla(const char* png);
    void iniciar(int argc, char* argv[]);
    int obtenerOpcion();

};

