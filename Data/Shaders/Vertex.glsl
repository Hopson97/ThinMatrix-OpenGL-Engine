#version 400 core

layout (location = 0 )   in vec3 position;
layout (location = 1 )   in vec2 texture;

out vec2 textureCoords;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main ( void )
{

    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4 ( position.xyz, 1.0 );
    textureCoords = texture;
}
