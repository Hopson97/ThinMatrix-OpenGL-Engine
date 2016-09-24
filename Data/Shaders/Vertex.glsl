#version 400 core

layout (location = 0 )   in vec3 position;
layout (location = 1 )   in vec2 texture;

out vec2 textureCoords;

void main ( void )
{

    gl_Position = vec4 ( position.xyz, 1.0 );
    textureCoords = texture;
}
