#include "Loader.h"

Loader :: ~Loader ()
{
    for(auto& i : this->vaoList)
        glDeleteVertexArrays(1, &i);

    for(auto& i : this->vboList)
        glDeleteBuffers(1, &i);
}


Raw_Model Loader :: loadToVAO( const std::vector<GLfloat>& positions,
                               const std::vector<GLuint>&  indices )
{
    GLuint id = createVAO();
    bindIndexBuffer ( indices );

    storeDataInAttributeList( 0, positions );
    unbindVAO();

    return { id, indices.size() };
}

void Loader :: bindIndexBuffer( const std::vector<GLuint>& indices )
{
    GLuint vbo = createVBO( GL_ELEMENT_ARRAY_BUFFER );
    glBufferData ( GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof ( indices.at( 0 ) ), indices.data(), GL_STATIC_DRAW );
}


//Vertex ARRAY object
GLuint Loader::createVAO()
{
    GLuint id;
    glGenVertexArrays( 1, &id );
    glBindVertexArray ( id );

    vaoList.push_back( id );
    return id;
}

//Vertex BUFFER object
GLuint Loader::createVBO( GLenum type )
{
    GLuint vbo;
    glGenBuffers( 1, &vbo );
    glBindBuffer ( type, vbo );

    vboList.push_back (  vbo );
    return vbo;
}


void Loader :: storeDataInAttributeList ( int attributeID, const std::vector<GLfloat>& data )
{
    GLuint vbo = createVBO( GL_ARRAY_BUFFER );
    glBufferData ( GL_ARRAY_BUFFER, data.size() * sizeof ( data.at( 0 ) ), data.data(), GL_STATIC_DRAW );

    glVertexAttribPointer       ( attributeID, 3, GL_FLOAT, GL_FALSE, 0, ( GLvoid* ) 0 );
    glEnableVertexAttribArray   ( attributeID );

    glBindBuffer ( GL_ARRAY_BUFFER, 0 );

}

void Loader :: unbindVAO()
{
    glBindVertexArray ( 0 );
}

