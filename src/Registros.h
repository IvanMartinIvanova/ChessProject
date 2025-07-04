#pragma once
#include "Puntuacion.h"
#include "Tiempo.h"

class Registro
{
public:
	Tiempo t;
	Puntuacion p1;
	Puntuacion p2;
	char nombre1[50];
	char nombre2[50];
	static int nRegistros;
	//Constructor
	Registro();
	//Gesti�n n�mero de registros
	int getNumReg();
	void setNumReg(int nReg);
	//Acciones con los registros
	int CreaRegistro(const char* nom1, const char* nom2, const Puntuacion& pt1, const Puntuacion& pt2);
	void BorraRegistros(Registro* list);
	Registro* LeeRegistros();
	void ImprimeRegistro(Registro* list, const int& nReg) const;

	//Destructor
	~Registro();


};



