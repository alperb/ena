#shader vertex
#version 330 core

layout(location=0) in vec4 position;
layout (location=1) in vec3 aNormal;
layout(location=2) in vec2 aTexCoord;


uniform mat4 u_MVP;

out vec3 v_FragPos;
out vec3 v_Normal;

void main()
{
    gl_Position = u_MVP * position;
    v_Normal = aNormal;
    v_FragPos = vec3(position);
}

#shader fragment
#version 330 core

in vec3 v_Normal;
in vec3 v_FragPos;

uniform vec4 u_Color;
uniform vec3 u_lightPos;
uniform vec3 u_viewPos;

out vec4 color;

void main()
{
    float specularStrength = 0.5;
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(u_lightPos - v_FragPos);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);

    // specular lighting
    vec3 viewDir = normalize(u_viewPos - v_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // diffuse lighting
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // ambient lighting
    float ambientStrength = 0.9;
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = (ambient + diffuse + specular);

    color = vec4(result, 1.0) * u_Color;
}