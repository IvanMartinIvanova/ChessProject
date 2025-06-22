#include "casillaselec.h"

CasillaSelec::CasillaSelec()
{
	row = 8;
	file = 1;
	rowin = 8;
	filein = 1;
}

void CasillaSelec::move(unsigned char tecla)
{
	if (tecla == ' ')
	{
		file = filein;
		row = rowin;
	}
	else
	{
		if (tecla == 'w' && rowin < 8)
			rowin += 1;
		if (tecla == 's' && rowin > 1)
			rowin -= 1;
		if (tecla == 'd' && filein < 8)
			filein += 1;
		if (tecla == 'a' && filein > 1)
			filein -= 1;
	}
	//if (tecla == '\r')
	

	//std::cout << row << " " << file << std::endl;
	//std::cout << CasillaSelec::gettipo(rowin, file) << std::endl;
}


void CasillaSelec::draw(float side, Vector3D org)
{
	getcasilla(filein, rowin).drawselec(side, org);
	getcasilla(filein, rowin).print();
	//std::cout << file << " " << row << " " << endl;
}

void CasillaSelec::getlista(vector<Casilla>* listain)
{
	lista = listain;
}

PiezaGr* CasillaSelec::getpieza(int filein, int rowin)
{
	if (filein > 0 && rowin > 0 && filein < 9 && rowin < 9)
		return (*lista)[(filein - 1) * 8 + (rowin - 1)].getpieza();

	else 
	{
		std::cerr << "Error: coordenadas inválidas (getpieza) (" << filein << ", " << rowin << ")\n";
		std::exit(EXIT_FAILURE);  // Termina el programa con código de error
	}
}

string CasillaSelec::gettipo(int filein, int rowin)
{
	if (filein > 0 && rowin > 0 && filein < 9 && rowin < 9)
		return getpieza(filein, rowin)->gettipo();

	else
	{
		std::cerr << "Error: coordenadas inválidas (gettipo) (" << filein << ", " << rowin << ")\n";
		std::exit(EXIT_FAILURE);  // Termina el programa con código de error
	}
}

Casilla CasillaSelec::getcasilla()
{
	return (*lista)[(file - 1) * 8 + (row - 1)];
}

Casilla CasillaSelec::getcasilla(int file, int row)
{
	if (file > 0 && row > 0 && file < 9 && row < 9)
		return (*lista)[(file - 1) * 8 + (row - 1)];

	else 
	{
		std::cerr << "Error: coordenadas inválidas (getcasilla) (" << file << ", " << row << ")\n";
		std::exit(EXIT_FAILURE);  // Termina el programa con código de error
	}
}


void CasillaSelec::resalta(int side, Vector3D org)
{
	std::string tipo = gettipo(file, row);
	bool color = getpieza(file, row)->getcolor();
	cout << file << " " << row << endl;
	if (color == Tablero::turno)
	{
		if (tipo == "reina")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (reina(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
		if (tipo == "peon")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (peon(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
		if (tipo == "torre")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (torre(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
		if (tipo == "alfil")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (alfil(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
		if (tipo == "caballo")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (caballo(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
		if (tipo == "rey")
		{
			for (auto i = 0; (*lista).size() > i; i++)
			{
				if (rey(CasillaSelec::getcasilla(file, row), (*lista)[i]) == 1)
				{
					(*lista)[i].drawposibl(side, org);
				}
			}
		}
	}
}

bool CasillaSelec::reina(Casilla casillap, Casilla casillacheck)
{


	// La reina puede moverse en l�nea recta o diagonal
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();



	int dx = abs(xFin - xIni);
	int dy = abs(yFin - yIni);

	//std::cout << "balls" << std::endl;

	// Verificamos si el movimiento es en l�nea recta o en diagonal
	if (dx == 0 || dy == 0 || dx == dy) {
		// Movimiento en l�nea recta (horizontal o vertical) o en diagonal
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
	// Verifica si el pe�n est� movi�ndose hacia adelante
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();


	int x1in = xIni, y1in = yIni, x2in = xFin, y2in = yFin;
	if (casillap.getfile() < 9 && casillap.getfile() > 0)
	{
		if (casillap.getpieza()->color == 1) {
			if (xFin == xIni + 1 && yFin == yIni && gettipo(xFin, yFin) == "vacio") {
				return true;  // Avance de una casilla hacia adelante
			}
			if (xIni == 2 && xFin == 4 && yIni == yFin && gettipo(xFin, yFin) == "vacio" && gettipo(xIni + 1, yIni) == "vacio") {
				return true;  // Avance de dos casillas hacia adelante
			}
			if (abs(yFin - yIni) == 1 && xFin == xIni + 1 && gettipo(xFin, yFin) != "vacio") {
				return true;  // Captura en diagonal
			}
		}
		else if (casillap.getpieza()->color == 0) {
			if (xFin == xIni - 1 && yFin == yIni && gettipo(xFin, yFin) == "vacio") {
				return true;  // Avance de una casilla hacia adelante
			}
			if (xIni == 7 && xFin == 5 && yIni == yFin && gettipo(xFin, yFin) == "vacio" && gettipo(xIni - 1, yIni) == "vacio") {
				return true;  // Avance de dos casillas hacia adelante
			}
			if (abs(yFin - yIni) == 1 && xFin == xIni - 1 && gettipo(xFin, yFin) != "vacio") {
				return true;  // Captura en diagonal
			}
		}
	}
	return false;  // Si ninguna de las condiciones anteriores se cumple, el movimiento no es v�lido
}

bool CasillaSelec::torre(Casilla casillap, Casilla casillacheck)
{
	int xIni = casillap.getfile();
	int yIni = casillap.getrow();
	int xFin = casillacheck.getfile();
	int yFin = casillacheck.getrow();
	
	//Para evitar que se seleccionen las diagonales
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

	// Comprobar si el camino est� libre
	int xDirection = (xFin - xIni) > 0 ? 1 : -1;
	int yDirection = (yFin - yIni) > 0 ? 1 : -1;

	int x = xIni + xDirection;
	int y = yIni + yDirection;

	if (x < 1 || y < 1 || x > 7 || y > 7)
		return false;

	while (x != xFin && y != yFin) {
		if (xFin > 0 && yFin > 0) {
			if (gettipo(x, y) != "vacio")
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