#pragma once

struct Tiempo {
	int min;
	int sec;
};
struct Puntos {
	float points;
};
class Registro
{
	Tiempo t;
	Puntos p;
	char nombre[50];
	static int nRegistros;
public:
	//Constructor
	Registro();
	//Gestión número de registros
	int getNumReg();
	void setNumReg(int nReg);
	//Acciones con los registros
	int CreaRegistro(const int& numReg, const char* nom, const Puntos& p, const Tiempo& t);
	void BorraRegistros(const int& numReg, Registro* list);
	Registro* LeeRegistros(Registro* regis, int& n);
	void ImprimeRegistro(Registro* list, const int& nReg) const;

	//Destructor
	~Registro();
	

};

