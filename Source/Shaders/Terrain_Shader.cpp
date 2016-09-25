#include "Terrain_Shader.h"

#include "Light.h"
#include "Camera.h"
#include "Maths.h"

Terrain_Shader :: Terrain_Shader()
:   Shader_Program ( "Data/Shaders/TerrainVertexShader.glsl", "Data/Shaders/TerrainFragmentShader.glsl" )
{
    createProgram();
    getAllUniformLocations();
}

void Terrain_Shader :: loadTransformationMatrix ( const Matrix4& matrix ) const
{
    loadMatrix4( locationTransformMatrix, matrix );
}

void Terrain_Shader :: loadViewMatrix ( const Camera& camera ) const
{
    Matrix4 view = Maths::createViewMatrix( camera );
    loadMatrix4( locationViewMatrix, view );
}


void Terrain_Shader :: loadProjectionMatrix ( const Matrix4& matrix ) const
{
    loadMatrix4( locationProjectionMatrix, matrix );
}

void Terrain_Shader :: loadLight ( const Light& light ) const
{
    loadVector3( locationLightPosition, light.getPosition () );
    loadVector3( locationLightColour,   light.getColour   () );
}

void Terrain_Shader :: loadShineVariables ( float damper, float reflectivness )
{
    loadFloat( locationShineDamper,     damper          );
    loadFloat( locationReflectivness,   reflectivness   );
}

void Terrain_Shader :: bindAttributes ()
{
    bindAttribute( 0, "position" );
    bindAttribute( 1, "texture"  );
    bindAttribute( 2, "normal"  );
}


void Terrain_Shader :: getAllUniformLocations ()
{
    locationTransformMatrix     = getUniformLocation( "transformationMatrix"    );
    locationProjectionMatrix    = getUniformLocation( "projectionMatrix"        );
    locationViewMatrix          = getUniformLocation( "viewMatrix"              );

    locationLightPosition       = getUniformLocation( "lightPosition"   );
    locationLightColour         = getUniformLocation( "lightColour"     );

    locationShineDamper         = getUniformLocation( "shineDamper"     );
    locationReflectivness       = getUniformLocation( "reflectivness"   );

}
