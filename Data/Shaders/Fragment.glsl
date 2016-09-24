#version 400 core

in vec2 textureCoords;

out vec4 outColor;

uniform sampler2D textureSampler;

void main ( void )
{
     outColor = texture ( textureSampler, textureCoords );
}
