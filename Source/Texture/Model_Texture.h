#ifndef MODEL_TEXTURE_H
#define MODEL_TEXTURE_H

#include "../OpenGL/GLEW/glew.h"

class Model_Texture
{
    public:
        Model_Texture( GLuint id, GLfloat shineDamper = 1, GLfloat reflectivness = 1 );

        GLuint getID () const;

        GLfloat getShineDamper  () const;
        GLfloat getReflectivity () const;


    private:
        GLuint  m_id;

        GLfloat m_shineDamper = 1;
        GLfloat m_reflectiveness = 1;
};

#endif // MODEL_TEXTURE_H
