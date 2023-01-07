#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normals;
layout(location=2) in vec2 textCoords;

uniform mat4 u_MVP;
uniform mat4 u_Model;

out vec3 v_Normal;
out vec3 v_localPosition;
out vec2 v_TexCoord;

void main()
{
    gl_Position = u_MVP * vec4(position, 1.0);
    v_Normal = vec3(u_Model * vec4(normals, 1.0));
    v_localPosition = vec3(u_MVP * vec4(position, 1.0));
    v_TexCoord = textCoords;
}

#shader fragment
#version 330 core

out vec4 color;

in vec3 v_Normal;
in vec3 v_localPosition;
in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec3 u_lightPos;
uniform vec3 u_viewPos;
uniform vec4 u_diffuseColor;
uniform float u_shininess;
uniform vec4 u_specularColor;
uniform vec4 u_Color;
uniform float u_ambientStrength;

void main()
{
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = u_ambientStrength * vec3(u_Color);
    
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

    vec4 tex = texture(u_Texture, v_TexCoord);
    color = tex * vec4(final_color, 1.0);
}