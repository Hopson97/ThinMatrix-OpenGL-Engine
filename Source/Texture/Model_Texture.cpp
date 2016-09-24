#include "Model_Texture.h"

Model_Texture :: Model_Texture ( GLuint id )
:   m_id ( id )
{ }

GLuint Model_Texture :: getID () const
{
    return m_id;
}
