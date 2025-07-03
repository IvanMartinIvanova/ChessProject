#pragma once
#include "Vector3D.h"
#include "ETSIDI.h"

class Personaje
{
public:
	static double counter;

	bool color; //1->blanco 0->negro
	ETSIDI::SpriteSequence* sprite;

	Personaje() :sprite{ nullptr }, color{ NULL } {}
	Personaje(bool colorin) : color{ colorin }, sprite{ nullptr } {}

	void draw() { dibuja(); }
private:
	virtual void dibuja() = 0;
};

class Idle :public Personaje
{
public:
	Idle(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/idle.png", 2, 1, 50, true, 0, 0, 4, 4, 0);
		//sprite->setState(0, false);

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
		sprite = new ETSIDI::SpriteSequence("rc/finalblow.png", 8, false);

		if (!color)
			sprite->flip(1, 0);
	}

	void dibuja() override
	{
		sprite->draw();
		if (sprite->getState() == 8)
			sprite = new ETSIDI::SpriteSequence("rc/vanish.png", 4, false);
	}
};

class Death : public Personaje
{
public:
	Death(bool colorin) : Personaje(colorin)
	{
		sprite = new ETSIDI::SpriteSequence("rc/idle.png", 8, false);

		if (!color)
			sprite->flip(1, 0);
	}

	void dibuja() override
	{
		sprite->draw();
		if (sprite->getState() == 8)
			sprite->setState(8, true);
	}
};
