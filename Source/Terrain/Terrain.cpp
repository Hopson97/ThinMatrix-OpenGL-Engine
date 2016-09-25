#include "Terrain.h"

#include <vector>

#include "Loader.h"
#include "Model_Texture.h"

Terrain :: Terrain ( int gridX, int gridZ, Loader& loader, const Model_Texture& texture )
:   m_model     ( generateTerrain( loader ) )
,   m_texture   ( &texture )
,   m_x         ( gridX * SIZE )
,   m_z         ( gridZ * SIZE )
{
    generateTerrain( loader );
}

Raw_Model Terrain :: generateTerrain ( Loader& loader )
{
    int count = VERTEX_COUNT * VERTEX_COUNT;

    std::vector<GLfloat> vertices   ( count * 3 );
    std::vector<GLfloat> normals    ( count * 3 );
    std::vector<GLfloat> textures   ( count * 2 );

    std::vector<GLuint> indices     ( 6 * ( VERTEX_COUNT - 1 ) * (VERTEX_COUNT - 1 ) );

    int vertexPointer = 0;
    for ( int x = 0 ; x < VERTEX_COUNT ; x++ ) {
        for ( int y = 0 ; y < VERTEX_COUNT ; y++ ) {
            vertices    [ vertexPointer * 3     ]   = (float) y / ( (float) VERTEX_COUNT - 1 ) * SIZE;
            vertices    [ vertexPointer * 3 + 1 ]   = 0;
            vertices    [ vertexPointer * 3 + 2 ]   = (float) x / ( (float) VERTEX_COUNT - 1 ) * SIZE;

            normals     [ vertexPointer * 3     ]   = 0;
            normals     [ vertexPointer * 3 + 1 ]   = 1;
            normals     [ vertexPointer * 3 + 2 ]   = 0;

            textures    [ vertexPointer * 2     ]   = (float) y / ( (float) VERTEX_COUNT - 1 );
            textures    [ vertexPointer * 2     ]   = (float) x / ( (float) VERTEX_COUNT - 1 );

            vertexPointer++;
        }
    }

    int pointer = 0;
    for ( int gz = 0 ; gz < VERTEX_COUNT - 1 ; gz++ ) {
        for ( int gx = 0 ; gx < VERTEX_COUNT - 1 ; gx++ ) {
            int topLeft     = ( gz * VERTEX_COUNT ) + gx;
            int topRight    = topLeft + 1;

            int bottomLeft  = ( ( gz + 1) * VERTEX_COUNT ) + gx;
            int bottomRight = bottomLeft + 1;

            indices [ pointer++ ] = topLeft;
            indices [ pointer++ ] = bottomLeft;
            indices [ pointer++ ] = topRight;
            indices [ pointer++ ] = topRight;
            indices [ pointer++ ] = bottomLeft;
            indices [ pointer++ ] = bottomRight;
        }
    }

    return loader.loadToVAO( vertices, indices, normals, textures );
}


const Raw_Model& Terrain :: getModel () const
{
    return m_model;
}

const Model_Texture& Terrain :: getTexture () const
{
    return *m_texture;
}

float Terrain :: getX () const
{
    return m_x;
}

float Terrain :: getZ () const
{
    return m_z;
}

















