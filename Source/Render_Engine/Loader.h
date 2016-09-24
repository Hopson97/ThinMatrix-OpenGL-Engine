#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <memory>

#include "Raw_Model.h"

class Loader
{
    public:
        ~Loader();

        Raw_Model loadToVAO ( const std::vector<GLfloat>& positions );


    private:
        GLuint createVAO ();
        void storeDataInAttributeList ( int attributeID, const std::vector<GLfloat>& data );
        void unbindVAO();

        std::vector<GLuint> vaoList;
        std::vector<GLuint> vboList;
};

#endif // LOADER_H
