//#include "hombre.h"
//#include "esfera.h"
#include "particulas.h"
//#include "bonus.h"
//#include "disparo.h"
#include "plataforma.h"
#include "estela.h"
#include "sprite3D.h"
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
	Plataforma piezas1{ {-20,-2,0},{-18,-3,-5},{180,0,240} };
	Plataforma piezas2{ {18,-2,0},{20,-3,-5},{180,0,240} };
	/*Sprite3D fondo{ {0,0,0.1}, "rc/board.png",0,0,25,25)};
	Sprite3D board;*/
	ETSIDI::Sprite* fondo = new ETSIDI::Sprite("rc/board.png", 0, 0, 25, 25);
	

	//Cara fondo{ -100.f, 100.f, 100.f, 100.f, -100.f, -100.f, {180,60,200} };
	//Sprite(const char *texturePath, float x=0, float y=0, float width = ‐1, float height = ‐1);


public:
	void mueve();
	void dibuja();
	Mundo();
	void rotarOjo();
	void inicializa();
	void tecla(char key);

};