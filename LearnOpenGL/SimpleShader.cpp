#include "SimpleShader.h"
#include <iostream>
#include <fstream>
#include <string>


SimpleShader::SimpleShader()
{
	_window = nullptr;
	_programID = 0;

	if (!InitSystems()) {
		return;
	}

}


SimpleShader::~SimpleShader()
{
	_programID = 0;
}

bool SimpleShader::InitSystems()
{

	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Only for MacOS
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_window = glfwCreateWindow(800, 600, "Learn OpenGL", nullptr, nullptr);

	if (nullptr == _window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(_window);
	glfwSetKeyCallback(_window, key_callback);


	// Init Glew

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialize Glew" << std::endl;
		return false;
	}

	// Need to pass the Width and Height of the Window from GLFW to OpenGL.
	int width, height;
	glfwGetFramebufferSize(_window, &width, &height);
	glViewport(0, 0, width, height);

	return true;

}

bool SimpleShader::CompileAllShaders()
{

	_programID = glCreateProgram();
	if (0 == _programID) {
		printf("Program not created");
		return false;
	}

	if (!CompileShader("shader.vert", GL_VERTEX_SHADER)) {
		return false;
	}

	if (!CompileShader("shader.frag", GL_FRAGMENT_SHADER)) {
		return false;
	}

	glLinkProgram(_programID);
	GLint success;
	GLchar infoLog[512];
	glGetProgramiv(_programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(_programID, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
		return false;
	}

	return true;
}

bool SimpleShader::CompileShader(const char * _filename, int SHADER_TYPE)
{

	std::ifstream fileptr(_filename);
	if (fileptr.fail()) {
		std::printf("Failed to Open %s Shader", _filename);
		return false;
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(fileptr, line))
	{
		fileContents += line + "\n";
	}

	std::cout << fileContents << std::endl;

	fileptr.close();
	const char * ShaderSource = fileContents.c_str();

	GLuint curShader;
	curShader = glCreateShader(SHADER_TYPE);

	glShaderSource(curShader, 1, &ShaderSource, NULL);
	glCompileShader(curShader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(curShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(curShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

	glAttachShader(_programID, curShader);
	glDeleteShader(curShader);

	return true;
}
