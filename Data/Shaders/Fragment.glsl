#version 400 core

in vec2 textureCoords;

in vec3 surfaceNormal;
in vec3 toLightSource;

out vec4 outColor;

uniform sampler2D textureOfModel;

uniform vec3 lightColour;

void main ( void )
{
    vec3 unitNormal         = normalize ( surfaceNormal );
    vec3 unitLightVector    = normalize ( toLightSource );

    float nDot1         = dot ( unitNormal, unitLightVector );
    float brightness    = max ( nDot1, 0.1 );

    vec3 diffuse = brightness * lightColour;

    outColor = vec4 ( diffuse, 1.0 ) * texture ( textureOfModel, textureCoords );
}
