#pragma once
#include "ETSIDI.h"
#include <iostream>
#include <map>
#include <string>
#include<vector>

constexpr float tamano = 2.0f;

class PiezaGr
{
public:
	bool color; //1->blanco 0->negro
	std::string tipo;
	ETSIDI::Sprite* sprite;
	int skin;

	static std::map<int, std::map<std::string, std::map<bool, std::string>>> direcciones;

	virtual ~PiezaGr();
	PiezaGr() = default;
	PiezaGr(bool colorin, int skinin = 1) :sprite{ nullptr }, color{ colorin }, tipo{ NULL }, skin{ skinin } {}

	std::string getdirecciones(int skin, std::string tipo, bool color);

	virtual void draw() = 0;
	void dibuja() { this->draw(); }
	bool getcolor() { return color; }
	std::string gettipo();
};

class PeonGr : public PiezaGr
{
public:

	PeonGr(bool colorin, int skinin) : PiezaGr(colorin, skinin)
	{
		sprite = new ETSIDI::Sprite(getdirecciones(skin, "peon", colorin).c_str(), 0, 0, tamano, tamano);
		tipo = "peon";
	};

	void draw() override { sprite->draw(); }
};

class CaballoGr : public PiezaGr
{
public:
	CaballoGr(bool colorin, int skinin) : PiezaGr(colorin, skinin)
	{
		sprite = new ETSIDI::Sprite(getdirecciones(skin, "caballo", color).c_str(), 0, 0, tamano, tamano);
		tipo = "caballo";
	}

	void draw() override { sprite->draw(); };
};

class AlfilGr : public PiezaGr
{
public:
	AlfilGr(bool colorin, int skinin) : PiezaGr(colorin, skinin) {

		sprite = new ETSIDI::Sprite(getdirecciones(skin, "alfil", color).c_str(), 0, 0, tamano, tamano);
		tipo = "alfil";
	}
	void draw() override { sprite->draw(); }
};

class TorreGr : public PiezaGr
{
public:
	TorreGr(bool colorin, int skinin) : PiezaGr(colorin, skinin) {

		sprite = new ETSIDI::Sprite(getdirecciones(skin, "torre", color).c_str(), 0, 0, tamano, tamano);
		tipo = "torre";
	}

	void draw() override { sprite->draw(); }
};

class ReyGr : public PiezaGr
{
public:
	ReyGr(bool colorin, int skinin) : PiezaGr(colorin, skinin) {

		sprite = new ETSIDI::Sprite(getdirecciones(skin, "rey", color).c_str(), 0, 0, tamano, tamano);
		tipo = "rey";
	}



	void draw() override { sprite->draw(); }
};

class ReinaGr : public PiezaGr
{
public:
	ReinaGr(bool colorin, int skinin) : PiezaGr(colorin, skinin) {

		sprite = new ETSIDI::Sprite(getdirecciones(skin, "reina", color).c_str(), 0, 0, tamano, tamano);
		tipo = "reina";
	}

	void draw() override { sprite->draw(); }
};

class VacioGr : public PiezaGr
{
public:
	VacioGr() {
		color = NULL;
		sprite = nullptr;
		tipo = "vacio";
	}

	void draw() override {  }
};