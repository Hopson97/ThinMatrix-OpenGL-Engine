#include "Loader.h"

#include <SFML/Graphics/Image.hpp>

#include "Raw_Model.h"

Loader :: ~Loader ()
{
    for(auto& i : this->vaoList)
        glDeleteVertexArrays(1, &i);

    for(auto& i : this->vboList)
        glDeleteBuffers(1, &i);

    for(auto& i : this->textureList)
        glDeleteTextures(1, &i);
}


Raw_Model Loader :: loadToVAO( const std::vector<GLfloat>& positions,
                               const std::vector<GLuint>&  indices,
                               const std::vector<GLfloat>&  texture )
{
    GLuint id = createVAO();
    bindIndexBuffer ( indices );

    storeDataInAttributeList( 0, 3, positions );
    storeDataInAttributeList( 1, 2, texture );
    unbindVAO();

    return { id, indices.size() };
}

GLuint Loader :: loadTexture ( const std::string& fileName )
{
    sf::Image image;
    image.loadFromFile( "Data/Textures/" + fileName + ".png" );

    image.flipVertically    ();

    GLuint textureID;
    glGenTextures( 1, &textureID );
    textureList.push_back( textureID );

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    return textureID;
}



void Loader :: bindIndexBuffer( const std::vector<GLuint>& indices )
{
    createVBO( GL_ELEMENT_ARRAY_BUFFER );
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

/*
void Loader :: storeDataInAttributeList ( int attributeID, const std::vector<GLfloat>& data )
{
    createVBO( GL_ARRAY_BUFFER );
    glBufferData ( GL_ARRAY_BUFFER, data.size() * sizeof ( data.at( 0 ) ), data.data(), GL_STATIC_DRAW );

    glVertexAttribPointer       ( attributeID, 3, GL_FLOAT, GL_FALSE, 0, ( GLvoid* ) 0 );
    glEnableVertexAttribArray   ( attributeID );

    glBindBuffer ( GL_ARRAY_BUFFER, 0 );

}*/

void Loader :: unbindVAO()
{
    glBindVertexArray ( 0 );
}

