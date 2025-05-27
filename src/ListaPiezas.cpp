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

void ListaPiezas::eliminar(vector<Pieza*> lista, Pieza* p)
{
	int count = 0;
	for (Pieza* p2 : lista)
	{
		count++;
		if (p2 = p)
		{
			delete p2;
			for (int i = count - 1; i < lista.size(); i++)
			{
				lista[i] = lista[i + 1]; //Ordenamos el vector para dejar como elemento libre (por haber eliminado la pieza) el último de la lista
			}
			lista.pop_back(); //Eliminamos el último elemento de la lista (que deberá estar vacio)

		}

	}
}

void ListaPiezas::limpiar()
{
	lista_piezas.clear();
}

ListaPiezas::~ListaPiezas()
{
	limpiar();
}