#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <memory>

#include "Raw_Model.h"

class Loader
{
    public:
        ~Loader();

        Raw_Model loadToVAO ( const std::vector<GLfloat>& positions,
                              const std::vector<GLuint>&  indices,
                              const std::vector<GLfloat>&  texture );

        GLuint loadTexture  ( const std::string& fileName );


    private:
        void bindIndexBuffer ( const std::vector<GLuint>& indices );

        GLuint createVAO ();
        GLuint createVBO ( GLenum type );
        void unbindVAO();

        template<typename T>
        void storeDataInAttributeList ( int attributeID, int coordCount, const std::vector<T>& data )
        {
            createVBO( GL_ARRAY_BUFFER );
            glBufferData ( GL_ARRAY_BUFFER, data.size() * sizeof ( data.at( 0 ) ), data.data(), GL_STATIC_DRAW );

            glVertexAttribPointer       ( attributeID, coordCount, GL_FLOAT, GL_FALSE, 0, ( GLvoid* ) 0 );
            glEnableVertexAttribArray   ( attributeID );

            glBindBuffer ( GL_ARRAY_BUFFER, 0 );

        }

        std::vector<GLuint> vaoList;
        std::vector<GLuint> vboList;
        std::vector<GLuint> textureList;
};

#endif // LOADER_H
