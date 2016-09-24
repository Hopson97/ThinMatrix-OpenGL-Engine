#include "Static_Shader.h"

#include "Camera.h"
#include "Maths.h"

Static_Shader :: Static_Shader()
:   Shader_Program ( "Data/Shaders/Vertex.glsl", "Data/Shaders/Fragment.glsl" )
{
    bindAttributes();
    getAllUniformLocations();
}

void Static_Shader :: loadTransformationMatrix ( const Matrix4& matrix )
{
    loadMatrix4( locationTransformMatrix, matrix );
}

void Static_Shader :: loadViewMatrix ( const Camera& camera )
{
    Matrix4 view = Maths::createViewMatrix( camera );
    loadMatrix4( locationViewMatrix, view );
}


void Static_Shader :: loadProjectionMatrix ( const Matrix4& matrix )
{
    loadMatrix4( locationProjectionMatrix, matrix );
}

void Static_Shader :: bindAttributes ()
{
    bindAttribute( 0, "position" );
    bindAttribute( 1, "texture"  );
}


void Static_Shader :: getAllUniformLocations ()
{
    locationTransformMatrix     = getUniformLocation( "transformationMatrix"    );
    locationProjectionMatrix    = getUniformLocation( "projectionMatrix"        );
    locationViewMatrix          = getUniformLocation( "viewMatrix"              );
}
