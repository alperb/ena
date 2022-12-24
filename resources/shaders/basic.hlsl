#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normals;
layout(location=2) in vec2 textCoords;

uniform mat4 u_MVP;

out vec3 v_Normal;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
    v_Normal = normals;
}

#shader fragment
#version 330 core

out vec4 color;
in vec3 v_Normal;

uniform vec4 u_Color;
uniform vec3 u_lightPos;
uniform vec3 u_viewPos;

void main()
{
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = ambientStrength * lightColor;

    float diffuseFactor = max(dot(normalize(v_Normal), normalize(u_lightPos - u_viewPos)), 0.0);

    vec3 diffuse = diffuseFactor * lightColor;

    color = u_Color * vec4((ambient + diffuse), 1.0);
}