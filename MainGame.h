#pragma once

#include <iostream>
#include <cmath>
#include <ctime>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL.h>

// GLM Mathematics
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "KeyPress.h"


extern GLfloat globalDeltaTime;

class MainGame
{
public:
	MainGame();
	~MainGame();
	int run();
	GLFWwindow* window;
	void pauseGameT();

private:
	
};

