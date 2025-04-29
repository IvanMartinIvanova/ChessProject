#define _CRT_SECURE_NO_WARNINGS
#include "Registro.h"
#include <iostream>


Registro::Registro(): nRegistros(0),nombre{"Pisco"}, p{0}, t{0,0}
{

}
int& Registro::CreaRegistro(int& numReg, const char& nom, const Puntos& pt, const Tiempo& temp)
{
	FILE* Reg;
	Reg = fopen("Registros.txt", "a"); //Abrimos el fichero en modo adición
	if (Reg == nullptr) //Comprobamos si ha podido abrir correctamente el fichero
		perror("No se ha encontrado el fichero de registros\n");
	else
	{
		fprintf(Reg, "\n%d", numReg);
		fprintf(Reg, " %s", nom);
		fprintf(Reg, " %f", pt.points);
		fprintf(Reg, " %d min :%d seg\n", t.min, t.sec);
		numReg++;
		return numReg;
	}
}

void Registro::BorraRegistro(int& numReg)
{

}

void Registro::LeeRegistro(const Registro& reg) const
{

}