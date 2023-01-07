#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 u_Projection;
uniform mat4 u_View;

void main()
{
    TexCoords = vec3(aPos.x, aPos.y, -aPos.z);
    vec4 pos = u_Projection * u_View * vec4(aPos, 1.0);
    gl_Position = pos.xyww;
} 

#shader fragment
#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{    
    FragColor = texture(skybox, TexCoords);
}