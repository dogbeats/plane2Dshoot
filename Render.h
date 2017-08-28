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
#include "Shader.h"
#include "Text.h"
#include "MainGame.h"
#include "Collision.h"
#include "Turret.h"


#include <iostream>
#include <ctime>
#include <cmath>
#include <string>


extern GLfloat fov;
extern GLfloat cameraSpeed;
extern GLfloat rotatePlaneAngle;
extern GLfloat deltaTime;
extern bool shootProjectile[1024];
extern bool drawProjectile[1024];
extern GLint localProjectileNumber;

extern GLfloat globalDeltaTime;
extern bool hasCollided[1024];


extern GLint hasInitLocation;


class Render
{
	public: 
		Render();
		~Render();
		void InitialLoad();
		void Window(GLFWwindow* window, Shader ourShader);
		Shader CompileShader();
		void CallTexture(GLint textureNumber, char* fileName);
		void DrawObj(Shader ourShader, GLFWwindow* window);
		void DrawProjectile(GLint test_int, glm::mat4 model, Shader ourShader, GLint modelLoc, GLint tempVC, glm::mat4 planePosModel);// GLFWwindow* window, GLfloat rotationAngle, GLfloat deltaTime, glm::vec3 position, GLfloat projectileVertices[]);
		void draw(GLuint texture, float posX, float posY, float sizeX, float sizeY);
		void calculateGlobalDelta();
		void Render::ShootLaser(GLint turretNumber, GLfloat laserSize);

		void Render::TempCollisionFunction(GLint projectileNumber);
		

	private:
		void Render::DrawCollisionTemp(Shader ourShader, GLint modelLoc, glm::vec3 position, GLint number);
		glm::vec3 Render::ObjectShake(GLint objectNumber);

};
