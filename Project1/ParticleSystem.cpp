#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Sprite * sprite)
{
	m_particleSprite = sprite;
	emissionRate = 1.0f;
	emitTimer = 0.0f;
}

void ParticleSystem::update(float fDeltaTime)
{
	emitTimer += emissionRate;

	while (emitTimer >= emissionRate)
	{
		float angle = (float)rand() / RAND_MAX * 360.0f * (M_PI / 180.0f);

		ParticleObject* PO = new ParticleObject(m_particleSprite);
		
		PO->SetPos(m_position);
		PO->SetVelocity(Vector(rand() % (20 - 10 + 1) * cos(angle), rand() % (20 - 10 + 1), 0) * sin(angle));
		PO->SetScale(0.5f);
		PO->setBlendingMode(ADD_BLEND);
		PO->SetColor(Color(1, 1, 1, 1));
		
		m_particleList.push_back(PO);
		emitTimer = 0;
	}

	std::list<ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* po = *iter;
		po->update();

		if (po->GetLife() <= 0)
		{
			iter = m_particleList.erase(iter);
			delete po;
		}
		else
		{
			iter++;
		}
	}
}

void ParticleSystem::draw(void)
{
	// Call all particles draw function
	std::list<ParticleObject*>::iterator it = m_particleList.begin();
	while (it != m_particleList.end())
	{
		ParticleObject& particle = (**it);
		particle.draw();
		it++;
	}
}

void ParticleSystem::EmitParticle(ParticleObject& particle)
{
	if (m_particleSprite == NULL)
	{
		//RandomizeParticle(particle);
	}
	else
	{
		for (unsigned int i = 0; i < m_particleList.size(); ++i)
		{
			ParticleObject& particle = ParticleObject();
		}
	}
}


void ParticleSystem::setEmissionRate(float rate)
{
	emissionRate = rate;
}

float ParticleSystem::getEmissionRate(void)
{
	return emissionRate;
}

void ParticleSystem::setPosition(Vector pos)
{
	m_position = pos;
}

Vector ParticleSystem::getPosition(void)
{
	return m_position;
}
