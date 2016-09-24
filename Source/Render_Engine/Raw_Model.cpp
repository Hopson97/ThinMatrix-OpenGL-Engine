#include "Raw_Model.h"

Raw_Model::Raw_Model( GLuint vao, GLuint vertexCount )
:   m_vaoID         ( vao )
,   m_vertexCount   ( vertexCount )
{

}


GLuint Raw_Model :: getVaoID() const
{
    return m_vaoID;
}

GLuint Raw_Model :: getVertexCount() const
{
    return m_vertexCount;
}
