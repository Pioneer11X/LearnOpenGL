// GLEW
#define GLEW_STATIC
#include <GL\glew.h>

//GLFW
#include <GLFW\glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include "Shader.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// Memory Leak line detection.
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUGs

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main() {

	// Set flags for Memory Leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int * test = new int();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Only for MacOS
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow * window = glfwCreateWindow(800, 600, "Learn OpenGL", nullptr, nullptr);

	if (nullptr == window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialize Glew" << std::endl;
		return -1;
	}

	// Need to pass the Width and Height of the Window from GLFW to OpenGL.
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);

	//GLuint VBO;
	//glGenBuffers(1, &VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Get the Maximum Number of Vertex Attributes.
	GLint nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	////Compile Shaders
	//std::ifstream fileptr("shader.vert");
	//if (fileptr.fail()) {
	//	std::printf("Failed to Open Vertex Shader");
	//}

	//std::string fileContents = "";
	//std::string line;

	//while (std::getline(fileptr, line))
	//{
	//	fileContents += line + "\n";
	//}

	//std::cout << fileContents << std::endl;

	//fileptr.close();
	//const char * vertShaderSource = fileContents.c_str();
	//
	//GLuint vertexShader;
	//vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//glShaderSource(vertexShader, 1, &vertShaderSource, NULL);
	//glCompileShader(vertexShader);

	//GLint success;
	//GLchar infoLog[512];
	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	//if (!success)
	//{
	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}

	//fileptr.open("shader.frag");
	//if (fileptr.fail()) {
	//	std::printf("Failed to Open Fragment Shader");
	//}

	//fileContents = "";
	//line = "";

	//while (std::getline(fileptr, line))
	//{
	//	fileContents += line + "\n";
	//}

	//std::cout << fileContents << std::endl;

	//fileptr.close();
	//const char * fragShaderSource = fileContents.c_str();

	//GLuint fragmentShader;
	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &fragShaderSource, NULL);
	//glCompileShader(fragmentShader);

	//fileptr.open("yellowShader.frag");
	//if (fileptr.fail()) {
	//	std::printf("Failed to Open Yellow Fragment Shader");
	//}

	//fileContents = "";
	//line = "";

	//while (std::getline(fileptr, line))
	//{
	//	fileContents += line + "\n";
	//}

	//std::cout << fileContents << std::endl;

	//fileptr.close();
	//const char * yellowFragShaderSource = fileContents.c_str();

	//GLuint yellowFragmentShader;
	//yellowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(yellowFragmentShader, 1, &yellowFragShaderSource, NULL);
	//glCompileShader(yellowFragmentShader);

	//GLuint shaderProgram, yellowShaderProgram;
	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);

	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//if (!success) {
	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	//	std::cout << infoLog << std::endl;
	//}

	//yellowShaderProgram = glCreateProgram();
	//glAttachShader(yellowShaderProgram, vertexShader);
	//glAttachShader(yellowShaderProgram, yellowFragmentShader);
	//glLinkProgram(yellowShaderProgram);

	//

	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);

	Shader ourShader("shader.vert", "shader.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		//0.5f,  0.5f, 0.0f,  // Top Right
		//0.5f, -0.5f, 0.0f,  // Bottom Right
		//-0.5f, -0.5f, 0.0f,  // Bottom Left

		//0.4f,  0.4f, -0.1f,  // Top Right
		//-0.6f,  0.4f, -0.1f,   // Top Left  
		//-0.6f, -0.6f, -0.1f,  // Bottom Left

		// First triangle		// Colors
		-0.9f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	 // Left 
		-0.0f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	 // Right
		-0.45f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	 // Top 

		// Second triangle
		0.0f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	 // Left
		0.9f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	 // Right
		0.45f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f	 // Top 
		
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3,   // First Triangle
		1, 2, 3    // Second Triangle
	};

	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Color Attribute.
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); This code line causes to crash because this is not passed over to glDrawElements call.

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

						  // Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		GLfloat redValue = (cos(timeValue) / 2) + 0.5;
		GLfloat blueValue = ( greenValue + redValue )/2 + 0.5f;

		// Draw our first triangle
		ourShader.UseShader();
		GLint vertexOffsetLocation = glGetUniformLocation(ourShader.Program, "vertexOffset");
		glBindVertexArray(VAO);
		glUniform3f(vertexOffsetLocation, redValue, greenValue, blueValue);
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}