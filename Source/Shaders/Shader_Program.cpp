#include "Shader_Program.h"

#include "shader_loader.h"

Shader_Program::Shader_Program ( const std::string vertexFile, const std::string fragmentString )
{
    //loadShader( vertexFile, fragmentString, m_id, m_vertexId, m_fragmentId );
}

Shader_Program :: Shader_Program ( GLuint id, GLuint vertexId, GLuint fragmentId )
:   m_id            ( id )
,   m_vertexId      ( vertexId )
,   m_fragmentId    ( fragmentId )
{ }

Shader_Program :: ~Shader_Program()
{
    stop();
    glDetachShader ( m_id, m_vertexId );
    glDetachShader ( m_id, m_fragmentId );

    glDeleteShader ( m_vertexId );
    glDeleteShader ( m_fragmentId );

    glDeleteProgram ( m_id );
}


void Shader_Program :: start()
{
    glUseProgram ( m_id );
}

void Shader_Program :: stop()
{
    glUseProgram ( 0 );
}

void Shader_Program::bindAttribute ( GLuint location, const std::string& name )
{
    glBindAttribLocation ( m_id, location, name.c_str() );
}
