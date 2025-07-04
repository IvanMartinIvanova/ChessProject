#pragma once

class Puntuacion {

public:
	float Puntos_totales;
	float Puntos_remaining_piezas;
	float Puntos_piezas_comidas;
	float Puntos_remaining_tiempo;
	Puntuacion() = default;
	Puntuacion(float totales, float piezas_restantes, float piezas_comidas) : 
		Puntos_totales(totales), 
		Puntos_remaining_piezas(piezas_restantes), 
		Puntos_piezas_comidas(piezas_comidas)
	{};
	
};