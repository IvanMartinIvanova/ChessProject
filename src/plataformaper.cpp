#include "plataformaper.h"

PlataformaPer::PlataformaPer() :Plataforma()
{

}

PlataformaPer::PlataformaPer(const bool colorin, const Vector3D& lim1, const Vector3D& lim2, const Color& col): Plataforma (lim1, lim2, col)
{
	personaje = new Active(colorin);
}

void PlataformaPer::dibuja()
{
	Plataforma::dibuja();
	glTranslated(getcentro().x, getcentro().y + 2, getcentro().z);
	personaje->draw();
	glTranslated(-getcentro().x, -getcentro().y - 2, -getcentro().z);
}