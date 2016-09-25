#include "Entity_Renderer.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Textured_Model.h"
#include "Model_Texture.h"
#include "Raw_Model.h"

#include "Maths.h"
#include "Display_Manager.h"

Entity_Renderer :: Entity_Renderer ( Static_Shader& shader, const Matrix4& projectionMatrix )
:   m_shader ( &shader )
{
    shader.start();
    shader.loadProjectionMatrix( projectionMatrix );
    shader.stop();
}

void Entity_Renderer :: render ( const std::map< const Textured_Model*, std::vector< const Entity* > >& entities )
{
    for ( auto& model : entities ) {
        prepareModel ( *model.first );

        for ( auto& enity : model.second ) {
            prepareInstance( *enity );
            glDrawElements( GL_TRIANGLES, model.first->getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0 );
        }
        unbindModel( *model.first );
    }
}

void Entity_Renderer :: prepareModel ( const Textured_Model& model )
{
    const auto& rawModel  = model.getRawModel ();
    glBindVertexArray ( rawModel.getVaoID() );

    const Model_Texture& t = model.getTexture();
    m_shader->loadShineVariables( t.getShineDamper(), t.getReflectivity() );

    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, model.getTexture().getID() );
}

void Entity_Renderer :: unbindModel ( const Textured_Model& model )
{
    glBindVertexArray ( 0 );
}

void Entity_Renderer :: prepareInstance ( const Entity& entity )
{
    Matrix4 transformation = Maths::createTransforrmationMatrix( entity.getPosition(),
                                                                 entity.getRotation(),
                                                                 entity.getScale() );
    m_shader->loadTransformationMatrix( transformation );
}
