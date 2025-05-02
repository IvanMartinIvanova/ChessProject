#include <iostream>
#include "tablero.h"
#include "Registro.h"
#include <vector>

constexpr int RMAX = 20;
int main() {
	
	int oca=0; //Variable para almacenar tras cada registro el valor del número de registros
	Registro* lista = new Registro[RMAX]; //Lista de registros para TMAX registros

	//Prueba Registros
	
	//Registro1
	const char name[50] = "JERONIMO";
	Puntos point{ 5000 };
	Tiempo tp{ 1,0 };
	Registro nuevo;
	lista = nuevo.LeeRegistros(lista, oca);
	oca = lista[0].getNumReg();
	nuevo.setNumReg(oca);
	oca = nuevo.CreaRegistro(nuevo.getNumReg(), name, point, tp);

	//Registro2
	const char name2[50] = "Benavides";
	Puntos point2{ 2000 };
	Tiempo tp2{ 2,30 };
	Registro nuevo2;
	lista = nuevo2.LeeRegistros(lista, oca);
	nuevo2.setNumReg(oca);
	oca = nuevo2.CreaRegistro(nuevo2.getNumReg(), name2, point2, tp2);

	//Registro3
	const char name3[50] = "Crisantemo";
	Puntos point3{ 7000 };
	Tiempo tp3{ 1,40 };
	Registro nuevo3;
	lista = nuevo3.LeeRegistros(lista, oca);
	nuevo3.setNumReg(oca);
	oca = nuevo3.CreaRegistro(nuevo3.getNumReg(), name3, point3, tp3);

	//Prueba eliminar registros
	int opcion = 0;
	std::cout << "\nQuiere eliminar los registros (1-SI / 2-NO): ";
	std::cin >> opcion;
	if (opcion == 1)
	{
		Registro eliminar;
		lista = eliminar.LeeRegistros(lista, oca);
		eliminar.BorraRegistros(oca, lista);
	}

	//Prueba imprimir registros
	Registro imprimir;
	lista = imprimir.LeeRegistros(lista, oca);
	imprimir.ImprimeRegistro(lista, oca);


	return 0;
}