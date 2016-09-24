#include "Loader.h"

Loader :: ~Loader ()
{
    for(auto& i : this->vaoList)
        glDeleteVertexArrays(1, &i);

    for(auto& i : this->vboList)
        glDeleteBuffers(1, &i);
}


Raw_Model Loader :: loadToVAO( const std::vector<GLfloat>& positions )
{
    GLuint id = createVAO();
    storeDataInAttributeList( 0, positions );
    unbindVAO();

    return { id, positions.size() / 3 };
}

GLuint Loader::createVAO()
{
    GLuint id;
    glGenVertexArrays( 1, &id );
    glBindVertexArray ( id );

    vaoList.push_back( id );

    return id;
}

void Loader :: storeDataInAttributeList ( int attributeID, const std::vector<GLfloat>& data )
{
    GLuint vbo;

    glGenBuffers( 1, &vbo );
    glBindBuffer ( GL_ARRAY_BUFFER, vbo );
    glBufferData ( GL_ARRAY_BUFFER, data.size(), data.data(), GL_STATIC_DRAW );

    glVertexAttribPointer       ( attributeID, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    glEnableVertexAttribArray   ( attributeID );

    glBindBuffer ( GL_ARRAY_BUFFER, 0 );

    vboList.push_back (  vbo );
}

void Loader :: unbindVAO()
{
    glBindVertexArray ( 0 );
}

