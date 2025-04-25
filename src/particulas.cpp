#include "Particulas.h"
#include <math.h>
#include "freeglut.h"

void particulas::dibujae(double orgx, double orgy, double orgz)
{
	glColor3ub(255, 255, 255);

	glBegin(GL_POINTS);
	for (int i = 0; maxpart > i; i++)
	{
		teta = rand() % 360 * 3.1415 / 180;
		fi = rand() % 180 * 3.1415 / 180;
		rad = (rand() % maxrad) / 1000.0;
		glVertex3f(orgx + rad * sin(fi) * cos(teta), orgy + rad * sin(fi) * sin(teta), orgz + rad * cos(fi));
	}
	glEnd();
}

void particulas::dibujac(double orgx, double orgy, double orgz)
{
	

	glBegin(GL_POINTS);
	for (int i = 0; maxpart > i; i++)
	{
		//glColor3ub(rand() % 255, 0, rand() % 255);
		glColor3ub(rand() % 255, 0, rand() % 255);
		teta = rand() % 360 * 3.1415 / 180;
		z = (rand() % 500) / static_cast<float>(100);
		rad = (rand() % 10)/static_cast<float>(30);
		//glVertex3f(orgx + 0.5 * cos(teta), orgy - z,orgz + 0.5 * sin(teta));
		glVertex3f(orgx + rad * cos(teta), orgy - z, orgz + rad * sin(teta));
	}

	for (int i = 0; maxpart > i; i++)
	{
		//glColor3ub(rand() % 255, 0, rand() % 255);
		glColor3ub(rand() % 10, 0, 255);
		teta = rand() % 360 * 3.1415 / 180;
		z = (rand() % 500) / static_cast<int>(100);
		rad = (rand() % 10) / static_cast<float>(20);
		//glVertex3f(orgx + 0.5 * cos(teta), orgy - z,orgz + 0.5 * sin(teta));
		glVertex3f(orgx + rad * cos(teta), orgy - z, orgz + rad * sin(teta));
	}
	glEnd();
}