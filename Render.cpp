#include "Render.h"
#include "Sound.h"

GLfloat vertices[] = { //FOR PLAYER PLANE
	// Positions          // Colors				// Texture Coords
	-0.02f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left
	0.02f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom Right
	0.02f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	0.02f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.02f, 0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-0.02f, -0.1f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-0.2f, -0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 0.875f, 0.5f, // Top Right //Bottom Left
	0.2f, -0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, // Bottom Right
	0.2f, 0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom Left //top right
	0.2f, 0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom Left // top right
	-0.2f, 0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 0.875f, 1.0f,  // Top Left 
	-0.2f, -0.75f, 0.10f, 1.0f, 1.0f, 1.0f, 1.0f, 0.875f, 0.5f, // Top Right //Bottom Left

	/*-1.0f, -1.0f, -0.5f, 1.0f, 0.0f, 0.0f, 0.875f, 1.0f, // Top Right //Bottom Left
	1.0f, -1.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.875f, 0.5f, // Bottom Right
	1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.5f, // Bottom Left
	1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.5f, // Bottom Left
	-1.0f, 1.0f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f,  // Top Left 
	-1.0f, -1.0f, -0.5f, 1.0f, 0.0f, 0.0f, 0.875f, 1.0f, // Top Right //Bottom Left*/

	//WING LEFT (12)
	// Positions          // Colors				// Texture Coords
	-0.25f, -0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.125f, 1.0f, // Top Right //Bottom Left
	0.25f, -0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.125f, 0.75f, // Bottom Right
	0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.75f, // Bottom Left //Top Right
	0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.75f, // Bottom Left //Top Right
	-0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-0.25f, -0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.125f, 1.0f, // Top Right //Bottom Left //143

	// Positions          // Colors				// Texture Coords
	-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top Right //Bottom Left
	0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom Right
	0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom Left //Top Right
	0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom Left //Top Right
	-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Top Right //Bottom Left

	//WING RIGHT (24)
	// Positions          // Colors				// Texture Coords
	-0.25f, -0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.125f, 0.75f, // Top Right //Bottom Left
	0.25f, -0.225f, 0.1f, 01.0f, 1.0f, 1.0f, 1.0f, 0.125f, 0.5f, // Bottom Right
	0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left //Top Right
	0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left //Top Right
	-0.25f, 0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.75f,  // Top Left 
	-0.25f, -0.225f, 0.1f, 1.0f, 1.0f, 1.0f, 1.0f, 0.125f, 0.75f, // Top Right //Bottom Left //143

	// Positions          // Colors				// Texture Coords // laser
	-0.15f, -112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 8.0f, 1.0f, // Top Right //Bottom Left
	0.15f, -112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 8.0f, 0.0f, // Bottom Right
	0.15f, 112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	0.15f, 112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.15f, 112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-0.15f, -112.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 8.0f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords // background
	-100.0f, -100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 50.0f, 50.0f, // Top Right //Bottom Left
	100.0f, -100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 50.0f, 0.0f, // Bottom Right
	100.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	100.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-100.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 50.0f,  // Top Left 
	-100.0f, -100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 50.0f, 50.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords // laser shoot
	-0.15f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left
	0.15f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom Right
	0.15f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	0.15f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.15f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-0.15f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f // Top Right //Bottom Left (minus 0.5)


};

glm::vec3 tempColourToDelete[] = { glm::vec3(1.0f, 0.0f, 0.5f), glm::vec3(1.0f, 1.0f, 0.5f) };

GLfloat tempColourToDelete2[] = { 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.5f };

//TO IMPLEMENT TWO BELOW
GLfloat objectVertices[] = {
	// Positions          // Colors				// Texture Coords
	-1.5f, -1.25f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left
	1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.5f, 0.5f, // Bottom Right
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	1.5f, 1.25f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	-1.5f, 1.25f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left
	1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, // Bottom Right
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	-1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left
	1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, // Bottom Right
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	-1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left
	1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, // Bottom Right
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	-1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // Top Right //Bottom Left
	1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, // Bottom Right
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, // Bottom Left
	-1.5f, 1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,  // Top Left 
	-1.5f, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f // Top Right //Bottom Left (minus 0.5)
};

GLfloat projectileVertices[] = {
	// Positions          // Colors				// Texture Coords
	-0.500f, -0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left
	0.505f, -0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom Right
	0.505f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	0.505f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.500f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // Top Left 
	-0.500f, -0.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left (minus 0.5)

	// Positions          // Colors				// Texture Coords
	-0.500f, -100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top Right //Bottom Left
	0.505f, -100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom Right
	0.505f, 100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	0.505f, 100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-0.500f, 100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // Top Left 
	-0.500f, -100.25f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f // Top Right //Bottom Left (minus 0.5)
};

GLuint WIDTH = 800, HEIGHT = 600;
glm::vec3 cubePositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f), 
	glm::vec3(0.0f, 0.0f, 0.0f), //wings
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(-1.5f, -2.2f, 0.0f),
	glm::vec3(-3.8f, -2.0f, 0.0f),
	glm::vec3(2.4f, -0.4f, 0.0f),
	glm::vec3(0.0f, -5.4f, 0.0f),
	glm::vec3(0.0f, -5.0f, 0.0f), 
	glm::vec3(0.0f, -5.0f, 0.0f), // (temp thing for the x, y of the calculation thing)
	glm::vec3(0.0f, 0.0f, -0.01f), //background
	glm::vec3(-1.3f, 1.0f, 0.0f)
};

glm::vec3 objectPositions[] = {
	glm::vec3(-115.0f, 0.0f, 0.0f),
	glm::vec3(-0.0f, -5.4f, 0.0f),
	glm::vec3(115.0f, -4.4f, 0.0f),
	glm::vec3(115.0f, 1.0f, 0.0f),
	glm::vec3(-6.0f, -5.5f, 0.0f)
};

glm::vec3 projectilePositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f)
};

glm::vec3 explosionPositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(0.0f, 0.0f, 0.0f)
};

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void do_movement();
void move_object();
// Camera
glm::vec3 cameraPos = glm::vec3(0.3f, 0.2f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec4 cameraUp4 = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
GLfloat yaw = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
GLfloat pitch = 0.0f;
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
GLfloat fov = 11.0f;
//bool keys[1024];
// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame
GLfloat rotatePlaneAngle = 3.142f;
GLfloat delayTime = 0.0f;

//probs delete this and replace with something better
bool hasRecoiled[1024];

time_t timet;

//before draw projectile
bool shootProjectile[1024];
bool drawProjectile[1024];
bool initialClick[1024];
glm::vec3 projectilePos[1024];
//projectilePos[0] = cubePositions[1];
//projectilePos[1] = cubePositions[1];
GLfloat initRotationAngle[1024];
GLfloat cumulative[1024];
GLint localProjectileNumber = 1;
glm::mat4 projectileModel[1024];
GLfloat spray[1024];

//////TEMPORARY FOR LINE CALCULATION
glm::mat4 initialPlaneLocation;
glm::vec3 projectileLine[1024];
GLint hasInitLocation = 0;
GLfloat calcDeltaTime;

GLfloat sparkTime;

bool shootLaser = false;
GLfloat laserScaler[10];
GLfloat laserTimer = 0.0f;

Turret turret;

bool tempBoolIsHeightAndWidthDone = false;
GLuint objectNumber = 0;
//GLfloat objectHeight, objectWidth;


GLfloat objectCollisionCounter[10];
GLfloat objectFaceCounter[10];

GLfloat rotateSparkAngle[10];


GLfloat pollTurretHealthTime = 0.0f;
GLint turretState[10]; //(10 full, 0 dead);

//to delete probs
Text text;
GLfloat rotateObjectAngle[10];

Collision collision;

GLfloat turretToRotateTo[10];
GLfloat turretSpeed[10];
bool isCollisionTrue[10];
bool initialTurretRotateTo[10];

GLfloat explosionTime[10];
GLint explosionTarget = -1;
GLfloat updateExplosionTime = 0.0f;

/////////TURRET PROJECTILE
glm::vec3 turretProjectilePosition[1024];
GLint turretProjectileOrigin[1024];
GLfloat tempRepositionTime[10];
GLfloat turretProjectLinePosition[1024];
bool turretProjectileShoot[1024];
GLfloat turretLockOnTime[10];
GLfloat turretTotalShootTime[10];

Render::Render()
{

}

Render::~Render()
{
}

int loadedInitial = false;
void Render::InitialLoad()
{
	for (int i = 0; i < 10; i++)
	{
		turretState[i] = 10;
		objectCollisionCounter[i] = 30.0f;
		//pollTurretHealthTime[i] = 0.0f;
		rotateObjectAngle[i] = 0.0f;
		turretToRotateTo[i] = 0.0f;
		turretSpeed[i] = 0.0f;
		isCollisionTrue[i] = false;
		objectFaceCounter[i] = 0.0f;
		initialTurretRotateTo[i] = false;
		rotateSparkAngle[i] = 0.0f;
		explosionTime[i] = 0.0f;
		tempRepositionTime[i] = 0.0f;
		turretLockOnTime[i] = 0.0f;
		laserScaler[i] = 0.5f;
		turretTotalShootTime[i] = 0.0f;
	}

	for (int i = 0; i < 5; i++)
		rotateObjectAngle[i] = 4.7f * (i + 1);

	updateExplosionTime = 1.0f;
}

GLfloat soundDeltaTime = 0.0f;

void Render::calculateGlobalDelta()
{
	globalDeltaTime += deltaTime;
	soundDeltaTime += deltaTime;
	if (soundDeltaTime >= 2.0f)
	{
		Sound sound;
		sound.DropSound();
		soundDeltaTime = 0.0f;
	}
}

GLfloat currentFrame = glfwGetTime();
bool pauseGameS = false;
void Render::Window(GLFWwindow* window, Shader ourShader)
{

	currentFrame = glfwGetTime();
	// Calculate deltatime of current frame
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	// Swap the screen buffers
	delayTime += currentFrame;

	DrawObj(ourShader, window);
	move_object();

	//time(&timet);
	//std::cout << currentFrame << "\n" << deltaTime << "\n";
	glfwSwapBuffers(window);
}

Shader Render::CompileShader()
{
	// Build and compile our shader program
	Shader shader("Shaders/shader.vs", "Shaders/shader.frag");
	shader.Use();
	// Camera/View transformation
	glm::mat4 view;
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	//glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	return shader;
}

GLuint VAO, VBO, EBO;
GLuint VAO_obj, VBO_obj, EBO_obj;

GLuint texture[10];
GLuint texture2;
const char* file;
int textureNumber[] = { 0, 1 };

GLfloat cameraSpeed = 0.001f;

bool isInitialThing = false;

bool hasCollided[1024];

Render render;

GLfloat objectWidthTemp, objectHeightTemp;


/*GLfloat objectVertices[] = {
	// Positions          // Colors				// Texture Coords
	-1.500f, -1.25f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right //Bottom Left
	1.505f, -1.25f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
	1.505f, 1.25f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	1.505f, 1.25f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
	-1.500f, 1.25f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // Top Left 
	-1.500f, -1.25f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right //Bottom Left (minus 0.5)
};*/


//GLfloat laserCounter = 0.0f;

void Render::ShootLaser(GLint turretNumber, GLfloat laserSize)
{
	turretLockOnTime[turretNumber] += 1.0f * deltaTime;

	if (laserSize < 4.0f)
	{
		laserScaler[turretNumber] = laserSize;
	}
	else if (laserSize >= 4.0f && turretTotalShootTime[turretNumber] >= 0.5f)
	{
		turretProjectileShoot[turretNumber] = true;
		laserScaler[turretNumber] = laserSize;
	}

	turretTotalShootTime[turretNumber] += deltaTime;
	
}

void Render::TempCollisionFunction(GLint projectileNumber)
{
	//projectilePositions[projectileNumber][0] = -10000.0f;
	//NOT CALLING FUNCTION QUICKLY
	
	if (!tempBoolIsHeightAndWidthDone)
	{
		//objectWidth = objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber]; //10.75
		objectWidthTemp = (objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber])/2;
		//objectHeight = objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber]; // 0.62
		objectHeightTemp = (objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber])/2;
		tempBoolIsHeightAndWidthDone = true;
	}

	if ((shootProjectile[projectileNumber]) && (projectilePos[projectileNumber][0] < (objectPositions[0][0] + objectWidthTemp + 0.1f)) && (projectilePos[projectileNumber][0] > (objectPositions[0][0] - objectWidthTemp - 0.1f))
		&& (projectilePos[projectileNumber][1] < (objectPositions[0][1] + objectHeightTemp + 0.1f)) && (projectilePos[projectileNumber][1] > (objectPositions[0][1] - objectHeightTemp - 0.1f)) && !hasCollided[projectileNumber])
	{

		GLfloat x1, x2, y1, y2, temp, m1, m2, c1, c2;

		x2 = projectilePos[projectileNumber][0];

		y2 = projectilePos[projectileNumber][1];


		cubePositions[6] = glm::vec3(x2, y2, 0.0f);


		sparkTime = 0.0f;

		hasCollided[projectileNumber] = true;

		std::cout << cubePositions[6][0] << "\n";
	}
}

void Render::CallTexture(GLint textureNumber, char* fileName)
{
	glGenTextures(1, &texture[textureNumber]);

	glBindTexture(GL_TEXTURE_2D, texture[textureNumber]); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
											  // Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height;
	unsigned char* image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.	
}

void Render::DrawObj(Shader ourShader, GLFWwindow* window)
{
	cubePositions[8] = cubePositions[0];

	glBindVertexArray(VAO_obj);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_obj);
	glBufferData(GL_ARRAY_BUFFER, sizeof(objectVertices), objectVertices, GL_STATIC_DRAW);
	// Color attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO


	if (!loadedInitial)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		// Color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		// TexCoord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);		
		glBindVertexArray(0); // Unbind VAO


		glGenVertexArrays(1, &VAO_obj);
		glGenBuffers(1, &VBO_obj);
		glBindVertexArray(VAO_obj);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_obj);
		glBufferData(GL_ARRAY_BUFFER, sizeof(objectVertices), objectVertices, GL_STATIC_DRAW);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		// Color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		// TexCoord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(7 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		glBindVertexArray(0); // Unbind VAO

		CallTexture(0, "body_main.png");
		CallTexture(1, "wing_main.png");
		CallTexture(2, "explosion1.png");
		CallTexture(3, "projectile_bullet_temp4.png");
		CallTexture(4, "object_temp2.png");
		CallTexture(5, "laser2.png");
		CallTexture(7, "background1-high.png");
		CallTexture(8, "laser-projectile.png");

		loadedInitial = true;
	}
	
	

	if (globalDeltaTime >= 0.0001f)
	{
		for (int i = 0; i < 5; i++)
		{
			if (objectFaceCounter[i] >= 0.0f && turretState[i] != 0)
			{
				GLfloat distA, distB, distC, distAngle;

				glm::vec3 tempPos;
				tempPos[0] = objectPositions[i][0];
				tempPos[1] = objectPositions[i][1] + 0.01f;

				distA = sqrt(pow((objectPositions[i][0] - tempPos[0]), 2.0f) + pow((objectPositions[i][1] - tempPos[1]), 2.0f));
				distB = sqrt(pow((cubePositions[0][0] - tempPos[0]), 2.0f) + pow((cubePositions[0][1] - tempPos[1]), 2.0f));
				distC = sqrt(pow((objectPositions[i][0] - cubePositions[0][0]), 2.0f) + pow((objectPositions[i][1] - cubePositions[0][1]), 2.0f));

				distAngle = (pow(distA, 2.0f) + pow(distC, 2.0f) - pow(distB, 2.0f)) / (2 * distA*distC);
				distAngle = acos(distAngle);

				if (rotateObjectAngle[i] < 0.0f)
				{
					rotateObjectAngle[i] += 6.28f;
				}
				else if (rotateObjectAngle[i] > 6.28f)
				{
					rotateObjectAngle[i] -= 6.28f;
				}


				if (cubePositions[0][0] > objectPositions[i][0])
				{
					turretToRotateTo[i] = distAngle;
				}
				else if (cubePositions[0][0] < objectPositions[i][0])
				{
					turretToRotateTo[i] = distAngle;
				}


				if (cubePositions[0][0] < objectPositions[i][0] && cubePositions[0][1] >= objectPositions[i][1]) //bottom right
				{

				}
				else if (cubePositions[0][0] >= objectPositions[0][0] && cubePositions[0][1] > objectPositions[0][1]) //bottom left 
				{

				}
				else if (cubePositions[0][0] > objectPositions[0][0] && cubePositions[0][1] <= objectPositions[0][1]) //top left
				{

				}
				else if (cubePositions[0][0] <= objectPositions[0][0] && cubePositions[0][1] < objectPositions[0][1]) //top right
				{

				}
				else if (cubePositions[0][0] == objectPositions[i][0])
				{
					rotateObjectAngle[i] = 1.0f;
				}
				else
				{
				}

				if (cubePositions[0][0] > objectPositions[i][0])
				{
					turretToRotateTo[i] = 6.28 - turretToRotateTo[i];//3.14 + (3.14 - turretToRotateTo[i]);
				}
				

				GLfloat angleDist = turretToRotateTo[i] - rotateObjectAngle[i];


				if (initialTurretRotateTo)
				{
					if (cubePositions[0][0] < objectPositions[i][0] + 15.0f && cubePositions[0][0] > objectPositions[i][0] - 15.0f && cubePositions[0][1] < objectPositions[i][1] + 15.0f && cubePositions[0][1] > objectPositions[i][1] - 15.0f)
					{

						if (rotateObjectAngle[i] > turretToRotateTo[i] - 0.05f &&  rotateObjectAngle[i] < turretToRotateTo[i] + 0.05f)
						{
							rotateObjectAngle[i] = turretToRotateTo[i];
							turretLockOnTime[i] += 1.0f * deltaTime;
						}
						else if (rotateObjectAngle[i] > 3.14 && turretToRotateTo[i] < 3.14)
						{
							rotateObjectAngle[i] += 0.3f * deltaTime;
							turretLockOnTime[i] = 0.0f;
						}
						else
						{
							rotateObjectAngle[i] -= 0.3f * deltaTime;
							turretLockOnTime[i] = 0.0f;
						}
					}
				}

				if (!initialTurretRotateTo[i])
				{
					rotateObjectAngle[i] = turretToRotateTo[i];
					initialTurretRotateTo[i] = true;
				}
			}

			objectFaceCounter[i] += deltaTime;
			if (objectFaceCounter[i] >= 1.0f)
			{
				objectFaceCounter[i] = 0.0f;
			}
		}

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// Camera/View transformation
		glm::mat4 view;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		glm::mat4 projection;
		projection = glm::perspective(11.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		//text.drawText("abbbababaaa abg", ourShader, cameraUp, cameraSpeed, deltaTime, fov, cubePositions[0]);

		view;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection;
		projection = glm::perspective(fov, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		
		// Get their uniform location
		 modelLoc = glGetUniformLocation(ourShader.Program, "model");
		viewLoc = glGetUniformLocation(ourShader.Program, "view");
		projLoc = glGetUniformLocation(ourShader.Program, "projection");
		// Pass the matrices to the shaderco
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		//text.drawText("ababbaabhello", ourShader, cameraUp, cameraSpeed, deltaTime, fov, cubePositions[0]);


		glBindVertexArray(VAO);

		glm::mat4 model[8];
		glm::vec3 tempPos;
		
		//background
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		model[7] = glm::translate(model[7], cubePositions[9]);
		//rotateSparkAngle = rotateObjectAngle[1];
		//model[7] *= glm::mat4(cos(rotateSparkAngle), sin(rotateSparkAngle), 0.0f, 0.0f, -sin(rotateSparkAngle), cos(rotateSparkAngle), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		//std::cout << std::to_string(objectNumber) + " ";
		//model[0] = glm::rotate(model[0], rotatePlaneAngle, glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[7]));
		glDrawArrays(GL_TRIANGLES, 36, 6);

				

		//LASER PROJECTILE
		glm::mat4 laserProjectileModel[10];

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		for (int i = 0; i < 5; i++)
		{
			tempPos = objectPositions[i];
			//turretProjectileShoot[1] = true;
			if (turretProjectileShoot[i] == true)
			{
				if (turretProjectLinePosition[i] == -10000.0f)
					turretProjectLinePosition[i] = objectPositions[i][1];
				turretProjectLinePosition[i] += 15.0f * deltaTime;
				//std::cout << turretProjectLinePosition[i] << "\n";
			}
			else
			{
				turretProjectLinePosition[i] = -10000.0f;
				//std::cout << turretProjectLinePosition[i] << "\n";
			}

			if (turretProjectLinePosition[i] >= 0.0f)
				tempPos += glm::vec3(0.0f, 2.5f + turretProjectLinePosition[i], 0.0f) * glm::mat3(cos(rotateObjectAngle[i]), -sin(rotateObjectAngle[i]), 0.0f, sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 1.0f);
			else
				tempPos += glm::vec3(0.0f, -10000.0f, 0.0f) * glm::mat3(cos(rotateObjectAngle[i]), -sin(rotateObjectAngle[i]), 0.0f, sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 1.0f);

			laserProjectileModel[i] = glm::translate(laserProjectileModel[i], tempPos);


			//laserProjectileModel[i] = glm::translate(laserProjectileModel[i], (objectPositions[i] + glm::vec3(0.0f, 2.0f + turretProjectLinePosition[i], 0.0f)));
			//std::cout << std::to_string(objectNumber) + " ";
			//model[0] = glm::rotate(model[0], rotatePlaneAngle, glm::vec3(0.0f, 0.0f, 1.0f));
			if (cameraSpeed > 0.0f)
				laserProjectileModel[i] *= cameraSpeed * glm::mat4(cos(rotateObjectAngle[i]), sin(rotateObjectAngle[i]), 0.0f, 0.0f, -sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;

			laserProjectileModel[i] = glm::scale(laserProjectileModel[i], glm::vec3(laserScaler[i], 1.0f, 0.0f));
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(laserProjectileModel[i]));
			glDrawArrays(GL_TRIANGLES, 42, 6);
		}

		//LASER TEMP

		glm::mat4 laserModel[5];
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);


		for (int i = 0; i < 5; i++)
		{
			if (cubePositions[0][0] < objectPositions[i][0] + 15.0f && cubePositions[0][0] > objectPositions[i][0] - 15.0f && cubePositions[0][1] < objectPositions[i][1] + 15.0f && cubePositions[0][1] > objectPositions[i][1] - 15.0f)
			{
				tempPos = objectPositions[i];

				tempPos += glm::vec3(0.0f, 113.5f, 0.0f) * glm::mat3(cos(rotateObjectAngle[i]), -sin(rotateObjectAngle[i]), 0.0f, sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 1.0f);
				laserModel[i] = glm::translate(laserModel[i], tempPos);

				if (cameraSpeed > 0.0f)
				{
					laserModel[i] *= cameraSpeed * glm::mat4(cos(rotateObjectAngle[i]), sin(rotateObjectAngle[i]), 0.0f, 0.0f, -sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;
				}

				laserModel[i] = glm::scale(laserModel[i], glm::vec3(laserScaler[i], 1.0f, 0.0f));
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(laserModel[i]));
				if (turretState[i] != 0)
					glDrawArrays(GL_TRIANGLES, 30, 6);
			}
		}
		
		glm::mat4 explosionModel[6];

		//to move back to below
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		for (int i = 0; i < 6; i++)
		{
			explosionModel[i] = glm::translate(explosionModel[i], explosionPositions[i]);
			explosionModel[i] = glm::scale(explosionModel[i], glm::vec3(1.5f, 1.5f, 0.0f));
			explosionModel[i] *= glm::mat4(cos(rotateSparkAngle[i]), sin(rotateSparkAngle[i]), 0.0f, 0.0f, -sin(rotateSparkAngle[i]), cos(rotateSparkAngle[i]), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
			//std::cout << std::to_string(objectNumber) + " ";
			//model[0] = glm::rotate(model[0], rotatePlaneAngle, glm::vec3(0.0f, 0.0f, 1.0f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(explosionModel[i]));
			glDrawArrays(GL_TRIANGLES, 18, 6);
		}
		//////////////////// MOVE ABOVE BACK BELOW

	//Wing LEFT
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 1);

		tempPos = cubePositions[0];
		tempPos += glm::vec3(-0.45f, -0.17f, 0.0f) * glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.0f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 1.0f);

		model[1] = glm::translate(model[1], tempPos);

		if (cameraSpeed > 0.0f)
		{
			model[1] *= cameraSpeed * glm::mat4(cos(rotatePlaneAngle), sin(rotatePlaneAngle), 0.0f, 0.0f, -sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;
		}

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[1]));
		glDrawArrays(GL_TRIANGLES, 12, 6);

	//Wing RIGHT
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 1);

		tempPos = cubePositions[0];
		tempPos += glm::vec3(0.45f, -0.17f, 0.0f) * glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.0f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 1.0f);

		model[4] = glm::translate(model[4], tempPos);

		if (cameraSpeed > 0.0f)
		{
			model[4] *= cameraSpeed * glm::mat4(cos(rotatePlaneAngle), sin(rotatePlaneAngle), 0.0f, 0.0f, -sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;
		}

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[4]));
		glDrawArrays(GL_TRIANGLES, 24, 6);

		////////////////////////////////////////////////////////////////////////////////////////////////
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		model[0] = glm::translate(model[0], cubePositions[0]);

		if (cameraSpeed > 0.0f)
			model[0] *= cameraSpeed * glm::mat4(cos(rotatePlaneAngle), sin(rotatePlaneAngle), 0.0f, 0.0f, -sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[0]));
		glDrawArrays(GL_TRIANGLES, 6, 6);

		///////////////////////////////////////////////////////////////////////////////////////////////
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		model[5] = glm::translate(model[5], cubePositions[8]);

		if (cameraSpeed > 0.0f)
			model[5] *= cameraSpeed * glm::mat4(cos(rotatePlaneAngle), sin(rotatePlaneAngle), 0.0f, 0.0f, -sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model[5]));
		glDrawArrays(GL_TRIANGLES, 6, 6);

			

		for (int i = 0; i < 5; i++)
		{

			if (turretLockOnTime[i] >= 6.5f && turretTotalShootTime[i] >= 10.0f)
			{
				turretProjectLinePosition[i] = -10000.0f;
				turretProjectileShoot[i] = false;
				turretLockOnTime[i] = 0.0f;
				laserScaler[i] = 0.5f;
				turretTotalShootTime[i] = 0.0f;
			}

			if (turretLockOnTime[i] >= 6.0f && turretLockOnTime[i] < 6.5f && laserTimer <= 2.5f)
			{
				ShootLaser(i, turretLockOnTime[i] - 3.0f);
				laserTimer += deltaTime;
			}
			else if (turretLockOnTime[i] <= 2.5f)
			{
				ShootLaser(i, 0.5f);
			}
			else
			{
				if (turretLockOnTime[i] > 6.5f)
					ShootLaser(i, 4.0f);
				else
					ShootLaser(i, turretLockOnTime[i] - 2.5f);
				laserTimer = 0.0f;
			}
		}


		for (int j = 0; j < 5; j++)
		{
			if (turretState[j] == 0)
			{
				
				if (explosionTime[j] < 0.5f && (explosionTarget == -1 || explosionTarget == j) && updateExplosionTime >= 0.1f)
				{
					for (int i = 0; i <= 6; i++)
					{
						GLfloat tempRand = rand() % 100;
						if (explosionTime[j] > 0.2f && i < 2)
						{
							i = 2;
							explosionPositions[0][0] = -10000.0f;
							explosionPositions[1][0] = -10000.0f;
						}
						else if (explosionTime[j] > 0.3f && i < 4)
						{
							i = 4;
							explosionPositions[0][0] = -10000.0f;
							explosionPositions[1][0] = -10000.0f;
							explosionPositions[2][0] = -10000.0f;
							explosionPositions[3][0] = -10000.0f;
						}
						else if (explosionTime[j] > 0.4f && i < 6)
						{
							i = 5;
							explosionPositions[0][0] = -10000.0f;
							explosionPositions[1][0] = -10000.0f;
							explosionPositions[2][0] = -10000.0f;
							explosionPositions[3][0] = -10000.0f;
							explosionPositions[4][0] = -10000.0f;
						}

						if (tempRand < 50)
						{
							explosionTarget = j;
							explosionTime[j] += 0.02f;
							std::cout << explosionTime[j] << "\n";

							tempRand = rand() % 15;
							tempRand = tempRand / (rand() % 11 + 10);
							GLint isNegative = rand() % 2;
							if (isNegative % 2 == 0)
								tempRand *= -1;
							explosionPositions[i][0] = tempRand + objectPositions[j][0];

							tempRand = rand() % 15;
							tempRand = tempRand / (rand() % 11 + 10);
							isNegative = rand() % 2;
							if (isNegative % 2 == 0)
								tempRand *= -1;
							explosionPositions[i][1] = tempRand + objectPositions[j][1];
							sparkTime = 0.0f;

							rotateSparkAngle[i] = rand() % 628;
							rotateSparkAngle[i] *= 0.01;
							updateExplosionTime = 0.0f;

							Sound sound;
							sound.PlaySoundN(2, deltaTime);
						}
					}
				}
				else if (explosionTime[j] >= 0.5f && explosionTarget == j)
				{
					explosionTarget = -1;
					for (int i = 0; i < 6; i++)
						explosionPositions[i][0] = -10000.0f;
				}
				else if (explosionTarget == j || explosionTarget == -1)
					updateExplosionTime += 1.0f * deltaTime;				
			}
		}

		for (int i = 0; i <= 1023; i++)
		{
			DrawProjectile(i, model[3], ourShader, modelLoc, i, model[1]);
			//std::cout << i << "\n";
		}

		glBindVertexArray(VAO_obj);

		//FIRST OBJECT (to move back up eventually maybe)
		glm::mat4 objectModel[5];

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

		for (int i = 0; i < 5; i++)
		{
			glm::vec3 modifyPosition = ObjectShake(i);

			objectModel[i] = glm::translate(objectModel[i], modifyPosition);
			objectModel[i] *= glm::mat4(cos(rotateObjectAngle[i]), sin(rotateObjectAngle[i]), 0.0f, 0.0f, -sin(rotateObjectAngle[i]), cos(rotateObjectAngle[i]), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(objectModel[i]));
			glDrawArrays(GL_TRIANGLES, 0 + 6*i, 6);
		}

		glBindVertexArray(0);
	}	

}

bool isSprayed[1024];

GLfloat updateCollisionTime = 0;

glm::mat4 tempModel[1024];
glm::vec3 tempCollisionPositions[1024];

void Render::DrawCollisionTemp(Shader ourShader, GLint modelLoc, glm::vec3 position, GLint number)
{
	tempCollisionPositions[number] = position;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

	tempModel[number] = glm::translate(tempModel[number], tempCollisionPositions[number]);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(tempModel[number]));
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	
}

GLfloat objectShakeCounter = 0.0f;

//TO COMPLETE
glm::vec3 Render::ObjectShake(GLint objectNumber)
{
	if (turretState[objectNumber] != 0)
	{
		objectCollisionCounter[objectNumber] += 0.4f * deltaTime;
		if (objectCollisionCounter[objectNumber] <= 0.1f)
		{

			objectVertices[7 + 54 * objectNumber] = 1.0f;
			objectVertices[8 + 54 * objectNumber] = 1.0f; //55
			objectVertices[16 + 54 * objectNumber] = 1.0f;
			objectVertices[17 + 54 * objectNumber] = 0.5f;
			objectVertices[25 + 54 * objectNumber] = 0.5f;
			objectVertices[26 + 54 * objectNumber] = 0.5f;
			objectVertices[34 + 54 * objectNumber] = 0.5f;
			objectVertices[35 + 54 * objectNumber] = 0.5f;
			objectVertices[43 + 54 * objectNumber] = 0.5f;
			objectVertices[44 + 54 * objectNumber] = 1.0f;
			objectVertices[52 + 54 * objectNumber] = 1.0f;
			objectVertices[53 + 54 * objectNumber] = 1.0f;

			GLint isNegative = rand() % 2;
			GLfloat randValue = rand() % 15;
			GLfloat modifyValueX = randValue / 50;
			//std::cout << modifyValueX << " mod x \n";

			if (isNegative % 2)
				modifyValueX *= -1;

			isNegative = rand() % 2;
			randValue = rand() % 15;
			GLfloat modifyValueY = randValue / 50;

			if (isNegative % 2)
				modifyValueY *= -1;

			glm::vec3 returnValue = glm::vec3((objectPositions[objectNumber][0] + modifyValueX), (objectPositions[objectNumber][1] + modifyValueY), 0.0f);
			return returnValue;

		}
		else //if (objectCollisionCounter[objectNumber] >= 20.0f && objectCollisionCounter[objectNumber] <= 30.0f && turretState[objectNumber] != 0)
		{
			//std::cout << "false";
			isCollisionTrue[objectNumber] = false;

			objectVertices[7 + 54 * objectNumber] = 0.5f;
			objectVertices[8 + 54 * objectNumber] = 1.0f;
			objectVertices[16 + 54 * objectNumber] = 0.5f;
			objectVertices[17 + 54 * objectNumber] = 0.5f;
			objectVertices[25 + 54 * objectNumber] = 0.0f;
			objectVertices[26 + 54 * objectNumber] = 0.5f;
			objectVertices[34 + 54 * objectNumber] = 0.0f;
			objectVertices[35 + 54 * objectNumber] = 0.5f;
			objectVertices[43 + 54 * objectNumber] = 0.0f;
			objectVertices[44 + 54 * objectNumber] = 1.0f;
			objectVertices[52 + 54 * objectNumber] = 0.5f;
			objectVertices[53 + 54 * objectNumber] = 1.0f;

			return objectPositions[objectNumber];
			std::cout << "BOTTOM\n";
			objectCollisionCounter[objectNumber] = 30.0f;
		}
	}
	else
	{
		objectVertices[7 + 54 * objectNumber] = 0.5f;
		objectVertices[8 + 54 * objectNumber] = 0.5f;
		objectVertices[16 + 54 * objectNumber] = 0.5f;
		objectVertices[17 + 54 * objectNumber] = 0.0f;
		objectVertices[25 + 54 * objectNumber] = 0.0f;
		objectVertices[26 + 54 * objectNumber] = 0.0f;
		objectVertices[34 + 54 * objectNumber] = 0.0f;
		objectVertices[35 + 54 * objectNumber] = 0.0f;
		objectVertices[43 + 54 * objectNumber] = 0.0f;
		objectVertices[44 + 54 * objectNumber] = 0.5f;
		objectVertices[52 + 54 * objectNumber] = 0.5f;
		objectVertices[53 + 54 * objectNumber] = 0.5f;
		return objectPositions[objectNumber];
	}

	/*
	//std::cout << "HELLOT";
	objectShakeCounter += deltaTime;
	if (objectShakeCounter <= 2.0f)
	{
		GLfloat tempRand = (rand() % 1000) / 999;
		GLint ifIsNegative = rand() % 2;
		if (ifIsNegative % 2 == 0)
			tempRand *= -1;
		std::cout << tempRand << "\n";
		objectPositions[0][0] += tempRand;
		objectPositions[0][1] += tempRand;
		//std::cout << "HELLOE";
		//ObjectShake();
	}*/
}


void Render::DrawProjectile(GLint test_int, glm::mat4 model, Shader ourShader, GLint modelLoc, GLint tempVC, glm::mat4 planePosModel)//GLFWwindow* window, GLfloat rotationAngle, GLfloat deltaTime, glm::vec3 position, GLfloat projectileVertices[])
{
	if (pollTurretHealthTime > 5.0f)
	{
		for (int i = 0; i < 5; i++)
		{
			GLfloat turretHealth = turret.PollTurretHealth(i);
			if (100 - turretHealth == 0)
			{
				turretState[i] = 0;
			}
			//std::cout << "turret health[" << i << "]: " << turretHealth << "\n";
		}
		pollTurretHealthTime = 0.0f;
	}
	else
	{
		pollTurretHealthTime += 0.01f * deltaTime;
	}

	projectileModel[tempVC] = model;

	if (updateCollisionTime >= 0.2f)
	{
		for (int i = 0; i <= 1023; i++)
		{

			if (!initialClick[i])
				projectilePos[i] = cubePositions[1];

			if (shootProjectile[i])
			{
				for (int j = 0; j < 5; j++)
				{
					if (projectilePos[i][0] > objectPositions[j][0] - 1.7f && projectilePos[i][0] < objectPositions[j][0] + 1.7f && projectilePos[i][1] > objectPositions[j][1] - 1.35f && projectilePos[i][1] < objectPositions[j][1] + 1.35f)
					{

						glm::mat3 temporaryMatrix = collision.DetectCollision(glm::vec3(objectVertices[0], objectVertices[1], objectVertices[2]), glm::vec3(objectVertices[8], objectVertices[9], objectVertices[10]), glm::vec3(objectVertices[16], objectVertices[17], objectVertices[18]), glm::vec3(objectVertices[32], objectVertices[33], objectVertices[34]), rotateObjectAngle[j], glm::vec3(cubePositions[0][0], cubePositions[0][1], cubePositions[0][2]), glm::vec3(cubePositions[8][0], cubePositions[8][1], cubePositions[8][2]), rotatePlaneAngle, projectilePos[i], tempVC, initRotationAngle[i], glm::vec3(objectPositions[j][0], objectPositions[j][1], objectPositions[j][2]));
						if (temporaryMatrix[2][2] == 0 && !isCollisionTrue[j])
						{
							objectCollisionCounter[j] = 0.0f;
							cubePositions[6][0] = temporaryMatrix[1][0];
							cubePositions[6][1] = temporaryMatrix[1][1];
							cubePositions[8][0] = temporaryMatrix[0][0];
							cubePositions[8][1] = temporaryMatrix[0][1];
							//objectShakeCounter = 0.0f;
							//ObjectShake();//TO COMPLETE
							//std::cout << objectShakeCounter;
							std::cout << "Hit\n";
							drawProjectile[i] = false;
							projectilePos[i][0] = -10000.0f;
							isCollisionTrue[j] = true;
							turret.TurretHit(j);
						}
					}
				}
			}
		}

		updateCollisionTime = 0;
	}

	if (objectCollisionCounter[1] < 21.0f)
	{		
		//std::cout << objectCollisionCounter << "\n";
		//ObjectShake(1);
	}


	updateCollisionTime += deltaTime;

		if (shootProjectile[tempVC])
		{
			//std::cout << "shoot proj: " << shootProjectile[tempVC] << " tempvc: " << tempVC << "\n";
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture[3]);
			glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
			//TempCollisionFunction(localProjectileNumber);
			if (!initialClick[tempVC])
			{				
				isSprayed[tempVC] = false;
				initRotationAngle[tempVC] = rotatePlaneAngle;

				if (tempVC % 2 == 0)
					projectilePos[tempVC] += glm::vec3(0.5f, 0.0f, 0.0f) * glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.0f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 1.0f);
				else
					projectilePos[tempVC] += glm::vec3(-0.5f, 0.0f, 0.0f) * glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.0f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 1.0f);

				initialClick[tempVC] = true;
				cumulative[tempVC] = 0.0f;
				projectileModel[tempVC] = model;
				GLfloat temporaryRandom = (rand() % 10);
				GLfloat temporaryRandom2 = (rand() % 2);
				if (temporaryRandom2 == 0)
					spray[tempVC] = temporaryRandom / 150;
				else if (temporaryRandom2 == 1)
					spray[tempVC] = -temporaryRandom / 150;
			}
			else if (initialClick[tempVC])// && projectilePos[tempVC] != cubePositions[1])
			{
				if (!isSprayed[tempVC])
				{
					//initRotationAngle[tempVC] += 10; 
					//initRotationAngle[tempVC] += 0.01;
					initRotationAngle[tempVC] += spray[tempVC];

					isSprayed[tempVC] = true;
				}
				else if (isSprayed[tempVC])
				{

				}			
				
				projectilePos[tempVC] += 10.0f * cameraUp *glm::mat3(cos(initRotationAngle[tempVC]), -sin(initRotationAngle[tempVC]), 0.3f, sin(initRotationAngle[tempVC]), cos(initRotationAngle[tempVC]), -0.25f, 0, 0, 1) * deltaTime;//* glm::mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f) 
				
				projectileModel[tempVC] = glm::translate(projectileModel[tempVC], projectilePos[tempVC]);

				projectileModel[tempVC] *= cameraSpeed * glm::mat4(cos(initRotationAngle[tempVC]), sin(initRotationAngle[tempVC]), 0.0f, 0.0f, -sin(initRotationAngle[tempVC]), cos(initRotationAngle[tempVC]), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;// *glm::mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

			}

			cumulative[tempVC] += deltaTime;

			for (int i = 0; i <= 1023; i++)
			{ 				
				if (drawProjectile[i])
				{
					glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(projectileModel[i]));
					glDrawArrays(GL_TRIANGLES, 0, 6);
				}
			}

			glBindVertexArray(0);

			if (cumulative[tempVC] > 2.0f)
			{
				initialClick[tempVC] = false;
				shootProjectile[tempVC] = false;
				drawProjectile[tempVC] = false;
			}
		}

		initialPlaneLocation = planePosModel;

		calcDeltaTime += deltaTime;

		if (hasInitLocation == 0 && calcDeltaTime >= 2000.0f)
		{
			initialPlaneLocation = planePosModel;
			//std::cout << initialPlaneLocation[0][0] * 10000 << " " << initialPlaneLocation[0][1] * 10000 << " " << initialPlaneLocation[1][0] * 10000 << " " << initialPlaneLocation[1][1] * 10000 << " " << "\n";
			calcDeltaTime = 0;
		}
		else if (hasInitLocation == 1 && calcDeltaTime >= 2000)
		{
			glm::mat4 bulletLocation = projectileModel[0];
		}
		else if (hasInitLocation == 2 && calcDeltaTime >= 2000)
		{

		}
}

void Render::draw(GLuint texture, float posX, float posY, float sizeX, float sizeY) 
{
	/*glBegin(GL_QUADS); 
	glBindTexture(GL_TEXTURE_2D, texture); 
	glTexCoord2f(sizeX, sizeY); 
	glVertex3f(posX, posY, 0.0f); 
	glTexCoord2f(0.025f + sizeX, sizeY); 
	glVertex3f(posX + 16.0f, posY, 0.0f); 
	glTexCoord2f(0.025f + sizeX, 0.025f + sizeY); 
	glVertex3f(posX + 16.0f, posY + 16.0f, 0.0f); 
	glTexCoord2f(sizeX, 0.025f + sizeY); 
	glVertex3f(posX, posY + 16.0f, 0.0f); 
	glEnd();
	std::cout << "hello";*/
}

MainGame mainGameT;

void move_object()
{
	cubePositions[0] += cameraSpeed * cameraUp *glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.3f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), -0.25f, 0, 0, 1) * deltaTime;
	cubePositions[1] += cameraSpeed * cameraUp *glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.3f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), -0.25f, 0, 0, 1) * deltaTime;
	cameraPos += cameraSpeed * cameraUp * glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.3f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), -0.25f, 0, 0, 1) * deltaTime;
}