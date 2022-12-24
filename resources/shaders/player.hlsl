#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normals;
layout(location=2) in vec2 textCoords;

uniform mat4 u_MVP;

out vec3 v_Normal;
out vec3 v_localPosition;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
    v_Normal = normals;
    v_localPosition = position;
}

#shader fragment
#version 330 core

out vec4 color;

in vec3 v_Normal;
in vec3 v_localPosition;

uniform sampler2D u_Texture;
uniform vec3 u_lightPos;
uniform vec3 u_viewPos;
uniform vec4 u_diffuseColor;
uniform float u_shininess;
uniform vec4 u_specularColor;
uniform vec4 u_Color;

void main()
{
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = ambientStrength * lightColor;
    
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(u_lightPos - v_localPosition);

    float diffuseFactor = max(dot(norm, lightDir), 0.0);

    vec3 specularColor = vec3(0.0, 0.0, 0.0);
    vec3 diffuseColor = vec3(0.0, 0.0, 0.0);

    if(diffuseFactor > 0) {
        diffuseColor = diffuseFactor * vec3(u_diffuseColor);

        vec3 viewDir = normalize(u_viewPos - v_localPosition);

        vec3 reflectDir = normalize(reflect(lightDir, norm));
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_shininess);
        specularColor = vec3(u_specularColor) * spec;
    }

    vec3 final_color = clamp(ambient + diffuseColor + specularColor, 0.0, 1.0);

    color = u_Color * vec4(final_color, 1.0);
}