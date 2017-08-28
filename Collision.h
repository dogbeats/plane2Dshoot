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

extern bool hasCollided[1024];

class Collision
{
public:
	Collision();
	~Collision();
	glm::mat3 DetectCollision(glm::vec3 objectVertTopRight, glm::vec3 objectVertTopLeft, glm::vec3 objectVertBottomLeft, glm::vec3 objectVertBottomRight, GLfloat rotateObjectAngle, glm::vec3 planePosition, glm::vec3 tempPosition, GLfloat rotatePlaneAngle, glm::vec3 projectilePosition, GLint projectileNumber, GLfloat projectileAngle, glm::vec3 objectPosition);
	glm::mat3 TempCollisionFunction2(GLint projectileNumber, GLfloat objectVertices[], glm::vec3 projectilePos[1024], glm::vec3 cubePosition, GLint objectNumber, glm::vec3 objectPositions[1], GLfloat initRotationAngle);


private:
	GLfloat Collision::ProjectileRotation(GLfloat projectileRotationAngle, GLfloat objectRotationAngle, GLfloat gradient1, GLfloat gradient2);
};
