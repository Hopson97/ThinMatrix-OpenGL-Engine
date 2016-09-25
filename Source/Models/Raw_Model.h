#ifndef RAW_MODEL_H
#define RAW_MODEL_H

#include "../OpenGL/GLEW/glew.h"

class Raw_Model
{
    public:
        Raw_Model() = default;

        Raw_Model( GLuint vao, GLuint vertexCount );

        GLuint getVaoID         () const;
        GLuint getVertexCount   () const;

    private:
        GLuint m_vaoID;
        GLuint m_vertexCount;
};

#endif // RAW_MODEL_H
