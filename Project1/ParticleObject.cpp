#include "ParticleObject.h"

ParticleObject::ParticleObject()
{

}

ParticleObject::ParticleObject(Sprite * spr) : GameObject(spr)
{
	
}

void ParticleObject::SetLife(float l)
{
	m_life = l;
}

float ParticleObject::GetLife()
{
	return m_life;
}

void ParticleObject::SetVelocity(Vector v)
{
	m_velocity = v;
}

const Vector & ParticleObject::GetVelocity()
{
	// TODO: insert return statement here
	return m_velocity;
}

void ParticleObject::SetAcceleration(Vector a)
{
	m_acceleration = a;
}

const Vector & ParticleObject::GetAcceleration()
{
	// TODO: insert return statement here
	return m_acceleration;
}

bool ParticleObject::isDead()
{
	if (m_life < 0.0)
		return true;
	else
		return false;
}

void ParticleObject::Start()
{
	/*particle = new ParticleObject(m_dummySprite2);
	particle->SetVelocity(Vector(2.0f, 2.0f, 0.0f));
	particle->SetAcceleration(Vector(2.0f, 2.0f, 0.0f));*/
}

void ParticleObject::update()
{
	//===========update the position
	//particle->update();

	//acceleration affects velocity
	m_velocity += m_acceleration;

	//velocity affects position
	m_position += m_velocity;

	//decrease the life of particle every update
	m_life--;
}
