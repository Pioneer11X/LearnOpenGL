#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
	// color = vertexColor;
    // color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
	// color = vec4(ourColor, 1.0f);
	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, vec2(TexCoord.x , 1.0f - TexCoord.y)), 0.2);
} 