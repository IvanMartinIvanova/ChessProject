#define _CRT_SECURE_NO_WARNINGS
#include "Registro.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int Registro::nRegistros = 0;
Registro::Registro():nombre{"Pisco"}, p{0}, t{0,0}
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
int Registro::CreaRegistro(const int& numReg, const char *nom, const Puntos& pt, const Tiempo& temp)
{
	FILE* Reg;
	int n = numReg;
	Reg = fopen("Registros.txt", "a"); //Abrimos el fichero en modo adición
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		fprintf(Reg, " %d ", numReg+1); //Escribimos el nº de registro (empezando por 1, por eso el numReg+1)
		int i = 0;
		while (nom[i] != '\0') //Escribimos el nombre del ganador
		{
			fprintf(Reg, "%c", nom[i]); 
			i++;
		}
		fprintf(Reg, " %f", pt.points); //Escribimos los puntos
		fprintf(Reg, " %d min :%d seg\n", temp.min, temp.sec); //Escribimos el tiempo de la partida
		if (fclose(Reg) != 0)
		{
			perror("No se ha cerrado correctamente el fichero");
		}
		return 0; //Retornamos 0 para resetear la variable temporal oca de Info.cpp para que no influya en siguientes creaciones
	}
}

void Registro::BorraRegistros(const int& numReg, Registro* list) //Elimina todos los registros (Proxima mejora poner esta funcion como independiente y poner una función miembro para borrar registros especificos)
{
	for (int i = 0; i < numReg; i++)
	{
		list[i].~Registro();
	}
	list = nullptr;
	std::ofstream archivo("Registros.txt", std::ios::trunc); //Abrimos el fichero de texto en modo truncado, borrando su contenido pero sin elimar el fichero
	archivo.close();
}

Registro* Registro::LeeRegistros(Registro* regis, int& n)
{
	FILE* Reg;
	int num = 0;
	int j = 0;
	char texto[250];
	char basura[250];
	char espacio;
	char salto;
	int numero = 0;
	int peso = 0;
	int flag = 0;
	num = n;
	Reg = fopen("Registros.txt", "r"); //Abrimos el fichero en modo adición
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		while (feof(Reg) == 0)
		{
			while (flag != -1)
			{
				fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer número que se corresponde con el número de registro
				if(fscanf_s(Reg, "%d", &regis[num].nRegistros) == 1) //Lee el número de registro
				{
					fscanf_s(Reg, "%c", &espacio); //Hace un skip del espacio
					fscanf_s(Reg, "%s", regis[num].nombre, 250); //Lee la cadena de caracteres que se corresponde con el nombre del ganador
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer número que se corresponde con la puntuación
					fscanf_s(Reg, "%f", &regis[num].p); //Lee la puntuación
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer número que se corresponde con los minutos de partida
					fscanf_s(Reg, "%d", &regis[num].t.min); //Lee los minutos de partida
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer número que se corresponde con los segundos de partida
					fscanf_s(Reg, "%d", &regis[num].t.sec); //Lee los minutos de partida
					fscanf_s(Reg, "%[^\n]s", basura, 250); //Hace un skip hasta justo antes del salto de línea
					fscanf_s(Reg, "%c", &salto); //Se come el caracter de salto línea
					num++; //Incrementamos el número de registros leídos
				}
				flag = -1; //Para salir del bucle
			}
			flag = 0; //Reseteamos flag
		}
		n = num; //Actualizamos el valor del número de registros
		if (fclose(Reg) != 0)
		{
			perror("No se ha podido cerrar correctamente el fichero");
		}
		return regis; //Devolvemos la lista de registros
	}
}

void Registro::ImprimeRegistro(Registro* list, const int& nReg) const
{
	int opcion = 0;
	int opcion2 = 0;
	std::cout << "Desea visualizar todos los registros o uno en concreto (1 - TODOS / 2 - Especifico / 3 - NO): ";
	std::cin >> opcion;
	switch (opcion)
	{
	case 1:
	{
		for (int i = 0; i < nReg; i++)
		{
			std::cout << i+1 << ". Nombre: " << list[i].nombre << " Puntuacion: " << list[i].p.points << " Tiempo: " << list[i].t.min << "min : " << list[i].t.sec << "seg" << std::endl;
		}
		break;
	}
	case 2:
		std::cout << "Introduce el numero del registro que quieres ver: ";
		std::cin >> opcion2;
		for (int i = 0; i < nReg; i++)
		{
			if (opcion2 == i+1)
			{
				std::cout << opcion2 << ". Nombre: " << list[i].nombre << " Puntuacion: " << list[i].p.points << " Tiempo: " << list[i].t.min << "min : " << list[i].t.sec << "seg" << std::endl;
			}
		}
		break;
	case 3:
		break;
	default: std::cout << "Opcion Incorrecta";
	}
}
Registro::~Registro()
{

}