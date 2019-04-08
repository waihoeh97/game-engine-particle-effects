#ifndef  APPLICATION_H
#define APPLICATION_H

#include "Sprite.h"
#include "GameObject.h"
#include "ParticleSystem.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

class Application
{
private:
	Sprite* m_dummySprite;
	Sprite* m_dummySprite2;

	GameObject* gameObject;
	GameObject* gameObject2;

	ParticleSystem* particleSystem;
public:
	Application();
	~Application();

	void Start();
	void Update(float deltatime);
	void Draw();

};
#endif // ! APPLICATION_H
#pragma once
