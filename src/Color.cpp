#include "Color.h"
#include "freeglut.h"
using uchar = unsigned char;

void Color::change()
{
		r = 255 - r;
		g = 255 - g;
		b = 255 - b;
}

void Color::pon_color()
{
	glColor3ub(r, g, b);
}