#pragma once
#ifndef  PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "ParticleObject.h"
#include <list>

class ParticleSystem
{
private:
	std::list<ParticleObject*> m_particleList;
	float emissionRate;
	float emitTimer = 0;
	Vector m_position;

	Sprite* m_particleSprite;
	
public:
	ParticleSystem(Sprite* sprite);
	
	void update(float fDeltaTime);
	
	void draw();

	void EmitParticle(ParticleObject& particle);

	void setEmissionRate(float rate);
	float getEmissionRate(void);

	void setPosition(Vector pos);
	Vector getPosition(void);

};
#endif // ! PARTICLESYSTEM_H