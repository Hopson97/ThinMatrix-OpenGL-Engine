#include "Model_Texture.h"

Model_Texture :: Model_Texture ( GLuint id, GLfloat shineDamper, GLfloat reflectivness )
:   m_id                ( id )
,   m_shineDamper       ( shineDamper )
,   m_reflectiveness    ( reflectivness )
{ }


GLuint Model_Texture :: getID () const
{
    return m_id;
}

GLfloat Model_Texture :: getShineDamper() const
{
    return m_shineDamper;
}

GLfloat Model_Texture :: getReflectivity() const
{
    return m_reflectiveness;
}
