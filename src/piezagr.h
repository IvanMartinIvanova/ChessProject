#pragma once
#include "ETSIDI.h"
#include <map>
#include <string>

constexpr float size = 20;

class PiezaGr
{
public:
	bool color;
	virtual void draw() = 0;
	ETSIDI::Sprite* sprite;

	virtual ~PiezaGr();
	PiezaGr();
	PiezaGr(bool colorin) : sprite{nullptr}, color {colorin}{}
	void dibuja()
	{
		this->draw();
	}
};

class PeonGr : public PiezaGr
{
public:
	using PiezaGr::PiezaGr;
	
	PeonGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}


	void draw() override
	{
		sprite->draw();
	}

};

class CaballoGr : public PiezaGr
{
public:
	CaballoGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}
	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};

class AlfilGr : public PiezaGr
{
public:
	AlfilGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}

	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};

class TorreGr : public PiezaGr
{
public:
	TorreGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}

	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};

class ReyGr : public PiezaGr
{
public:
	ReyGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}

	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};

class ReinaGr : public PiezaGr
{
public:
	ReinaGr(bool color) : PiezaGr(color) {
		sprite = new ETSIDI::Sprite("rc/pwaun.png", 0, 0, 20, 20);
	}

	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};

class VacioGr : public PiezaGr
{
	using PiezaGr::PiezaGr;

	void draw() override
	{
		sprite->draw();
	}
};


