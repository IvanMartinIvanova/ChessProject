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
	int nRegistros;
public:
	Registro();
	int& CreaRegistro(int& numReg, const char& nom, const Puntos& p, const Tiempo& t);
	void BorraRegistro(int& numReg);
	void LeeRegistro(const Registro& reg) const;

};

