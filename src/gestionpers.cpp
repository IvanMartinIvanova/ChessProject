#include "gestionpers.h"

void GestionPers::dibuja()
{
	blanco.dibuja();
	negro.dibuja();
	GestionPers::gestion();
}
void GestionPers::gestion()
{
	if (!Tablero::wwins && !Tablero::bwins)
	{
		if (Tablero::turno)
		{
			blanco.setstate(new Active(1));
			negro.setstate(new Idle(0));
		}
		else 
		{
			blanco.setstate(new Idle(1));
			negro.setstate(new Active(0));
		}
	}
	if (Tablero::wwins && !Tablero::bwins)
	{
		blanco.setstate(new Finalblow(1));
		negro.setstate(new Death(0));
	}
	if (!Tablero::wwins && Tablero::bwins)
	{
		blanco.setstate(new Death(1));
		negro.setstate(new Finalblow(0));
	}
	if (Tablero::wwins && Tablero::bwins)
	{
		blanco.setstate(new Finalblow(1));
		negro.setstate(new Finalblow(0));
	}
}