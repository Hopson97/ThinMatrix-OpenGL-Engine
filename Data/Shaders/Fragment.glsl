#version 400 core

in vec2 textureCoords;

in vec3 surfaceNormal;
in vec3 toLightSource;

in vec3 toCameraVector;

out vec4 outColor;

uniform sampler2D textureOfModel;

uniform vec3    lightColour;

uniform float   shineDamper;
uniform float   reflectivness;

vec3 getSpecular ( vec3 unitNormal )
{
    vec3 unitVectorToCamera = normalize ( toCameraVector );
    vec3 lightDirection = -unitVectorToCamera;
    vec3 reflectiveLightDirection = reflect ( lightDirection, unitNormal );

    float specularFactor = dot ( reflectiveLightDirection, unitVectorToCamera );
    specularFactor = max ( specularFactor, 0.1 );

    float dampedFactor = pow ( specularFactor, shineDamper );

    return dampedFactor * reflectivness * lightColour;
}

void main ( void )
{
    vec3 unitNormal         = normalize ( surfaceNormal );
    vec3 unitLightVector    = normalize ( toLightSource );

    float nDot1         = dot ( unitNormal, unitLightVector );
    float brightness    = max ( nDot1, 0.2 );

    vec3 diffuse = brightness * lightColour;

    vec3 finalSpecular = getSpecular( unitNormal);

    outColor = vec4 ( diffuse, 1.0 ) * texture ( textureOfModel, textureCoords ) + vec4 ( finalSpecular, 1.0 );
}

/*
    vec3 unitVectorToCamera = normalize ( toCameraVector );
    vec3 lightDirection = -unitVectorToCamera;
    vec3 reflectiveLightDirection = reflect ( lightDirection, unitNormal );

    float specularFactor = dot ( reflectiveLightDirection, unitVectorToCamera );
    specularFactor = max ( specularFactor, 0.1 );

    float dampedFactor = pow ( specularFactor, shineDamper );

    return dampedFactor * lightColour;
    */
