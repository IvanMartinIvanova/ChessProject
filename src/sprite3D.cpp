#include "sprite3D.h"

Sprite3D::Sprite3D()
{}

Sprite3D::Sprite3D(Vector3D posin, ETSIDI::Sprite* dirin)
{
	
	pos = posin;
	dir = dirin;
}

void Sprite3D::draw()
{
	glDisable(GLUT_MULTISAMPLE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPushMatrix();
	glTranslated(pos.x,pos.y,pos.z);
	dir->draw();
	glPopMatrix();

	glEnable(GLUT_MULTISAMPLE);
}