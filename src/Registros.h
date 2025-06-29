#pragma once
#include "Puntuacion.h"
#include "Tiempo.h"

class Registro
{
public:
	Tiempo t;
	Puntuacion p1;
	Puntuacion p2;
	const char* nombre1[50];
	const char* nombre2[50];
	static int nRegistros;
	//Constructor
	Registro();
	//Gestión número de registros
	int getNumReg();
	void setNumReg(int nReg);
	//Acciones con los registros
	int CreaRegistro(const int& numReg, const char* nom1, const char* nom2, const Puntuacion& pt1, const Puntuacion& pt2, const Tiempo& temp);
	void BorraRegistros(const int& numReg, Registro* list);
	Registro* LeeRegistros();
	void ImprimeRegistro(Registro* list, const int& nReg) const;

	//Destructor
	~Registro();


};



