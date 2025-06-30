#pragma once

class Tiempo
{
public:
	int mins;
	int segs;
	Tiempo() = default;
	Tiempo(int minutos, int segundos) : mins(minutos), segs(segundos) {}
	friend class Jugador;
};