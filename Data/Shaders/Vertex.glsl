#version 400 core

layout (location = 0 )   in vec3 position;

out vec3 color;

void main ( void )
{

    gl_Position = vec4 ( position, 1.0 );
    color = vec3 ( 0, 1, 2 );
}
