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

// Other includes
#include "MainGame.h"
#include <iostream>
#include <ctime>
#include <cmath>

class Turret
{
	public:
		void TurretHit(GLint turretNumber);
		GLint PollTurretHealth(GLint turretNumber);
};