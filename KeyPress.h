
// Other includes
#pragma once

#include <iostream>

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

#include "Sound.h"


extern bool shootProjectile[1024];
extern bool drawProjectile[1024];

extern GLfloat fov;
extern GLfloat cameraSpeed;
extern GLfloat rotatePlaneAngle;
extern GLfloat deltaTime;
extern GLint localProjectileNumber;
extern bool hasCollided[1024];

//to delete probs
extern GLint hasInitLocation;

class KeyPress
{
	public:
		void keyCallback(GLFWwindow* window);
		void space_press();
		

};