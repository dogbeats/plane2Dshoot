#include "Text.h"

GLuint VAO_t, VBO_t;

bool initText = false;

GLfloat textVertices[] =
{
	0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, //BL //A
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 1.0f, //BR
	0.0f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, //TR
	0.0f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, //TR
	0.2f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.75f, //TL
	0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  //BL

	0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 1.0f, //BL //B
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 1.0f, //BR
	0.0f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.75f, //TR
	0.0f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.75f, //TR
	0.2f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 0.75f, //TL
	0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, 1.0f   //BL
};

GLuint texture;

Text::Text()
{

}

Text::~Text()
{

}

glm::vec3 tempPos;
GLfloat tempFovCount;

void Text::drawText(std::string text, Shader ourShader, glm::vec3 cameraUp, GLfloat cameraSpeed, GLfloat deltaTime, GLfloat fov, glm::vec3 cubePos)
{
	GLuint verticesNumber = 0;
	//Read the string

	//Draw next letter
	for (int i = 0; i < 11; i++)
	{
		std::cout << i << "\n";
		if (text[i] == *"a")
		{
			verticesNumber = 0;
			/*
			textVertices[6] = 1.0f; //BL
			textVertices[7] = 1.0f;
			textVertices[14] = 0.75f; //BR
			textVertices[15] = 1.0f;
			textVertices[22] = 0.75f; //TR
			textVertices[23] = 0.75f;
			textVertices[30] = 0.75f; //TR
			textVertices[31] = 0.75f;
			textVertices[38] = 1.0f; //TL
			textVertices[39] = 0.75f;
			textVertices[46] = 1.0f; //BL
			textVertices[47] = 1.0f;
			//std::cout << textVertices[14];*/

			if (!initText)
			{
				glGenVertexArrays(1, &VAO_t);
				glGenBuffers(1, &VBO_t);

				glBindVertexArray(VAO_t);

				glBindBuffer(GL_ARRAY_BUFFER, VBO_t);
				glBufferData(GL_ARRAY_BUFFER, sizeof(textVertices), textVertices, GL_STATIC_DRAW);

				// Position attribute
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
				glEnableVertexAttribArray(0);
				// Color attribute
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(1);
				// TexCoord attribute
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
				glEnableVertexAttribArray(2);

				glBindVertexArray(0); // Unbind VAO


				int width, height;

				glGenTextures(1, &texture);

				glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
				// Set our texture parameters
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				// Set texture filtering
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				unsigned char* image = SOIL_load_image("test_test.png", &width, &height, 0, SOIL_LOAD_RGBA);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
				glGenerateMipmap(GL_TEXTURE_2D);
				SOIL_free_image_data(image);
				glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

				//std::cout << "\n\ninittext\n\n" << height << "\n";

				initText = true;
			}

			glBindVertexArray(VAO_t);

			GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");

			glm::mat4 model;

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
			

			//tempPos += cameraSpeed * cameraUp *glm::mat3(cos(rotatePlaneAngle), -sin(rotatePlaneAngle), 0.0f, sin(rotatePlaneAngle), cos(rotatePlaneAngle), 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;

			//std::cout << fov << " before\n";

			tempFovCount = (11.0f - fov) / 0.2f;
			if (tempFovCount <= -0.98 && tempFovCount >= -1.02 || tempFovCount >= 0.98 && tempFovCount <= 1.02)
			{
				tempFovCount = 1.0f;
			}
			//std::cout << tempFovCount << " tempfovcount\n";
			//if (fov == 11.0f)
			//model = glm::translate(model, cubePos + glm::vec3(1.5f, 2.0f, 0.0f));
			//else if (fov == 10.8f)
			//	model = glm::translate(model, cubePos + glm::vec3(2.3f, 2.3f, 0.0f));


			//std::cout << tempFovCount << " fovcount\n";
			//std::cout << fov << " fov\n";
			//std::cout << (2*(3 * tempFovCount) - 1 * (tempFovCount - 1))  << "\n";

			GLfloat temp = (((tempFovCount - 1.0f) * 0.2f) - 0.1f) * 10.0f;
			GLfloat temp2;
			//std::cout << "test: " << temp << "\n";
			if (tempFovCount <= 1.1f)
			{
				temp2 = tempFovCount * 6;
			}
			else
			{
				temp2 = tempFovCount * 6 - temp;
			}
			//std::cout << "pixels: " << temp2 * 9 - 1<< "\n";
			
			temp = (temp2 * 9 - 1) / 100.0f;

			//model = glm::translate(model, cubePos + glm::vec3(1.5f, 2.0f + float((9 * (tempFovCount + 1)) / 100), 0.0f));
			//model = glm::translate(model, cubePos + glm::vec3(1.5f, (2.0f + temp)*(0.3 * (tempFovCount + 1)), 0.0f));
			model = glm::translate(model, cubePos + glm::vec3(-3.0f + 0.2f*i, 2.09f, 0.0f));
			//std::cout << "Temp: " << 2.0f + temp << "\n";

			//2.09f, 2.75f, 3.6f, 4.75f, 6.44f, 9.23f
			//(0), 0.66f, 0.85f, 1.15f, 1.69f, 2.79f
			//0.19, 0.3, 0.54, 1.1
			//2.0f - div 5.5
			//HEIGHT FROM BOTTOM - 9, 62, 107, 146 (0, 53, 98, 137) 53->45->39
			//FOV AT HEIGHT: 11, 10.8, 10.6, 10.4
			//2.0f -> 9, 1.5f -> 59, 1.0f -> 109
			//ratios 20/53 -> 0.377, 40/98 -> 0.408, 60/137 -> 0.437
			//6*9->11*9->15*9

			//model *= cameraSpeed * glm::mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) * deltaTime;

			//std::cout << std::to_string(objectNumber) + " ";
			//model[0] = glm::rotate(model[0], rotatePlaneAngle, glm::vec3(0.0f, 0.0f, 1.0f));
			
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, verticesNumber*6, 6);

			glBindVertexArray(0);
			//std::cout << tempPos[0] << " " << tempPos[1] << "\n";
			//std::cout << "drawn A\n";
		}

		if (text[i] == *"b")
		{
			GLuint temp = 0;
			verticesNumber = 1;
			/*textVertices[6] = 1.0f; //BL
			textVertices[7] = 1.0f;
			textVertices[14] = 0.5f; //BR
			textVertices[15] = 1.0f;
			textVertices[22] = 0.5f; //TR
			textVertices[23] = 0.5f;
			textVertices[30] = 0.5f; //TR
			textVertices[31] = 0.5f;
			textVertices[38] = 1.0f; //TL
			textVertices[39] = 0.5f;
			textVertices[46] = 1.0f; //BL
			textVertices[47] = 1.0f;*/
			//std::cout << textVertices[14];

			if (!initText)
			{
				glGenVertexArrays(1, &VAO_t);
				glGenBuffers(1, &VBO_t);

				glBindVertexArray(VAO_t);

				glBindBuffer(GL_ARRAY_BUFFER, VBO_t);
				glBufferData(GL_ARRAY_BUFFER, sizeof(textVertices), textVertices, GL_STATIC_DRAW);

				// Position attribute
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
				glEnableVertexAttribArray(0);
				// Color attribute
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(1);
				// TexCoord attribute
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
				glEnableVertexAttribArray(2);

				glBindVertexArray(0); // Unbind VAO


				int width, height;

				glGenTextures(1, &texture);

				glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
				// Set our texture parameters
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				// Set texture filtering
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				unsigned char* image = SOIL_load_image("test_test.png", &width, &height, 0, SOIL_LOAD_RGBA);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
				glGenerateMipmap(GL_TEXTURE_2D);
				SOIL_free_image_data(image);
				glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

				//std::cout << "\n\ninittext\n\n" << height << "\n";

				initText = true;

			}

			glBindVertexArray(VAO_t);

			GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");

			glm::mat4 model;

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);

			tempFovCount = (11.0f - fov) / 0.2f;

			model = glm::translate(model, cubePos + glm::vec3(-3.0f + 0.2f*i, 2.09f, 0.0f));

			//std::cout << std::to_string(objectNumber) + " ";
			//model[0] = glm::rotate(model[0], rotatePlaneAngle, glm::vec3(0.0f, 0.0f, 1.0f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, verticesNumber * 6, 6);

			glBindVertexArray(0);
			
			std::cout << "drawn B\n";
		}
		else
		{
		
		}		

	}
	
}