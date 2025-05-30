#include <piezagr.h>

//PiezaGr::PiezaGr()
//{
//
//}

PiezaGr::~PiezaGr()
{
	delete sprite;
}

std::string PiezaGr::gettipo()
{
	return tipo;
}