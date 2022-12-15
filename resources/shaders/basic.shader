#shader vertex
attribute vec4 position;
void main()
{
    gl_Position = position;
}

#shader fragment
uniform vec4 u_Color;
void main()
{
    gl_FragColor = u_Color;
}