#include "particulas.h"
#include "plataforma.h"
#include "estela.h"
#include "sprite3D.h"
#include "ETSIDI.h"
#include "tablerogr.h"
#include "casillaselec.h"
#include "Partida.h"
#include "Registros.h"
#include "Menu.h"
#include "gestionpers.h"
#include "plataformaper.h"
#include <vector>

using uchar = unsigned char;

//enum class EstadoJuego { MENU, JUGANDO, ESPERANDO_INPUT, FIN_PARTIDA};

class Mundo
{
private:
	double x_ojo, y_ojo, z_ojo;
	double xmira, ymira, zmira;
	const int scale = 20;
	const float lejos = 4;
	int counter = 0;
	//Disparo disparo;
	//Esfera esfera;
	//Hombre hombre;
	//Caja caja;
	//Bonus bonus;
	Plataforma tablero{ { -10,10,-5},{10,-10,-6},{255,255,255} };
	GestionPers personajes;
	TableroGr tablerogr;


	//Cara fondo{ -100.f, 100.f, 100.f, 100.f, -100.f, -100.f, {180,60,200} };
	//Sprite(const char *texturePath, float x=0, float y=0, float width = ‐1, float height = ‐1);


public:
	Jugador player1;
	Jugador player2;
	Partida partida;
	Menu menu_juego;
	DATOS_DIBUJO datos;
	int flag_juego;
	bool flag_fin_partida;
	int opcion_modo;
	char key_tecla;
	void mueve();
	void dibuja();
	Mundo();
	void rotarOjo();
	void inicializa(const int& skin_player1, const int& skin_player2);
	void tecla(char key);
	TableroGr& getTablerogr();
	int getFlag();
	bool update(int estado, Registro& reg);
};