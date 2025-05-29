#include "sprite3D.h"

Sprite3D::Sprite3D()
{}

Sprite3D::Sprite3D(Vector3D posin, ETSIDI::Sprite* dirin)
{
	
	//pos = posin;
	//dir = dirin;
	//dirc = dirin;
}

void Sprite3D::draw()
{
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(dir).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2d(-10, 0);
	glTexCoord2d(1, 1); glVertex2d(10, 0);
	glTexCoord2d(1, 0); glVertex2d(10, 15);
	glTexCoord2d(0, 0); glVertex2d(-10, 15);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glTranslated(pos.x,pos.y,pos.z);
	//dir->draw();
	glPopMatrix();

	glEnable(GLUT_MULTISAMPLE);
}