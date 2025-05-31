#pragma once

class Tiempo
{
	int mins;
	int segs;
public:
	Tiempo() = default;
	Tiempo(int minutos, int segundos) : mins(minutos), segs(segundos) {}
};