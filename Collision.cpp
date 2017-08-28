#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

//temp line calculatin for object (hitbox)
GLfloat obj_x1, obj_x2, obj_y1, obj_y2, obj_c, obj_m;
GLfloat proj_x1, proj_x2, proj_y1, proj_y2, proj_m, proj_c;
GLfloat simul_x1, simul_y1, simul_c, simul_m, temp_simul_x1, temp_simul_y1;
//glm::vec4 collisionSets[] = { glm::vec4(1, 10, 0, 9), glm::vec4(7, 10, 9, 6), glm::vec4(7, 4, 6, 3), glm::vec4(1, 4, 0, 3) };
GLint collisionSets[] = { 1, 10, 0, 9, 7, 10, 6, 9, 7, 4, 6, 3, 1, 4, 0, 3 };
GLfloat diff_x[8], diff_y[8];

GLfloat localDeltaTime;
GLfloat midPointX, midPointY, tempXD, tempYD;

bool tempBoolIsHeightAndWidthDone1;
GLfloat objectHeight, objectWidth;

/*
void Collision::TempCollisionFunction(GLint projectileNumber)
{
	//projectilePositions[projectileNumber][0] = -10000.0f;
	//NOT CALLING FUNCTION QUICKLY

	if (!tempBoolIsHeightAndWidthDone)
	{
		//objectWidth = objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber]; //10.75
		objectWidth = (objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber]) / 2;
		//objectHeight = objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber]; // 0.62
		objectHeight = (objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber]) / 2;
		tempBoolIsHeightAndWidthDone = true;
	}

	if ((shootProjectile[projectileNumber]) && (projectilePos[projectileNumber][0] < (objectPositions[0][0] + objectWidth + 0.1f)) && (projectilePos[projectileNumber][0] > (objectPositions[0][0] - objectWidth - 0.1f))
		&& (projectilePos[projectileNumber][1] < (objectPositions[0][1] + objectHeight + 0.1f)) && (projectilePos[projectileNumber][1] > (objectPositions[0][1] - objectHeight - 0.1f)) && !hasCollided[projectileNumber])
	{

		GLfloat x1, x2, y1, y2, temp, m1, m2, c1, c2;

		x2 = projectilePos[projectileNumber][0];

		y2 = projectilePos[projectileNumber][1];


		cubePositions[6] = glm::vec3(x2, y2, 0.0f);


		sparkTime = 0.0f;

		hasCollided[projectileNumber] = true;


	}
}
*/

glm::mat3 Collision::TempCollisionFunction2(GLint projectileNumber, GLfloat objectVertices[], glm::vec3 projectilePos[1024], glm::vec3 cubePosition, GLint objectNumber, glm::vec3 objectPositions[1], GLfloat initRotationAngle)
{
	//projectilePositions[projectileNumber][0] = -10000.0f;
	//NOT CALLING FUNCTION QUICKLY

	//std::cout << "CALLEd\n";

	if (!tempBoolIsHeightAndWidthDone1)
	{
		//objectWidth = objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber]; //10.75
		objectWidth = (objectVertices[8 + 64 * objectNumber] - objectVertices[0 + 64 * objectNumber]) / 2;
		//objectHeight = objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber]; // 0.62
		objectHeight = (objectVertices[17 + 64 * objectNumber] - objectVertices[1 + 64 * objectNumber]) / 2;
		tempBoolIsHeightAndWidthDone1 = true;
	}

	if ((shootProjectile[projectileNumber]) && (projectilePos[projectileNumber][0] < (objectPositions[0][0] + objectWidth + 0.1f)) && (projectilePos[projectileNumber][0] > (objectPositions[0][0] - objectWidth - 0.1f))
		&& (projectilePos[projectileNumber][1] < (objectPositions[0][1] + objectHeight + 0.1f)) && (projectilePos[projectileNumber][1] > (objectPositions[0][1] - objectHeight - 0.1f)) && !hasCollided[projectileNumber])
	{
		//if (projectilePos[projectileNumber][1] > (objectPositions[0][1] - 0.62))
		//{

		//std::cout << "Object Height: " << objectHeight << " Object Width: " << objectWidth << " \n";

		GLfloat x1, x2, y1, y2, temp, m1, m2, c1, c2, rotateSparkAngle;
		//std::cout << projectilePos[projectileNumber][0] << " " << projectilePos[projectileNumber][1] << " " << projectilePos[projectileNumber][2] << "\n";
		//std::cout << objectPositions[0][0] << " " << objectPositions[0][1] << " " << objectPositions[0][2] << "\n\n";

		//std::cout << " Rotation Angle: " << initRotationAngle[projectileNumber] << "\n";

		//x1 = cubePositions[0][0];
		x2 = projectilePos[projectileNumber][0];
		//y1 = cubePositions[0][1];
		y2 = projectilePos[projectileNumber][1];
		//y = mx + c

		/*std::cout << "x1: " << x1 << " x2: " << x2 << "\n";

		m1 = (x1 - x2);
		temp = (y1 - y2);

		if (m1 < 0)
		{
		temp *= -1;
		}
		m2 = temp / m1;*/

		//c1 = (y1 - (x1 * m2));

		//std::cout << "x1 " << x1 << " x2 " << x2 << " y1 " << y1 << " y2 " << y2 << "\n";
		//std::cout << "y = " << m2 << "x + " << c1 << "\n";
		//std::cout << "y = " << objectPositions[0][1] + 0.62 << "\n";

		//temp = ((objectPositions[0][1] + objectHeight) - c1) / m2;

		//std::cout << "Equal when y = " << objectPositions[0][1] - 0.62 << " and x = " << temp << "\n";

		//cubePositions[6] = glm::vec3(x2, y2, 0.0f);
		//std::cout << "cUBE POSITIONS " << cubePositions[6][0] << " " << cubePositions[6][1] << "\n";

		//NOTE TO DO THIS IN THE RETURNsparkTime = 0.0f;

		
		
		if ((cubePosition[0] <= objectPositions[0][0] + objectWidth + 0.1f) && (cubePosition[0] >= objectPositions[0][0] + objectWidth - 0.1f))
		{
		std::cout << "called0 \n";
		initRotationAngle = 0 - initRotationAngle;

		cubePosition = glm::vec3(x2 + 0.25f, y2, 0.0f);
//		std::cout << "cUBE POSITIONS " << cubePosition[0] << " " << cubePositions[6][1];

		rotateSparkAngle = 4.7f;
		}
		else if ((cubePosition[0] <= objectPositions[0][0] - objectWidth + 0.1f) && (cubePosition[0] >= objectPositions[0][0] - objectWidth - 0.1f))
		{
		std::cout << "called1 \n";
		initRotationAngle = 0 - initRotationAngle;

		cubePosition = glm::vec3(x2 - 0.25f, y2, 0.0f);
	//	std::cout << "cUBE POSITIONS " << cubePositions[6][0] << " " << cubePositions[6][1];

		rotateSparkAngle = 1.507f;
		}
		else if ((cubePosition[1] <= objectPositions[0][1] + objectHeight + 0.1f) && (cubePosition[1] >= objectPositions[0][1] + objectHeight - 0.1f))
		{
		std::cout << "called2 \n";
		initRotationAngle = 3.142 - initRotationAngle;

		cubePosition = glm::vec3(x2, y2 + 0.25f, 0.0f); //151-152//159-160//167-168//175-176//183-184//191-192 (BL, BR, TR, TR, TL, BL)

		std::cout << "CubePositions[6][0]: " << cubePosition[0] << "\n";
		std::cout << "CubePositions[6][1]: " << cubePosition[1] << "\n";
		std::cout << "ObjectPositions[0][0]: " << objectPositions[0][0] << "\n";
		std::cout << "ObjectPositions[0][1]: " << objectPositions[0][1] << "\n";
		std::cout << "Obj[0][0] + objwidth + 1: " << objectPositions[0][0] + objectWidth + 1.0f << "\n";
		std::cout << "Obj[0][0] - objwidth - 1: " << objectPositions[0][0] + objectWidth - 1.0f << "\n";
		std::cout << "Obj[0][1] + objheight: " << objectPositions[0][1] + objectHeight << "\n";
		std::cout << "Obj[0][1] - objheight: " << objectPositions[0][1] - objectHeight << "\n";

		rotateSparkAngle = 0.0f;
		projectilePos[projectileNumber][0] = cubePosition[0];
		projectilePos[projectileNumber][1] = cubePosition[1];
		std::cout << "//////////////RECEIVED////////////////\n";

		}
		else if ((cubePosition[1] <= objectPositions[0][1] - objectHeight + 0.1f) && (cubePosition[1] >= objectPositions[0][1] - objectHeight - 0.1f))
		{
		std::cout << "called3 \n";
		initRotationAngle = 3.142 - initRotationAngle;

		cubePosition = glm::vec3(x2, y2 - 0.25f, 0.0f);
		//std::cout << "cUBE POSITIONS " << cubePositions[6][0] << " " << cubePositions[6][1];

		rotateSparkAngle = 3.14f;
		}
		else
		{
		std::cout << "loop failure render.cpp \n";
		//std::cout << "CubePositions[6][0]: " << cubePositions[6][0] << "\n";
		//std::cout << "CubePositions[6][1]: " << cubePositions[6][1] << "\n";
		std::cout << "ObjectPositions[0][0]: " << objectPositions[0][0] << "\n";
		std::cout << "ObjectPositions[0][1]: " << objectPositions[0][1] << "\n";
		std::cout << "Obj[0][0] + objwidth + 1: " << objectPositions[0][0] + objectWidth + 1.0f << "\n";
		std::cout << "Obj[0][0] - objwidth - 1: " << objectPositions[0][0] + objectWidth - 1.0f << "\n";
		std::cout << "Obj[0][1] + objheight: " << objectPositions[0][1] + objectHeight << "\n";
		std::cout << "Obj[0][1] - objheight: " << objectPositions[0][1] - objectHeight << "\n";
		}
		
		

		hasCollided[projectileNumber] = true;
		std::cout << x2 << "\n";
		std::cout << "RESULT 1\n";
		return glm::mat3(x2, y2, 0.0f, initRotationAngle, rotateSparkAngle, 0.0f, 0.0f, 0.0f, 0.0f);
		//return glm::mat3(x2, y2, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	}
	else
	{
		//std::cout << "RESULT 2\n";
		return glm::mat3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 10.0f);
	}
}

GLfloat Collision::ProjectileRotation(GLfloat projectileRotationAngle, GLfloat objectRotationAngle, GLfloat gradient1, GLfloat gradient2)
{
	GLfloat angle;
	angle = atan((gradient1 - gradient2) / (1 + gradient1*gradient2));
	//std::cout << "angle: " << angle << "\n";
	projectileRotationAngle = 3.14 + angle;

	return projectileRotationAngle;
}

glm::mat3 Collision::DetectCollision(glm::vec3 objectVertTopRight, glm::vec3 objectVertTopLeft, glm::vec3 objectVertBottomLeft, glm::vec3 objectVertBottomRight, GLfloat rotateObjectAngle, glm::vec3 planePosition, glm::vec3 tempPosition, GLfloat rotatePlaneAngle, glm::vec3 projectilePosition, GLint projectileNumber, GLfloat projectileAngle, glm::vec3 objectPosition)
{
	GLint hasCollidedX = 1;

	//glm::vec3 topRight, topLeft, bottomRight, bottomLeft;
	GLfloat verticesPositions[12]; //top right, bottom right, bottom left, top left

	//////////////////////////OBJECT VERTICES POSITIONS
	verticesPositions[0] = (objectVertTopRight[0] * cos(rotateObjectAngle) - objectVertTopRight[1] * sin(rotateObjectAngle)) + objectPosition[0];
	verticesPositions[1] = (objectVertTopRight[1] * cos(rotateObjectAngle) + objectVertTopRight[0] * sin(rotateObjectAngle)) + objectPosition[1];
	verticesPositions[2] = 0.0f;

	verticesPositions[3] = (objectVertBottomRight[0] * cos(rotateObjectAngle) - objectVertBottomRight[1] * sin(rotateObjectAngle)) + objectPosition[0];
	verticesPositions[4] = (objectVertBottomRight[1] * cos(rotateObjectAngle) + objectVertBottomRight[0] * sin(rotateObjectAngle)) + objectPosition[1];
	verticesPositions[5] = 0.0f;

	verticesPositions[6] = (objectVertBottomLeft[0] * cos(rotateObjectAngle) - objectVertBottomLeft[1] * sin(rotateObjectAngle)) + objectPosition[0];
	verticesPositions[7] = (objectVertBottomLeft[1] * cos(rotateObjectAngle) + objectVertBottomLeft[0] * sin(rotateObjectAngle)) + objectPosition[1];
	verticesPositions[8] = 0.0f;

	verticesPositions[9] = (objectVertTopLeft[0] * cos(rotateObjectAngle) - objectVertTopLeft[1] * sin(rotateObjectAngle)) + objectPosition[0];
	verticesPositions[10] = (objectVertTopLeft[1] * cos(rotateObjectAngle) + objectVertTopLeft[0] * sin(rotateObjectAngle)) + objectPosition[1];
	verticesPositions[11] = 0.0f;


	GLfloat tempCalcPosX, tempCalcPosY;
	GLfloat diff_x1 = 0.0f, diff_y1 = 0.0f, diff_x2 = 0.0f, diff_y2 = 0.0f;

	for (int i = 0; i < 4; i++)
	{
		///NEED TO MODIFY FOR ALL SIDES
		obj_y2 = verticesPositions[collisionSets[4*i]];
		obj_y1 = verticesPositions[collisionSets[4*i + 1]];
		obj_x2 = verticesPositions[collisionSets[4*i + 2]];
		obj_x1 = verticesPositions[collisionSets[4*i + 3]];

		//std::cout << bottomLeft[0][0] << "    " << topLeft[0][0] << "\n";

		//m val
		obj_m = (obj_y1 - obj_y2) / (obj_x1 - obj_x2);
		obj_c = obj_y1 - (obj_x1 * obj_m);


		//cubePositions[8][0] = 0.0f;
		//cubePositions[8][1] = 1.0f;

		//if (shootProjectile[i])
		//{
		//tempCalcPosX = (projectilePosition[0] * cos(projectileAngle) - projectilePosition[1] * sin(projectileAngle)) + tempPosition[0];
		//tempCalcPosY = (projectilePosition[1] * cos(projectileAngle) + projectilePosition[0] * sin(projectileAngle)) + tempPosition[1];
		tempCalcPosX = objectPosition[0];
		tempCalcPosY = objectPosition[1];
			//std::cout << "pos x: " << tempCalcPosX << " " << "pos y :" << tempCalcPosY << "\n";
		//}
		//else
		//{
			//tempCalcPosX = (planePosition[0] * cos(rotatePlaneAngle) - (planePosition[1]) * sin(rotatePlaneAngle)) + tempPosition[0];
			//tempCalcPosY = ((planePosition[1]) * cos(rotatePlaneAngle) + planePosition[0] * sin(rotatePlaneAngle)) + tempPosition[1];
		//}

		//proj_y1 = projectilePos[0][1];
		proj_y1 = projectilePosition[1]; //tempcalcposy
		proj_y2 = objectPosition[1];
		//proj_x1 = projectilePos[0][0];
		proj_x1 = projectilePosition[0]; //tempcalcposx
		proj_x2 = objectPosition[0];

		proj_m = (proj_y1 - proj_y2) / (proj_x1 - proj_x2);
		proj_c = proj_y1 - (proj_x1 * proj_m);

		simul_x1 = -(proj_c - obj_c) / (proj_m - obj_m);
		simul_y1 = (((obj_m + proj_m) * simul_x1 + (obj_c + proj_c))) / 2;

		//cubePositions[6][0] = bottomLeft[0];
		//cubePositions[6][1] = bottomLeft[1];

		//std::cout << simul_x1 << " " << simul_y1 << "\n";
		//std::cout << "(proj-obj)m: " << proj_m << " " << obj_m << " (proj-obj)c: " << proj_c << " " << obj_c << "\n";
		//std::cout << "proj_y1: " << proj_y1 << " proj_x1 * obj_m: " << proj_x1 * obj_m << "\n";

		//if (rotateObjectAngle >= 0.0f && rotateObjectAngle <= 1.57f)
		//{

		GLfloat littleY, littleX;
		/*
		if (rotateObjectAngle < 1.57f)
		{
		if (obj_y2 <= obj_y1)
		{
		littleY = obj_y2;
		}
		else
		{
		littleY = obj_y1;
		}

		if (obj_x2 <= obj_x1)
		{
		littleX = obj_x2;
		}
		else
		{
		littleX = obj_x1;
		}
		}
		else if (rotateObjectAngle > 1.57f && rotateObjectAngle < 3.14f)
		{
		if (obj_y2 <= obj_y1)
		{
		littleY = obj_y2;
		}
		else
		{
		littleY = obj_y1;
		}

		if (obj_x2 <= obj_x1)
		{
		littleX = obj_x2;
		}
		else
		{
		littleX = obj_x1;
		}
		}
		else
		{
		if (obj_y2 <= obj_y1)
		{
		littleY = obj_y2;
		}
		else
		{
		littleY = obj_y1;
		}

		if (obj_x2 <= obj_x1)
		{
		littleX = obj_x2;
		}
		else
		{
		littleX = obj_x1;
		}

		*/

		//cubePositions[8][0] = tempCalcPosX;
		//cubePositions[8][1] = tempCalcPosY;

		//if (cubePositions[0][0] >= littleX && cubePositions[0][1] >= littleY)
		//{

		if (obj_x2 > obj_x1)
		{
			GLfloat sortTempVar = 0.0f;
			sortTempVar = obj_x1;
			obj_x1 = obj_x2;
			obj_x2 = sortTempVar;
		}

		
		if (simul_x1 <= obj_x1 && simul_x1 >= obj_x2)// && simul_y1 <= obj_y1 && simul_y1 >= obj_y2 )
		{

			//cubePositions[6][0] = simul_x1;
			//cubePositions[6][1] = simul_y1;
			//std::cout << "CALLED";
		}
		else
		{
			simul_x1 = 1.0f;
			simul_y1 = 1.0f;
		}
		

		
		midPointX = (obj_x1 + obj_x2) / 2;
		midPointY = (obj_y1 + obj_y2) / 2;

		
		//if (tempX < 0.0f)
		//	tempX *= -1;

	//	tempY = simul_y1 - planePosition[1];
		//if (tempY < 0.0f)
		//	tempY *= -1;

		diff_x[i] = sqrt(pow((midPointX - projectilePosition[0]), 2) + pow((midPointY - projectilePosition[1]), 2));
		//diff_y[i] = planePosition[1] - simul_y1;

		/*if (diff_x[i] <= 0.0f)
			diff_x[i] *= -1;

		if (diff_y[i] <= 0.0f)
			diff_y[i] *= -1;*/

		//if (diff_x1 <= 0.0f)
		//	diff_x1 *= -1;

		//if (diff_y1 <= 0.0f)
		//	diff_y1 *= -1;
		
		if (diff_x[i] < diff_x[i - 1] && i != 0)
		{
			temp_simul_x1 = simul_x1;
			temp_simul_y1 = simul_y1;
		}
		else if (i == 0)
		{
			temp_simul_x1 = simul_x1;
			temp_simul_y1 = simul_y1;
		}
		


		//}

		//rotateObjectAngle = 1.0f;

		//objectVertices[3] = 1.0f + rotatePlaneAngle;
		//objectVertices[4] = 1.0f + rotatePlaneAngle;
		//objectVertices[5] = 1.0f + rotatePlaneAngle;
		//topleft



		//}
		//if (rotateObjectAngle >= 1.57f && rotateObjectAngle <= 3.14f)
		//{
		//if (simul_x1 <= obj_x1 && simul_x1 <= obj_x2)// && simul_y1 <= obj_y1 && simul_y1 >= obj_y2 )
		//{
		//	cubePositions[6][0] = simul_x1;
		//	cubePositions[6][1] = simul_y1;
		//}
		//else
		//{
		//	cubePositions[6][0] = 1.0f;
		//	cubePositions[6][1] = 1.0f;
		//}
		//}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		/*
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		do_movement();
		// Set the required callback functions
		glfwSetKeyCallback(window, key_callback);
		*/

		//glfwSetCursorPosCallback(window, mouse_callback);
		//glfwSetScrollCallback(window, scroll_callback);

		/* LIGHTING EXPERIMENT
		for (int i = 0; i < 6; i++)
		{
		if ((cubePositions[1][1] <= (objectPositions[0][1] + objectVertices[1 + 8 * i]  + 5.0f)) && (cubePositions[1][1] >= (objectPositions[0][1] + objectVertices[1 + 8 * i])))
		{
		objectVertices[3 + 8 * i] = 0.5f;
		objectVertices[4 + 8 * i] = 0.5f;
		objectVertices[5 + 8 * i] = 0.5f;
		std::cout << "CALLED\n";
		}
		else if ((cubePositions[1][1] <= (objectPositions[0][1] + objectVertices[1 + 8 * i])))
		{
		objectVertices[3 + 8 * i] -= 0.05f;
		objectVertices[4 + 8 * i] -= 0.05f;
		objectVertices[5 + 8 * i] -= 0.05f;
		}
		}
		*/

		//std::cout << "CubePos[1][1]: " << cubePositions[1][1] << "\n";
		//std::cout << "ObjPos[0][1] + other: " << objectPositions[0][1] + objectVertices[1] << "\n";
		//std::cout << "ObjPos[0][1] + other: " << objectPositions[0][1] + objectVertices[1] + 3.0f << "\n";

		//std::cout << "cubepos[0][1]" << cubePositions[0][1] << "\n";
		//std::cout << "objvert[13]" << objectVertices[13] << "\n";

		//std::cout << "simul x: " << simul_x1 << "  " << "simul y: " << simul_y1 << " \n";



		//std::cout << "y = " << obj_m << "x + " << obj_c << "   ,   y = " << proj_m << "x + " << proj_c << "\n" << "tempcalcposy: " << tempCalcPosY << " tempcalcposx: " << tempCalcPosX << "\n" << "simul x: " << simul_x1 << " simul y: " << simul_y1 << "\n";
		//std::cout << "\n";
		
	}


	
	if (projectilePosition[1] <= temp_simul_y1 + 1.15f && projectilePosition[1] >= temp_simul_y1 - 1.15f && projectilePosition[0] <= temp_simul_x1 + 1.15f && projectilePosition[0] >= temp_simul_x1 - 1.15f)
	{
		//projectileAngle = ProjectileRotation(projectileAngle, rotateObjectAngle, proj_m, obj_m); //To complete
		hasCollidedX = 0;
		//for (int i = 0; i < 4; i++)
		//	std::cout << "diff_x[" << i << "]: " << diff_x[i] << "\n";
		//std::cout << "ddddddddddddddddddddd";
	}
	
	return glm::mat3(tempCalcPosX, tempCalcPosY, 0.0f, temp_simul_x1, temp_simul_y1, 0.0f, projectileAngle, 0.0f, hasCollidedX); //yellow thing x,y / intersect x,y
}