#pragma once

class DATOS_DIBUJO {

public:
	Pieza* pieza_origen = nullptr;
	Pieza* pieza_fin_sinGrav = nullptr;
	Pieza* pieza_fin_conGrav = nullptr;

	bool jaqueMate = false;
};
