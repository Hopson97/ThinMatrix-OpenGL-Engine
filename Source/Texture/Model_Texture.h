#ifndef MODEL_TEXTURE_H
#define MODEL_TEXTURE_H

#include "../OpenGL/GLEW/glew.h"

class Model_Texture
{
    public:
        Model_Texture( GLuint id );

        GLuint getID () const;


    private:
        GLuint m_id;
};

#endif // MODEL_TEXTURE_H
