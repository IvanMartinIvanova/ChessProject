#pragma once

class Puntuacion {
	float Puntos_totales;
	float Puntos_remaining_piezas;
	float Puntos_piezas_comidas;
	float Puntos_remaining_tiempo;
public:
	Puntuacion() = default;
	Puntuacion(float totales, float piezas_restantes, float piezas_comidas, float tiempo_restante) : 
		Puntos_totales(totales), 
		Puntos_remaining_piezas(piezas_restantes), 
		Puntos_piezas_comidas(piezas_comidas), 
		Puntos_remaining_tiempo(tiempo_restante) 
	{};
};