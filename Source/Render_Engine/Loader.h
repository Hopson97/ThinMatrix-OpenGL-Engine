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
                              const std::vector<GLuint>&  indices );


    private:
        void bindIndexBuffer ( const std::vector<GLuint>& indices );

        GLuint createVAO ();
        GLuint createVBO ( GLenum type );
        void storeDataInAttributeList ( int attributeID, const std::vector<GLfloat>& data );
        void unbindVAO();

        std::vector<GLuint> vaoList;
        std::vector<GLuint> vboList;
};

#endif // LOADER_H
