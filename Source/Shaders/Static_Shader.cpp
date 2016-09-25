#include "Static_Shader.h"

#include "Light.h"
#include "Camera.h"
#include "Maths.h"

Static_Shader :: Static_Shader()
:   Shader_Program ( "Data/Shaders/Vertex.glsl", "Data/Shaders/Fragment.glsl" )
{
    createProgram();
    getAllUniformLocations();
}

void Static_Shader :: loadTransformationMatrix ( const Matrix4& matrix ) const
{
    loadMatrix4( locationTransformMatrix, matrix );
}

void Static_Shader :: loadViewMatrix ( const Camera& camera ) const
{
    Matrix4 view = Maths::createViewMatrix( camera );
    loadMatrix4( locationViewMatrix, view );
}


void Static_Shader :: loadProjectionMatrix ( const Matrix4& matrix ) const
{
    loadMatrix4( locationProjectionMatrix, matrix );
}

void Static_Shader :: loadLight ( const Light& light ) const
{
    loadVector3( locationLightPosition, light.getPosition () );
    loadVector3( locationLightColour,   light.getColour   () );
}

void Static_Shader :: loadShineVariables ( float damper, float reflectivness )
{
    loadFloat( locationShineDamper,     damper          );
    loadFloat( locationReflectivness,   reflectivness   );
}



void Static_Shader :: bindAttributes ()
{
    bindAttribute( 0, "position" );
    bindAttribute( 1, "texture"  );
    bindAttribute( 2, "normal"  );
}


void Static_Shader :: getAllUniformLocations ()
{
    locationTransformMatrix     = getUniformLocation( "transformationMatrix"    );
    locationProjectionMatrix    = getUniformLocation( "projectionMatrix"        );
    locationViewMatrix          = getUniformLocation( "viewMatrix"              );

    locationLightPosition       = getUniformLocation( "lightPosition"   );
    locationLightColour         = getUniformLocation( "lightColour"     );

    locationShineDamper         = getUniformLocation( "shineDamper"     );
    locationReflectivness       = getUniformLocation( "reflectivness"   );

}
