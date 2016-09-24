#version 330 core

layout (location = 0)   in vec3 vertexPosition;
layout ( location = 1 ) in vec2 texturePosition;

out vec2 textureCoords;

uniform mat4 projectionViewModelMatrix;

void main()
{
    textureCoords = texturePosition;
    gl_Position = projectionViewModelMatrix * vec4 ( vertexPosition, 1.0 );
}
