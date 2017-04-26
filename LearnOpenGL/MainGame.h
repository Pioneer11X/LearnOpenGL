#pragma once
#include "SimpleShader.h"
#include "Entity.h"

class MainGame
{

private:
	SimpleShader * _shader;
	Entity * _e;

	GLuint VBO, VAO, EBO;

public:
	MainGame();
	~MainGame();

	bool InitBuffers();
	void Draw();
	void Run();

	SimpleShader * GetShader() { return _shader; }
};

