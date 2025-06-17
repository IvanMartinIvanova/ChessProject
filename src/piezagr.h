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
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/Pawn_Black.png", 0, 0, tamano, tamano);
			tipo = "peon";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/Pawn_White.png", 0, 0, tamano, tamano);
			tipo = "peon";
		}
	};

	void draw() override { sprite->draw(); }
};

class CaballoGr : public PiezaGr
{
public:
	CaballoGr(bool colorin) : PiezaGr(colorin) {
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/Horse_Black.png", 0, 0, tamano, tamano);
			tipo = "caballo";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/Horse_White.png", 0, 0, tamano, tamano);
			tipo = "caballo";
		}
	}

	void draw() override { sprite->draw(); };
};

class AlfilGr : public PiezaGr
{
public:
	AlfilGr(bool colorin) : PiezaGr(colorin) {
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/Bizhop_Black.png", 0, 0, tamano, tamano);
			tipo = "alfil";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/Bizhop_White.png", 0, 0, tamano, tamano);
			tipo = "alfil";
		}
	}
	void draw() override { sprite->draw(); }
};

class TorreGr : public PiezaGr
{
public:
	TorreGr(bool colorin) : PiezaGr(colorin) {
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/Tower_Black.png", 0, 0, tamano, tamano);
			tipo = "torre";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/Tower_White.png", 0, 0, tamano, tamano);
			tipo = "torre";
		}
	}

	void draw() override { sprite->draw(); }
};

class ReyGr : public PiezaGr
{
public:
	ReyGr(bool colorin) : PiezaGr(colorin) {
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/King_Black.png", 0, 0, tamano, tamano);
			tipo = "rey";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/King_White.png", 0, 0, tamano, tamano);
			tipo = "rey";
		}
	}



	void draw() override { sprite->draw(); }
};

class ReinaGr : public PiezaGr
{
public:
	ReinaGr(bool colorin) : PiezaGr(colorin) {
		if (colorin == 0) {
			sprite = new ETSIDI::Sprite("rc/Queen_Black.png", 0, 0, tamano, tamano);
			tipo = "reina";
		}
		else if (colorin == 1) {
			sprite = new ETSIDI::Sprite("rc/Queen_White.png", 0, 0, tamano, tamano);
			tipo = "reina";
		}
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