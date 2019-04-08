#include "Application.h"

Application::Application()
{

}

Application::~Application()
{

}
void Application::Start()
{
	m_dummySprite = new Sprite("../media/joker-2.bmp");
	gameObject = new GameObject(m_dummySprite);

	gameObject->SetSprite(m_dummySprite);
	gameObject->GetSprite();

	Vector p(400, 400, 0);
	gameObject->SetPos(p);
	gameObject->SetRotation(0);
	gameObject->SetVelocity(Vector(2.0f, 2.0f, 0.0f));
	gameObject->SetScale(0.5f);
	gameObject->SetColor(Color(1, 0, 0, 1));
	gameObject->setBlendingMode(ALPHA_BLEND);


	m_dummySprite2 = new Sprite("../media/deathParticle.bmp");
	particleSystem = new ParticleSystem(m_dummySprite2);
	particleSystem->setPosition(Vector(400.0f, 400.0f, 0.0f));
	particleSystem->setEmissionRate(15.0f);
}

void Application::Update(float deltatime)
{
	if (gameObject->GetPos().mVal[1] <= WINDOW_HEIGHT - ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()) && gameObject->goUp)
	{
		gameObject->SetPos(gameObject->GetPos() + gameObject-> GetVelocity());
		if (gameObject->GetPos().mVal[1] >= WINDOW_HEIGHT - ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()))
		{
			gameObject->goUp = false;
		}
	}
	else if (gameObject->GetPos().mVal[1] >= 0 + ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()) && !gameObject->goUp)
	{
		gameObject->SetPos(gameObject->GetPos() - gameObject->GetVelocity());
		if (gameObject->GetPos().mVal[1] <= 0 + ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()))
		{
			gameObject->goUp = true;
		}
	}

	if (gameObject->GetPos().mVal[0] <= WINDOW_WIDTH - ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()) && gameObject->goRight)
	{
		gameObject->SetPos(gameObject->GetPos() + gameObject->GetVelocity());
		if (gameObject->GetPos().mVal[0] >= WINDOW_WIDTH - ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()))
		{
			gameObject->goRight = false;
		}
	}
	else if (gameObject->GetPos().mVal[0] >= 0 + ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()) && !gameObject->goRight)
	{
		gameObject->SetPos(gameObject->GetPos() - gameObject->GetVelocity());
		if (gameObject->GetPos().mVal[0] <= 0 + ((gameObject->GetSprite()->m_height)*0.5f*gameObject->GetScale()+gameObject->GetRotation()))
		{
			gameObject->goRight = true;
		}
	}
	particleSystem->update(deltatime);
}

void Application::Draw()
{
	//gameObject->draw();
	particleSystem->draw();
}
