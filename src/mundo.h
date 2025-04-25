//#include "hombre.h"
//#include "esfera.h"
#include "particulas.h"
//#include "bonus.h"
//#include "disparo.h"
#include "plataforma.h"
#include "estela.h"
//#include "ETSIDI.h"

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
	Plataforma plataforma{ {5,5,5},{3,3,3},{(uchar)238,(uchar)100,(uchar)238} };
	//Cara fondo{ -100.f, 100.f, 100.f, 100.f, -100.f, -100.f, {180,60,200} };
	/*ETSIDI::Sprite* fondo;*/
	//Sprite(const char *texturePath, float x=0, float y=0, float width = ‐1, float height = ‐1);


public:
	void mueve();
	void dibuja();
	Mundo();
	void rotarOjo();
	void inicializa();
	void tecla(char key);

};