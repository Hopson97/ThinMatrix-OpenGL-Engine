#include "Static_Shader.h"

Static_Shader :: Static_Shader()
:   Shader_Program ( m_vertexFile, m_fragmentFile )
{
   // bindAttributes();
}


void Static_Shader :: bindAttributes()
{
   // bindAttribute( 0, "position" );
}
