#include "Static_Shader.h"

Static_Shader :: Static_Shader()
:   Shader_Program ( "Data/Shaders/Vertex.glsl", "Data/Shaders/Fragment.glsl" )
{
    bindAttributes();
}


void Static_Shader :: bindAttributes()
{
    bindAttribute( 0, "position" );
    bindAttribute( 1, "texture"  );
}
