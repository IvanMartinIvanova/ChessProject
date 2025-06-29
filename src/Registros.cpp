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
int Registro::CreaRegistro(const int& numReg, const char* nom1, const char* nom2, const Puntuacion& pt1, const Puntuacion& pt2, const Tiempo& temp)
{
	FILE* Reg;
	int n = numReg;
	Reg = fopen("Registros.txt", "a"); //Abrimos el fichero en modo adici�n
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		fprintf(Reg, " %d . ", numReg + 1); //Escribimos el n� de registro (empezando por 1, por eso el numReg+1)
		int i = 0;
		while (nom1[i] != '\0') //Escribimos el nombre del ganador
		{
			fprintf(Reg, "%c", nom1[i]);
			i++;
		}
		fprintf(Reg, "  (Puntos: %f)", pt1.Puntos_totales); //Escribimos los puntos
		fprintf(Reg, " VS ");
		int j = 0;
		while (nom2[i] != '\0') //Escribimos el nombre del ganador
		{
			fprintf(Reg, "%c", nom2[j]);
			j++;
		}
		fprintf(Reg, " (Puntos: %f)", pt2.Puntos_totales); //Escribimos los puntos

		//fprintf(Reg, " %d min :%d seg\n", temp.min, temp.sec); //Escribimos el tiempo de la partida
		if (fclose(Reg) != 0)
		{
			perror("No se ha cerrado correctamente el fichero");
		}
		return 0; //Retornamos 0 para resetear la variable temporal oca de Info.cpp para que no influya en siguientes creaciones
	}
}

void Registro::BorraRegistros(const int& numReg, Registro* list) //Elimina todos los registros (Proxima mejora poner esta funcion como independiente y poner una funci�n miembro para borrar registros especificos)
{
	for (int i = 0; i < numReg; i++)
	{
		list[i].~Registro();
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
	char texto[250];
	char basura[250];
	char espacio;
	char salto;
	int numero = 0;
	int peso = 0;
	int flag = 0;
	num = 0;
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
					fscanf_s(Reg, "%[A-Za-z]", basura,250);
					fscanf_s(Reg, "%s", regis[num].nombre1, 250); //Lee la cadena de caracteres que se corresponde con el nombre del ganador
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con la puntuaci�n
					fscanf_s(Reg, "%f", &regis[num].p1); //Lee la puntuaci�n
					fscanf_s(Reg, "%[A-Za-z]", basura, 250); //Hace un skip hasta la primera letra
					fscanf_s(Reg, "%s", regis[num].nombre2, 250); //Lee la cadena de caracteres que se corresponde con el nombre del ganador
					fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con la puntuaci�n
					fscanf_s(Reg, "%f", &regis[num].p2); //Lee la puntuaci�n
					//fscanf_s(Reg, "%d", &regis[num].t.mins); //Lee los minutos de partida
					//fscanf_s(Reg, "%[^0123456789]s", basura, 250); //Hace un skip hasta el primer n�mero que se corresponde con los segundos de partida
					//fscanf_s(Reg, "%d", &regis[num].t.segs); //Lee los minutos de partida
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
		return regis; //Devolvemos la lista de registros
	}
}

void Registro::ImprimeRegistro(Registro* list, const int& nReg) const
{
	float salto = 0;
		for (int i = 0; i < nReg; i++)
		{
			std::cout << i + 1 << ". Nombre: " << list[i].nombre1 << " Puntuacion: " << list[i].p1.Puntos_totales << " Tiempo: " << list[i].t.mins << "min : " << list[i].t.segs << "seg" << std::endl;
		}
	
	/*case 2:
		std::cout << "Introduce el numero del registro que quieres ver: ";
		std::cin >> opcion2;
		for (int i = 0; i < nReg; i++)
		{
			if (opcion2 == i + 1)
			{
				std::cout << opcion2 << ". Nombre: " << list[i].nombre << " Puntuacion: " << list[i].p.Puntos_totales << " Tiempo: " << list[i].t.mins << "min : " << list[i].t.segs << "seg" << std::endl;
			}
		}
		break;
	case 3:
		break;
	default: std::cout << "Opcion Incorrecta";
	}*/
}
Registro::~Registro()
{

}