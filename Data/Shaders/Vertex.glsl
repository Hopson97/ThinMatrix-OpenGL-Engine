#version 400 core

layout (location = 0 )   in vec3 position;
layout (location = 1 )   in vec2 texture;
layout (location = 2 )   in vec3 normal;

out vec2 textureCoords;

out vec3 surfaceNormal;
out vec3 toLightSource;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform vec3 lightPosition;

void main ( void )
{
    vec4 worldPosition = transformationMatrix * vec4 ( position, 1.0f );

    gl_Position = projectionMatrix * viewMatrix * worldPosition;

    textureCoords = texture;

    surfaceNormal = ( transformationMatrix * vec4 ( normal, 0.0f ) ).xyz;
    toLightSource = lightPosition - worldPosition.xyz;
}
