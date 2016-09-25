#version 400 core

in vec2 textureCoords;

in vec3 surfaceNormal;
in vec3 toLightSource;

out vec4 outColor;

uniform sampler2D textureSampler;

uniform vec3 lightColour;

void main ( void )
{
    vec3 unitNormal         = normalize ( surfaceNormal );
    vec3 unitLightVector    = normalize ( toLightSource );

    float nDot1 = dot ( unitNormal, unitLightVector );
    float brightness = max ( nDot1, 0 );

    vec3 diffuse = brightness * lightColour;

    vec4 col = vec4 ( diffuse, 1.0 ) * texture ( textureSampler, textureCoords );

    float value = 0.1;

    if ( col.r <= value ) {
        col.r = value;
    }
    if ( col.g <= value ) {
        col.g = value;
    }
    if ( col.b <= value ) {
        col.b = value;
    }
    outColor = col;

    //outColor = vec4 ( diffuse, 1.0 ) * texture ( textureSampler, textureCoords );
    //outColor = texture ( textureSampler, textureCoords );
}
