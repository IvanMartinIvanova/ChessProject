#pragma once

class Tiempo
{
	int min;
	int seg;
public:
	Tiempo() = default;
	Tiempo(int minutos, int segundos) : min(minutos), seg(segundos) 
	{};
};