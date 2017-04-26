#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class SimpleShader
{

private:
	GLFWwindow * _window;
	GLuint _programID;

public:
	SimpleShader();
	~SimpleShader();

	bool InitSystems();
	bool CompileAllShaders();
	bool CompileShader(const char * _filename, int SHADER_TYPE);

	GLuint GetProgramID() {
		return _programID;
	}

	GLFWwindow * GetWindow() { return _window; }
};

extern void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);