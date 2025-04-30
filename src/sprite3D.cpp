#include "sprite3D.h"

void Sprite3D::draw()
{
	glPushMatrix();
	glTranslated(pos.x,pos.y,pos.z);
	dir->draw();
	glPopMatrix();

}