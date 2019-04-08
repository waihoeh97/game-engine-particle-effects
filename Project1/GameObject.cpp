#include "GameObject.h"
#include <GLFW\glfw3.h>
#include "Windows.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

GameObject::GameObject()
{

}

GameObject::GameObject(Sprite * sprite)
{
	m_sprite = sprite;
	m_rotation = 0;
	m_scale = 1.0f;
}

void GameObject::SetPos(Vector pos)
{
	m_position = pos;
}

const Vector & GameObject::GetPos()
{
	// TODO: insert return statement here
	return m_position;
}

void GameObject::SetRotation(float rotate)
{
	m_rotation = rotate;
}

float GameObject::GetRotation()
{
	//return 0.0f;
	return m_rotation;
}

void GameObject::SetScale(float scale)
{
	m_scale = scale;
}

float GameObject::GetScale()
{
	//return 0.0f;
	return m_scale;
}

void GameObject::SetVelocity(Vector v)
{
	m_velocity = v;
}

const Vector & GameObject::GetVelocity()
{
	return m_velocity;
}

void GameObject::SetSprite(Sprite* sprite)
{
	m_sprite = sprite;
}

Sprite * GameObject::GetSprite()
{
	return m_sprite;
}

void GameObject::SetColor(const Color & color)
{
	this->m_color = color;
}

const Color & GameObject::GetColor()
{
	// TODO: insert return statement here
	glColor4f(m_color.r, m_color.g, m_color.b, m_color.a);
	return this->m_color;
}

void GameObject::setBlendingMode(enumBlend blend)
{
	glEnable(GL_BLEND);
	if (blend == ALPHA_BLEND)
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//alpha blend normal
	}
	else if (blend == ADD_BLEND)
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	}
	else if (blend == MULTI_BLEND)
	{
		glBlendFunc(GL_DST_COLOR, GL_ZERO);
	}
}

enumBlend GameObject::getBlendingMode()
{
	return enumBlend();
}

void GameObject::draw()
{
	m_sprite->draw(m_position.mVal[0], m_position.mVal[1], GetRotation(), GetScale());
}

void GameObject::update()
{
	//m_position += m_velocity;
}

void GameObject::update2()
{
	m_position -= m_velocity;
}


