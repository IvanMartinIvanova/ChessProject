#pragma once
#include "ETSIDI.h"
#include <freeglut.h>
#include <string>
    class Menu {
    private:
        ETSIDI::Sprite* fondo;
        ETSIDI::Sprite* banner;
        int opcionSeleccionada = 0;

        void dibujarTexto(float x, float y, const char* texto) {
            glColor3f(1, 1, 1);
            glRasterPos2f(x, y);
            while (*texto)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *texto++);
        }

        static Menu* instancia;

        static void dibujarMenuStatic() {
            if (instancia) instancia->dibujarMenu();
        }

        static void tecladoStatic(unsigned char key, int, int) {
            if (instancia) instancia->procesarTecla(key);
        }

        void dibujarMenu() {
            glClear(GL_COLOR_BUFFER_BIT);
            glLoadIdentity();

            // Dibuja fondo y banner
            fondo->draw();
            banner->draw();

            // Dibuja texto opciones (coordenadas adaptables)
            dibujarTexto(-0.3f, 0.2f, "1. Nueva partida");
            dibujarTexto(-0.3f, 0.0f, "2. Cargar partida");
            dibujarTexto(-0.3f, -0.2f, "3. Salir");

            dibujarTexto(-0.45f, -0.6f, "Pulsa 1, 2 o 3 para elegir.");

            glutSwapBuffers();
        }

        void procesarTecla(unsigned char key) {
            if (key >= '1' && key <= '3') {
                opcionSeleccionada = key - '0';
                exit(0);  // Sale del programa, o usa glutLeaveMainLoop si tu FreeGLUT lo soporta
            }
        }

    public:


        void mostrarPrincipal();
        //int obtenerOpcion();
        void limpiarPantalla();

        Menu() {
            instancia = this;
            fondo = new ETSIDI::Sprite("imagenes/fondo.png", 0, 0, 2.0f, 2.0f);
            banner = new ETSIDI::Sprite("imagenes/banner.png", -0.75f, 0.5f, 1.5f, 0.5f);
        }

        void iniciar(int argc, char* argv[]) {
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(800, 600);
            glutCreateWindow("Menu - Ajedrez Gravitacional");

            glClearColor(0, 0, 0, 1);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(-1, 1, -1, 1);

            glutDisplayFunc(dibujarMenuStatic);
            glutIdleFunc(dibujarMenuStatic);
            glutKeyboardFunc(tecladoStatic);

            glutMainLoop();
        }

        int obtenerOpcion() {
            return opcionSeleccionada;
        }

    };

    Menu* Menu::instancia = nullptr;
