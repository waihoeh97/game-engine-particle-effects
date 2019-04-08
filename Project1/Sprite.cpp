#include "Sprite.h"
#include"bitmap.h"

#include<GLFW\glfw3.h>

#define TEXTURE_COUNT 2

GLuint mTextureID[TEXTURE_COUNT];

void loadTexture(const char* path, GLuint TextureID)
{

}

Sprite::Sprite()
{
	//m_width = 100;
	//m_height = 100;
	//m_textureID = 0;
}

Sprite::Sprite(const std::string& file)
{
	glGenTextures(1, &m_textureID);

	CBitmap bitmap(file.c_str());
	loadTexture(file.c_str(), m_textureID);

	//create lineear filtered Texture
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//nearest (minecraft) filtering
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//bilinear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.GetWidth(), bitmap.GetHeight(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.GetBits());

	m_width = bitmap.GetWidth();
	m_height = bitmap.GetHeight();
}

Sprite::~Sprite()
{
	
}

void Sprite::draw(float x, float y, float rotate, float scale)
{
	/*
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glBegin(GL_TRIANGLES);

	glTexCoord2f(1, 0); glVertex3f((x * 100 / WINDOW_WIDTH) + (0.1f), -y * 100 / WINDOW_HEIGHT + (0.1f), 0);
	glTexCoord2f(0, 0); glVertex3f((-x * 100 / WINDOW_WIDTH) + (0.1f), -y * 100 / WINDOW_HEIGHT + (0.1f), 0);
	glTexCoord2f(1, 1.0f); glVertex3f((x * 100 / WINDOW_WIDTH) + (0.1f), y * 100 / WINDOW_HEIGHT + (0.1f), 0);


	glTexCoord2f(1, 1); 	glVertex3f((x * 100 / WINDOW_WIDTH) + (0.1f), y * 100 / WINDOW_HEIGHT + (0.1f), 0);
	glTexCoord2f(0, 1.0f); glVertex3f((-x * 100 / WINDOW_WIDTH) + (0.1f), y * 100 / WINDOW_HEIGHT + (0.1f), 0);
	glTexCoord2f(0, 0); glVertex3f((-x * 100 / WINDOW_WIDTH) + (0.1f), -y * 100 / WINDOW_HEIGHT + (0.1f), 0);
	glEnd();
	*/

	Matrix translation = Matrix::makeTranslationMatrix(x, y, 0);
	Matrix rotation = Matrix::makeRotateMatrix(rotate, Vector(0.0f, 0.0f, 1.0f));
	glLoadMatrixf((GLfloat*)(translation*rotation).mVal);

	float halfW = m_width*0.5f*scale;
	float halfH = m_height*0.5f*scale;

	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	//draw a rectangle based on the width, height and position
	glBegin(GL_TRIANGLES);
	glTexCoord2f(1, 0); glVertex3f(halfW, - halfH, 0);
	glTexCoord2f(0, 0); glVertex3f(- halfW,- halfH, 0);
	glTexCoord2f(1, 1); glVertex3f(halfW, halfH, 0);

	glTexCoord2f(1, 1); glVertex3f(halfW, halfH, 0);
	glTexCoord2f(0, 1); glVertex3f(- halfW, halfH, 0);
	glTexCoord2f(0, 0); glVertex3f(- halfW,- halfH, 0);
	glEnd();
}


