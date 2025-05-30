#pragma once
#include "ETSIDI.h"
#include <iostream>
#include <map>
#include <string>

constexpr float tamano = 2.0f;

class PiezaGr
{
public:
	bool color; //1->blanco 0->negro
	std::string tipo;
	ETSIDI::Sprite* sprite;

	virtual ~PiezaGr();
	PiezaGr() = default;
	PiezaGr(bool colorin) :sprite{ nullptr }, color{ colorin }, tipo{ NULL } {}

	virtual void draw() = 0;
	void dibuja() { this->draw(); }
	std::string gettipo();
	//virtual void drawmov() = 0;


};

class PeonGr : public PiezaGr
{
public:

	PeonGr(bool colorin) : PiezaGr(colorin)
	{
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, tamano, tamano);
		tipo = "peon";
	};

	void draw() override { sprite->draw(); }
};

class CaballoGr : public PiezaGr
{
public:
	CaballoGr(bool colorin) : PiezaGr(colorin) {
		sprite = new ETSIDI::Sprite("rc/horsey.png", 0, 0, tamano, tamano);
		tipo = "caballo";
	}

	void draw() override { sprite->draw(); };
};

class AlfilGr : public PiezaGr
{
public:
	AlfilGr(bool colorin) : PiezaGr(colorin) {
		sprite = new ETSIDI::Sprite("rc/bizop.png", 0, 0, tamano, tamano);
		tipo = "alfil";
	}

	void draw() override { sprite->draw(); }
};

class TorreGr : public PiezaGr
{
public:
	TorreGr(bool colorin) : PiezaGr(colorin) {
		sprite = new ETSIDI::Sprite("rc/tower.png", 0, 0, tamano, tamano);
		tipo = "torre";
	}

	void draw() override { sprite->draw(); }
};

class ReyGr : public PiezaGr
{
public:
	ReyGr(bool colorin) : PiezaGr(colorin) {
		sprite = new ETSIDI::Sprite("rc/king.png", 0, 0, tamano, tamano);
		tipo = "rey";
	}

	using PiezaGr::PiezaGr;

	void draw() override { sprite->draw(); }
};

class ReinaGr : public PiezaGr
{
public:
	ReinaGr(bool colorin) : PiezaGr(colorin) {
		sprite = new ETSIDI::Sprite("rc/qween.png", 0, 0, tamano, tamano);
		tipo = "reina";
	}

	void draw() override { sprite->draw(); }
};

class VacioGr : public PiezaGr
{
public:
	VacioGr(bool colorin) : PiezaGr(colorin) {
		sprite = nullptr;
		tipo = "vacio";
	}

	void draw() override {  }
};


