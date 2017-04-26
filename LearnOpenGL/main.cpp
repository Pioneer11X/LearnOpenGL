// GLEW
#define GLEW_STATIC
#include <GL\glew.h>

//GLFW
#include <GLFW\glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

#include "MainGame.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main() {

	MainGame(mg);
	mg.InitBuffers();
	mg.Run();

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}