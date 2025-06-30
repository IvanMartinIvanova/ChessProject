#include "ListaPiezas.h"

constexpr int MAX_PIEZAS = 24;

void ListaPiezas::dibuja()
{
	for (Pieza* p : lista_piezas)
	{
		p->dibuja(); //Dibujamos cada una de las piezas del jugador
	}
}

void ListaPiezas::agregar(Pieza* p)
{
	if (lista_piezas.size() <= MAX_PIEZAS)
	{
		lista_piezas.push_back(p); //Introducimos la pieza pasando a ser el último elemento de la lista
	}

}

Pieza* ListaPiezas::obtener_pieza(int index) const
{
	return lista_piezas.at(index); //.at devuelve el elemento de la posición index de la lista verificando antes el rango
}

using namespace std;
void ListaPiezas::eliminar(Pieza* p)
{
	int count = 0;
	for (int i = 0; i < this->lista_piezas.size(); i++)
	{
		if (p == lista_piezas[i])
		{
			lista_piezas.erase(lista_piezas.begin() + i);
			break;
		}

	}
}

void ListaPiezas::limpiar()
{
	lista_piezas.clear();
}

ListaPiezas::~ListaPiezas()
{
	//std::cout << "Destruyendo lista de piezas en: " << this << std::endl;
	limpiar();
}
