#pragma once
#ifndef  PARTICLEOBJECT_H
#define PARTICLEOBJECT_H

#include "GameObject.h"

class ParticleObject : public GameObject {
	

public:
	ParticleObject();
	ParticleObject(Sprite* spr);

	Sprite* m_dummySprite2;
	ParticleObject* particle;

	//Vector m_position;
	Vector m_velocity;
	Vector m_acceleration;
	//float m_age;
	float m_life = 100.0f;

	//void SetPos(Vector pos);
	//const Vector& GetPosition();

	void SetLife(float l);
	float GetLife();

	void SetVelocity(Vector v);
	const Vector& GetVelocity();

	void SetAcceleration(Vector a);
	const Vector& GetAcceleration();

	bool isDead();

	void Start();
	virtual void update();

};
#endif // ! PARTICLEOBJECT_H




