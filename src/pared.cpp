#include "freeglut.h"
#include "Color.h"
#include "pared.h"

Pared::Pared(){}

Pared::Pared(const Vector3D& lim1, const Vector3D& lim2, const Color& col):
limite1 { lim1 },
limite2 { lim2 },
color{ col }
{

}

void Pared::set_color(Color& col)
{
	color = col;
}

void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_QUADS);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::dibuja2()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, limite1.z);
	glVertex3d(limite1.x, limite2.y, limite2.z);
	glVertex3d(limite2.x, limite2.y, limite1.z);
	glVertex3d(limite2.x, limite2.y, limite2.z);

	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::cchange()
{
	color.change();
}

