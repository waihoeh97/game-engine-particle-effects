#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/GLU.h>

#include "camera.h"
#include "matrix.h"
#include "vector.h"
#include "Application.h"
#include "Sprite.h"
#include "bitmap.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void onWindowResized(GLFWwindow* window, int width, int height)
{
	//if (height == 0) height = 1;						// Prevent A Divide By Zero By making Height Equal One

	glViewport(0, 0, width, height);					// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
//	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.f);
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}




int main(void)
{
	GLFWwindow* window;
	Application app;
	Sprite sprite;


	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Joker's Funland", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(window, onWindowResized);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);


	glfwSwapInterval(1);


	const float fpsLimit = 60.0f;
	const float targetDeltaTime = 1.0f / double(fpsLimit);

	float deltaTime = 0.0f;
	float prevTime = glfwGetTime();

	app.Start();

	//sprite.init();
	/* Loop until user closes window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			break;

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		float currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;

		if (deltaTime < targetDeltaTime)
		{
			int sleepMS = (targetDeltaTime-deltaTime)*1000.0f-1;
			if (sleepMS > 0)
				Sleep(sleepMS);
		}


		while (deltaTime<targetDeltaTime)
		{
			deltaTime = glfwGetTime() - prevTime;
		}

		float fps = 1.0f / deltaTime;
		//std::cout << "fps: " << fps << "  DeltaTime: " << deltaTime << std::endl;
		prevTime = glfwGetTime();

		app.Update(deltaTime);
		app.Draw();
		



		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
