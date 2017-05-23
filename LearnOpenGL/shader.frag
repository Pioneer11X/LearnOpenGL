
#version 330 core
out vec4 fragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 viewPos;

// Lighting input.
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;		// The position of the light to calculate Diffuse as well as Specular?

void main()
{
	
	// Ambient Light.
	float ambientStrength = 0.2f;
	vec3 ambient = ambientStrength * lightColor;

	// Diffuse Light.
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);

	float diff = max(dot(norm, lightDir), 0.0f);
	vec3 diffuse = diff * lightColor;

	// Specular Light.
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * objectColor;
	fragColor =vec4(result, 1.0f);

}