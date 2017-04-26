#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Entity
{

private:
	GLfloat * _vertices;
	GLfloat * _indices;

	int _vertexCount;
	int _indexCount;

	GLuint _VBO, _VAO, _EBO;

public:
	Entity(GLfloat * _vertices, int _vertexCount, GLfloat * _indices, int indexCount);
	~Entity();
	void Draw(GLuint ProgramID, GLuint VAO, GLuint VBO, GLuint EBO);
};

