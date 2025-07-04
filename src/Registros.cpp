#define _CRT_SECURE_NO_WARNINGS
#include "Registros.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Pantalla.h"
int Registro::nRegistros = 0;
Registro::Registro() :nombre1{}, nombre2{}, p1{}, p2{}, t { 0, 0 }
{

}

int Registro::getNumReg()
{
	return nRegistros;
}

void Registro::setNumReg(int nReg)
{
	nRegistros = nReg;
}
int Registro::CreaRegistro(const char* nom1, const char* nom2, const Puntuacion& pt1, const Puntuacion& pt2)
{
	FILE* Reg;
	int n = this->getNumReg();
	Reg = fopen("Registros.txt", "a"); //Abrimos el fichero en modo adici�n
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		fprintf(Reg, " %d . ", n + 1); //Escribimos el n� de registro (empezando por 1, por eso el numReg+1)
		int i = 0;
		while (nom1[i] != '\0') //Escribimos el nombre del ganador
		{
			fprintf(Reg, "%c", nom1[i]);
			i++;
		}
		fprintf(Reg, "  (Puntos: %f)", pt1.Puntos_totales); //Escribimos los puntos
		fprintf(Reg, " VS ");
		int j = 0;
		while (nom2[j] != '\0') //Escribimos el nombre del ganador
		{
			fprintf(Reg, "%c", nom2[j]);
			j++;
		}
		fprintf(Reg, " (Puntos: %f)", pt2.Puntos_totales); //Escribimos los puntos
		fprintf(Reg, "\n");
		n++;
		this->setNumReg(n);
		//fprintf(Reg, " %d min :%d seg\n", temp.min, temp.sec); //Escribimos el tiempo de la partida
		if (fclose(Reg) != 0)
		{
			perror("No se ha cerrado correctamente el fichero");
		}
		return 0; //Retornamos 0 para resetear la variable temporal oca de Info.cpp para que no influya en siguientes creaciones
	}
}

void Registro::BorraRegistros(Registro* list) //Elimina todos los registros 
{
	for (int i = 0; i < this->nRegistros; i++)
	{
		this[i].~Registro();
	}
	list = nullptr;
	std::ofstream archivo("Registros.txt", std::ios::trunc); //Abrimos el fichero de texto en modo truncado, borrando su contenido pero sin elimar el fichero
	archivo.close();
}

Registro* Registro::LeeRegistros()
{
	Registro* regis{};
	int capacidadInicial = 100;  // o cualquier n�mero m�ximo esperado
	regis = new Registro[capacidadInicial];
	FILE* Reg;
	int num = 0;
	int j = 0;
	char basura[250];
	char salto = 0;
	int flag = 0;
	Reg = fopen("Registros.txt", "r"); //Abrimos el fichero en modo adici�n
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		while (feof(Reg) == 0)
		{
			while (flag != -1)
			{
				fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con el n�mero de registro
				if (fscanf_s(Reg, "%d", &regis[num].nRegistros) == 1) //Lee el n�mero de registro
				{
					fscanf_s(Reg, "%[^A-Za-z]", basura,250);
					fscanf_s(Reg, "%[A-Za-z]", regis[num].nombre1, 50); //Lee la cadena de caracteres que se corresponde con el nombre del player1
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con la puntuaci�n
					fscanf_s(Reg, "%f", &regis[num].p1); //Lee la puntuaci�n del player1
					fscanf_s(Reg, "%[^A-Za-z]", basura, 250); //Hace un skip hasta la primera letra
					fscanf_s(Reg, "%[A-Za-z]", basura, 250); //Leemos el VS
					fscanf_s(Reg, "%[^A-Za-z]", basura, 250); //Hace un skip hasta la primera letra
					fscanf_s(Reg, "%[A-Za-z]", regis[num].nombre2, 50); //Lee la cadena de caracteres que se corresponde con el nombre del player2
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con la puntuaci�n
					fscanf_s(Reg, "%f", &regis[num].p2); //Lee la puntuaci�n del player2
					fscanf_s(Reg, "%[^\n]s", basura, 250); //Hace un skip hasta justo antes del salto de l�nea
					fscanf_s(Reg, "%c", &salto); //Se come el caracter de salto l�nea
					num++; //Incrementamos el n�mero de registros le�dos
				}
				flag = -1; //Para salir del bucle
			}
			flag = 0; //Reseteamos flag
		}
		if (fclose(Reg) != 0)
		{
			perror("No se ha podido cerrar correctamente el fichero");
		}
		this->setNumReg(num);
		return regis; //Devolvemos la lista de registros
	}
}

void Registro::ImprimeRegistro(Registro* list, const int& nReg) const
{
	float salto = 0;
		for (int i = 0; i < nReg; i++)
		{
			std::cout << i + 1 << ". PLAYER1: " << list[i].nombre1 << " Puntuacion: " << list[i].p1.Puntos_totales <<  " VS " << "PLAYER2: " << list[i].nombre2 << " Puntuacion: " << list[i].p2.Puntos_totales << std::endl;
		}
	
	
}
Registro::~Registro()
{

}