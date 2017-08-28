// Other includes
#pragma once

#include <iostream>
#include <string>

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

#include "Shader.h"
#include "KeyPress.h"


class Text
{
	public:
		Text();
		~Text();
		void drawText(std::string text, Shader, glm::vec3 cameraUp, GLfloat cameraSpeed, GLfloat deltaTime, GLfloat fov, glm::vec3 cubePos);
};