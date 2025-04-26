//#include "hombre.h"
//#include "esfera.h"
#include "particulas.h"
//#include "bonus.h"
//#include "disparo.h"
#include "plataforma.h"
#include "estela.h"
#include "ETSIDI.h"

using uchar = unsigned char;

class Mundo
{
private:
	double x_ojo, y_ojo, z_ojo;
	double xmira, ymira, zmira;
	//Disparo disparo;
	//Esfera esfera;
	//Hombre hombre;
	//Caja caja;
	//Bonus bonus;
	Plataforma tablero{ { -10,10,0},{10,-10,-1},{180,0,200} };
	Plataforma piezas1{ {-20,0,0},{-18,-1,-5},{180,0,240} };
	Plataforma piezas2{ {18,0,0},{20,-1,-5},{180,0,240} };

	//Cara fondo{ -100.f, 100.f, 100.f, 100.f, -100.f, -100.f, {180,60,200} };
	//ETSIDI::Sprite* fondo;
	//Sprite(const char *texturePath, float x=0, float y=0, float width = ‐1, float height = ‐1);


public:
	void mueve();
	void dibuja();
	Mundo();
	void rotarOjo();
	void inicializa();
	void tecla(char key);

};