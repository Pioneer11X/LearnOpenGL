#version 330 core
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

uniform vec3 vertexOffset;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;

void main()
{
    // gl_Position = vec4( ( position + vertexOffset ) / 2 , 1.0);
	gl_Position = projection * view * model * vec4(position, 1.0f);
	// ourColor = color;
	TexCoord = texCoord;
}