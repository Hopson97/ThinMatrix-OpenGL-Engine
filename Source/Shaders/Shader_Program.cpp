#include "Shader_Program.h"


#include <stdexcept>
#include <string>
#include "shader_loader.h"

Shader_Program::Shader_Program ( const std::string& vertexFile, const std::string& fragmentString )
{
    loadShader( vertexFile, fragmentString, m_id, m_vertexId, m_fragmentId );
}

Shader_Program :: Shader_Program ( GLuint id, GLuint vertexId, GLuint fragmentId )
:   m_id            ( id )
,   m_vertexId      ( vertexId )
,   m_fragmentId    ( fragmentId )
{ }

void Shader_Program :: createProgram ()
{
    m_id = glCreateProgram();
    glAttachShader ( m_id, m_vertexId   );
    glAttachShader ( m_id, m_fragmentId );

    bindAttributes();

    glLinkProgram  ( m_id );

    glDeleteShader ( m_vertexId );
    glDeleteShader ( m_fragmentId );
}

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


GLuint Shader_Program :: getUniformLocation( const std::string& name ) const
{
    return glGetUniformLocation ( m_id, name.c_str() );
}

void Shader_Program :: loadBool ( GLuint location, bool value ) const
{
    glUniform1i ( location, value );
}

void Shader_Program :: loadFloat ( GLuint location, float value ) const
{
    glUniform1f ( location, value );
}

void Shader_Program :: loadVector3 ( GLuint location, const Vector3& value ) const
{
    glUniform3f ( location, value.x, value.y, value.z );
}

void Shader_Program :: loadMatrix4 ( GLuint location, const Matrix4& matrix ) const
{
    glUniformMatrix4fv ( location, 1, GL_FALSE, glm::value_ptr( matrix ) );
}

void Shader_Program::bindAttribute ( GLuint location, const std::string& name ) const
{
    glBindAttribLocation ( m_id, location, name.c_str() );
}
