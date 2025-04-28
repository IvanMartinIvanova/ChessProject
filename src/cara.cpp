#include "cara.h"
#include <iostream>

Cara::Cara(Vector3D in1, Vector3D in2, Color col = { 238,130,238 }, std::string textin) :
	esq1{ in1 },
	esq2{ in2 },
	color {col},
	text {textin}
{
}

Cara::Cara(float in1x, float in1y, float in1z, float in2x, float in2y, float in2z, Color col = { 238,130,238 }, std::string textin):
	esq1 {in1x,in1y,in1z},
	esq2 {in2x,in2y,in2z},
	color{ col },
	text{ textin }
{
}

Cara::Cara()
{}



void Cara::setpos(const Vector3D& in1, const Vector3D& in2, const Color& cin)
{
	esq1 = in1;
	esq2 = in2;
	color = cin;
}


void Cara::dibujaxy() //dibuja en plano x y en plano y
{
	if (text == "-1") {
		glDisable(GL_CULL_FACE);
		//	glDisable(GL_LIGHTING); //desactiva los efectos sobre lo q se dibuja
		glColor3ub(color.r, color.g, color.b);
		glBegin(GL_QUADS);
		glVertex3d(esq1.x, esq1.y, esq1.z);
		glVertex3d(esq1.x, esq2.y, esq1.z);
		glVertex3d(esq2.x, esq2.y, esq2.z);
		glVertex3d(esq2.x, esq1.y, esq2.z);

		esq1.print();
		esq2.print();
		//std::cout << esq1.x << " " << esq1.y << " " << esq1.z << std::endl;
		//std::cout << esq2.x << " " << esq2.y << " " << esq2.z << std::endl;
		//std::cout << color.r << " " << color.g << " " << color.b << " " << std::endl;
		std::cout << "xy" << std::endl;
		glEnd();
		//glEnable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(text.c_str()).id);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("../rc/skymedow").id);
		

		//	glDisable(GL_LIGHTING); //desactiva los efectos sobre lo q se dibuja
		glColor3ub(color.r, color.g, color.b);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glTexCoord2d(1, 1);  
		glTexCoord2d(1, 0);
		glTexCoord2d(0, 0);
		glVertex3d(esq1.x, esq1.y, esq1.z);
		glVertex3d(esq1.x, esq2.y, esq1.z);
		glVertex3d(esq2.x, esq2.y, esq2.z);
		glVertex3d(esq2.x, esq1.y, esq2.z);

		glDisable(GL_TEXTURE_2D);
		glEnd();
		//glEnable(GL_LIGHTING);
	}
}

void Cara::dibujaz()  //dibuja en plano z
{
	glDisable(GL_CULL_FACE);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_QUADS);

	glVertex3d(esq1.x, esq1.y, esq1.z);
	glVertex3d(esq1.x, esq2.y, esq2.z);
	glVertex3d(esq2.x, esq2.y, esq2.z);
	glVertex3d(esq2.x, esq1.y, esq1.z);

	esq1.print();
	esq2.print();

	std::cout << "z" << std::endl;

	glEnd();
}

void Cara::dibuja()
{
	glDisable(GL_LIGHTING); //desactiva los efectos sobre lo q se dibuja
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(esq1.x, esq1.y, esq1.z);
	glVertex3d(esq2.x, esq2.y, esq1.z);
	glVertex3d(esq2.x, esq2.y, esq2.z);
	glVertex3d(esq1.x, esq2.y, esq2.z);

	glEnd();
	glEnable(GL_LIGHTING);
}
//cara2 = { limite1.x, limite2.y, limite1.z, limite2.x, limite2.y, limite2.z, {0,200,0} };
