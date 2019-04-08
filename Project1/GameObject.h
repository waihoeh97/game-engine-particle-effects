#pragma once
#ifndef  GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GLFW\glfw3.h>

#include "Windows.h"
#include "Sprite.h"
#include "vector.h"

enum enumBlend 
{
	ADD_BLEND,
	MULTI_BLEND,
	ALPHA_BLEND
};

class Color
{
public:
	float r, g, b, a;

	Color()
	{

	}

	Color(float r, float g, float b, float a) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

class GameObject {

protected:
	Sprite* m_sprite;

	Vector m_position;
	float m_rotation;
	float m_scale;
	Vector m_velocity;
	Color m_color;
	enumBlend m_blendMode;
	

public:
	bool goRight = true;
	bool goUp = true;
	GameObject();
	GameObject(Sprite* sprite);

	void SetPos(Vector pos);
	const Vector& GetPos();

	void SetRotation(float rotate);
	float GetRotation();

	void SetScale(float scale);
	float GetScale();

	void SetVelocity(Vector v);
	const Vector& GetVelocity();

	void SetSprite(Sprite* sprite);
	Sprite* GetSprite();

	void SetColor(const Color& color);
	const Color& GetColor();

	void setBlendingMode(enumBlend blend); //allows to set alpha, addictive and multiply blends
	enumBlend getBlendingMode();

	void draw();
	virtual void update();
	virtual void update2();

};
#endif // ! GAMEOBJECT_H
