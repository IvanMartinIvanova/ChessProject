#include "casillaselec.h"

CasillaSelec::CasillaSelec()
{
	file = 3;
	row = 3;
	filein = 3;
	rowin = 3;
}

void CasillaSelec::move(unsigned char tecla)
{
	if ((tecla == 'w') && (filein < 8))
		filein += 1;
	if (tecla == 's' && filein > 1)
		filein -= 1;
	if (tecla == 'd' && rowin < 8)
		rowin += 1;
	if (tecla == 'a' && rowin > 1)
		rowin -= 1;
	if (tecla == ' ')
	{
		file = filein;
		row = rowin;
	}

	std::cout << row << " " << file << std::endl;
	std::cout << CasillaSelec::gettipo(rowin, file) << std::endl;
}


void CasillaSelec::draw(float side, Vector3D org)
{
	getcasilla(rowin, filein).drawselec(side, org);
	//std::cout << file << " " << row << " " << endl;
}

void CasillaSelec::getlista(vector<Casilla>* listain)
{
	lista = listain;
}

PiezaGr* CasillaSelec::getpieza(int rowin, int filein)
{
	Casilla casilla = (*lista)[(rowin - 1) * 8 + (filein - 1)];
	return casilla.getpieza();
}

string CasillaSelec::gettipo(int rowin, int filein)
{
	return getpieza(rowin, filein)->gettipo();
}

Casilla CasillaSelec::getcasilla()
{
	return (*lista)[(row - 1) * 8 + (file - 1)];
}

Casilla CasillaSelec::getcasilla(int row, int file)
{
	return (*lista)[(row - 1) * 8 + (file - 1)];
}

void CasillaSelec::resalta(int side, Vector3D org)
{
	std::string tipo = getcasilla(file,row).gettipo();

	if (tipo == "reina")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (reina(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}
	if (tipo == "peon")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (peon(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}
	if (tipo == "torre")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (torre(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}
	if (tipo == "alfil")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (alfil(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}
	if (tipo == "caballo")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (caballo(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}
	if (tipo == "rey")
	{
		for (auto i = 0; (*lista).size() > i; i++)
		{
			if (rey(CasillaSelec::getcasilla(row, file), (*lista)[i]) == 1)
			{
				(*lista)[i].drawposibl(side, org);
			}
		}
	}

	
}

bool CasillaSelec::reina(Casilla casillap, Casilla casillacheck) 
{
	// La reina puede moverse en línea recta o diagonal
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();

	int dx = abs(xFin - xIni);
	int dy = abs(yFin - yIni);

	std::cout << "balls" << std::endl;

	// Verificamos si el movimiento es en línea recta o en diagonal
	if (dx == 0 || dy == 0 || dx == dy) {
		// Movimiento en línea recta (horizontal o vertical) o en diagonal
		// Verificamos si hay piezas en el camino
		int xStep = (xFin - xIni != 0) ? (xFin - xIni) / abs(xFin - xIni) : 0;
		int yStep = (yFin - yIni != 0) ? (yFin - yIni) / abs(yFin - yIni) : 0;

		int x = xIni + xStep;
		int y = yIni + yStep;

		while (x != xFin || y != yFin) {
			//if (ListaCasillas::listacasillas.gettipo(x, y) != "vacio") {
			if ((*lista)[(x - 1) * 8 + (y - 1)].gettipo() != "vacio") {
				// Hay una pieza en el camino, no se puede mover
				return false;
			}
			x += xStep;
			y += yStep;
		}

		// Si el destino tiene una pieza, podemos comerla (propia o enemiga)
		return true;
	}

	return false;
}

bool CasillaSelec::peon(Casilla casillap, Casilla casillacheck) {
	// Verifica si el peón está moviéndose hacia adelante
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();

	int x1in = xIni, y1in = yIni, x2in = xFin, y2in = yFin;
	if (casillap.getfile() < 9 && casillap.getfile() > 0)
	{
		if (casillap.getpieza()->color == 1) {
			if (xIni == xFin && yFin == yIni + 1 && gettipo(xFin,yFin) == "vacio") {
				return true;  // Avance de una casilla hacia adelante
			}
			if (xIni == xFin && yIni == 2 && yFin == 4 && gettipo(xFin, yFin) == "vacio" && gettipo(xIni, yIni+1) == "vacio") {
				return true;  // Avance de dos casillas hacia adelante
			}
			if (abs(xFin - xIni) == 1 && yFin == yIni + 1 && gettipo(xFin,yFin) != "vacio") {
				return true;  // Captura en diagonal
			}
		}
		else if (casillap.getpieza()->color == 0) {
			if (xIni == xFin && yFin == yIni - 1 && gettipo(xFin, yFin) == "vacio") {
				return true;  // Avance de una casilla hacia adelante
			}
			if (xIni == xFin && yIni == 7 && yFin == 5 && gettipo(xFin, yFin) == "vacio" && gettipo(xIni, yIni - 1) == "vacio") {
				return true;  // Avance de dos casillas hacia adelante
			}
			if (abs(xFin - xIni) == 1 && yFin == yIni - 1 && gettipo(xFin, yFin) != "vacio") {
				return true;  // Captura en diagonal
			}
		}
	}
	return false;  // Si ninguna de las condiciones anteriores se cumple, el movimiento no es válido
}

bool CasillaSelec::torre(Casilla casillap, Casilla casillacheck) 
{
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();
	if (xIni != xFin && yIni != yFin) return false;

	int dx = (xFin > xIni) ? 1 : (xFin < xIni) ? -1 : 0;
	int dy = (yFin > yIni) ? 1 : (yFin < yIni) ? -1 : 0;

	int x = xIni + dx;
	int y = yIni + dy;

	while (x != xFin || y != yFin) {
		if (gettipo(x, y) != "vacio")
			return false;
		x += dx;
		y += dy;
	}

	return true;
}

bool CasillaSelec::alfil(Casilla casillap, Casilla casillacheck) 
{
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();

	int dx = abs(xFin - xIni);
	int dy = abs(yFin - yIni);

	if (dx != dy) return false;  // El Alfil solo se mueve en diagonal

	// Comprobar si el camino está libre
	int xDirection = (xFin - xIni) > 0 ? 1 : -1;
	int yDirection = (yFin - yIni) > 0 ? 1 : -1;

	int x = xIni + xDirection;
	int y = yIni + yDirection;

	while (x != xFin && y != yFin) {
		if (gettipo(x, y) != "vacio") {
			return false;  // Si hay una pieza en el camino, no se puede mover
		}
		x += xDirection;
		y += yDirection;
	}

	return true;
}

bool CasillaSelec::caballo(Casilla casillap, Casilla casillacheck) 
{
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();

	int dx = abs(xFin - xIni);
	int dy = abs(yFin - yIni);
	return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

bool CasillaSelec::rey(Casilla casillap, Casilla casillacheck)
{
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();

	int dx = abs(xFin - xIni);
	int dy = abs(yFin - yIni);
	return (dx <= 1 && dy <= 1 && (dx + dy > 0));
}