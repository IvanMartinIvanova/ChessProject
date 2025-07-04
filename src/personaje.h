#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"
#include "Partida.h"
#include "piezagr.h"

class Personaje
{
public:
	static double counter;

	bool color; //1->blanco 0->negro
	ETSIDI::SpriteSequence* sprite;
	string state;

	Personaje() :sprite{ nullptr }, color{ NULL } {}
	Personaje(bool colorin) : color{ colorin }, sprite{ nullptr }, state{ NULL } {}

	void draw() { dibuja(); }
	int getstage() { return sprite->getState(); }
	string getstate() { return state; }
private:
	virtual void dibuja() = 0;
};

class Idle :public Personaje
{
public:
	Idle(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/idle.png", 2, 1, 50, true, 0, 0, 4, 4, 0);
		state = "idle";

		if (!color)
			sprite->flip(1, 0);
	}
	void dibuja() override
	{
		sprite->draw();
		sprite->loop();
	}
};

class Active : public Personaje
{
public:
	Active(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/active.png", 8, 1, 50, true, 0, 0, 4, 4, 0);
		state = "active";

		if (!color)
			sprite->flip(1, 0);
	}

	void dibuja() override
	{
		sprite->draw();
		sprite->loop();
	}
};

class Finalblow : public Personaje
{

public:
	Finalblow(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/finalblow.png", 12, 1, 50, false, 0, 0, 4, 4, 0);
		state = "finalblow";

		if (!color)
			sprite->flip(1, 0);
	}

	void dibuja() override
	{
		sprite->draw();
		sprite->loop();
	}
};

class Death : public Personaje
{
public:
	Death(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/death.png", 8, 1, 50, false, 0, 0, 4, 4, 0);
		state = "death";

		if (!color)
			sprite->flip(1, 0);
	}

	void dibuja() override
	{
		sprite->draw();
		sprite->loop();
	}
};