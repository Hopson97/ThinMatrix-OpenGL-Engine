#include "Terrain_Render.h"

#include <iostream>

#include "Model_Texture.h"
#include "Maths.h"

Terrain_Render :: Terrain_Render ( Terrain_Shader& shader, const Matrix4& projectionMatrix )
:   m_shader ( &shader )
{
    shader.start();
    shader.loadProjectionMatrix( projectionMatrix );
    shader.stop();
}

void Terrain_Render :: render ( std::vector< const Terrain* >& terrains )
{
    for ( auto& terrain : terrains ) {
        prepareTerrain  ( *terrain );
        loadModelMatrix ( *terrain );
        glDrawElements( GL_TRIANGLES, terrain->getModel().getVertexCount(), GL_UNSIGNED_INT, 0 );

        unbindModel();
    }
}

void Terrain_Render :: prepareTerrain ( const Terrain& terrain )
{
    const auto& rawModel  = terrain.getModel();
    glBindVertexArray ( rawModel.getVaoID() );

    const auto& texture = terrain.getTexture();
    m_shader->loadShineVariables( texture.getShineDamper (),
                                  texture.getReflectivity() );

    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, texture.getID() );
}

void Terrain_Render :: unbindModel ()
{
    glBindVertexArray ( 0 );
}

void Terrain_Render :: loadModelMatrix ( const Terrain& terrain )
{
    Matrix4 transformation = Maths::createTransforrmationMatrix( { terrain.getX(), 0, terrain.getZ() },
                                                                 { 0, 0, 0 },
                                                                 { 1, 1, 1 } );
    m_shader->loadTransformationMatrix( transformation );
}
