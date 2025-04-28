#include "plataforma.h"
#include <iostream>

float Plataforma::counter = 0;

Plataforma::Plataforma() {}

Plataforma::Plataforma(const Vector3D& lim1, const Vector3D& lim2, const Color& col) :
	limite1{ lim1 },
	limite2{ lim2 },
	color{ col },
	/*cara1{ lim1.x, lim1.y, lim1.z, lim2.x, lim1.y, lim2.z, {200,0,0} },
	cara2{ lim1.x, lim2.y, lim1.z, lim2.x, lim2.y, lim2.z, {0,200,0} },
	cara3{ lim1.x, lim1.y, lim1.z, lim2.x, lim2.y, lim1.z, {0,0,200} },
	cara4{ lim1.x, lim1.y, lim2.z, lim2.x, lim2.y, lim2.z, {200,200,0} },
	cara5{ lim2.x, lim1.y, lim1.z, lim2.x, lim2.y, lim2.z, {200,0,200} },
	cara6{ lim1.x, lim1.y, lim1.z, lim1.x, lim2.y, lim2.z, {0,200,200} },*/
	estela{ (limite1.x + limite2.x) / 2,limite2.y,(limite1.z + limite2.z) / 2 },
	limest1{lim1},
	limest2{lim2}
{
}

void Plataforma::dibuja()
{
	Plataforma::calcidle();

	cara1.dibujaz();
	cara2.dibujaz();
	cara3.dibujaxy();
	cara4.dibujaxy();
	cara5.dibujaxy();
	cara6.dibujaxy();

	estela.dibuja();
//	std::cout << counter <<" ";
	//std::cout << color.r << " " << color.g << " " << color.b << " " << std::endl;
}


void Plataforma::set_color(Color& col)
{
	color = col;
}

void Plataforma::calcidle()
{
	limite1.x = limest1.x;
	limite1.y = limest1.y + 0.3*sin(counter);
	limite1.z = limest1.z;

	limite2.x = limest2.x;
	limite2.y = limest2.y + 0.3*sin(counter);
	limite2.z = limest2.z;

	estela.setorg({ (limite1.x + limite2.x) / 2,limite2.y,(limite1.z + limite2.z) / 2 });

	cara1.setpos({ limite1.x, limite1.y, limite1.z }, { limite2.x, limite1.y, limite2.z }, { 200,0,0 });
	cara2.setpos({ limite1.x, limite2.y, limite1.z }, { limite2.x, limite2.y, limite2.z }, { 0,200,0 });
	cara3.setpos({ limite1.x, limite1.y, limite1.z }, { limite2.x, limite2.y, limite1.z }, { 0,0,200 });
	cara4.setpos({ limite1.x, limite1.y, limite2.z }, { limite2.x, limite2.y, limite2.z }, { 200,200,0 });
	cara5.setpos({ limite2.x, limite1.y, limite1.z }, { limite2.x, limite2.y, limite2.z }, { 200,0,200 });
	cara6.setpos({ limite1.x, limite1.y, limite1.z }, { limite1.x, limite2.y, limite2.z }, { 0,200,200 });
	
	/*cara1 = { {limite1.x, limite1.y, limite1.z}, {limite2.x, limite1.y, limite2.z}, {200,0,0} };
	cara2 = { {limite1.x, limite2.y, limite1.z}, {limite2.x, limite2.y, limite2.z }, { 0,200,0 }};
	cara3 = { limite1.x, limite1.y, limite1.z, limite2.x, limite2.y, limite1.z, {0,0,200} };
	cara4 = { limite1.x, limite1.y, limite2.z, limite2.x, limite2.y, limite2.z, {200,200,0} };
	cara5 = { limite2.x, limite1.y, limite1.z, limite2.x, limite2.y, limite2.z, {200,0,200} };
	cara6 = { limite1.x, limite1.y, limite1.z, limite1.x, limite2.y, limite2.z, {0,200,200} };*/

}