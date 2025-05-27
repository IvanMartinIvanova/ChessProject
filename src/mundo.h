#include "particulas.h"
#include "plataforma.h"
#include "estela.h"
#include "sprite3D.h"
#include "ETSIDI.h"
#include "tablerogr.h"
#include "casillaselec.h"

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
	Plataforma tablero{ { -10,10,-5},{10,-10,-6},{255,255,255} };
	Plataforma piezas1{ {-15,-5,0},{-13,-6,-5},{180,0,240} };
	Plataforma piezas2{ {13,-5,0},{15,-6,-5},{180,0,240} };
	TableroGr tablerogr;
	/*Sprite3D fondo{ {0,0,0.1}, "rc/board.png",0,0,25,25)};
	Sprite3D board;*/
	ETSIDI::Sprite* fondo = new ETSIDI::Sprite("rc/sprite_prueba.png", 0, 0, 25, 25);
	

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