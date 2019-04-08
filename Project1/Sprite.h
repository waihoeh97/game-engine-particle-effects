#pragma once
#ifndef  SPRITE_H
#define SPRITE_H

#include <string>
#include "matrix.h"

class Sprite
{
private:
	unsigned int m_textureID;

public:
	unsigned int m_width;
	unsigned int m_height;
	Sprite();
	Sprite(const std::string& file);

	~Sprite();
	//void init();
	//void DrawRec(float x, float y,float moveX,float moveY,int textureID);
	
	void draw(float x, float y, float rotate, float scale);
};
#endif // ! SPRITE_H
