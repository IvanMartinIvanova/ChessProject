#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mostrarPrincipal() {
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1. Nueva partida\n";
    cout << "2. Cargar partida \n";
    cout << "3. Salir\n";
	cout << "\n\n\n Para guardar partidas, escribir 'g' en cualquier momento.\n\n Para guardar y salir, escribir 'q'.\n\n\n";
}

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
void Menu::limpiarPantalla() {
    system("cls"); 
}