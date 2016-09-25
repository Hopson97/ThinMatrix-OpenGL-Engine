#include "Renderer.h"

#include "Entity.h"
#include "Textured_Model.h"
#include "Model_Texture.h"
#include "Raw_Model.h"

#include "Maths.h"
#include "Display_Manager.h"

Renderer :: Renderer ( Static_Shader& shader )
:   m_shader ( &shader )
{
    projectionMatrix = glm::perspective( FIELD_OF_VIEW, (float)Display_Manager::WIDTH / Display_Manager::HEIGHT, NEAR_PLANE, FAR_PLANE );
    shader.start();
    shader.loadProjectionMatrix( projectionMatrix );
    shader.stop();
}

void Renderer :: render ( const std::map< const Textured_Model*, std::vector<Entity>>& entities )
{
    for ( auto& model : entities ) {
        prepareModel ( *model.first );

        for ( auto& enity : model.second ) {
            prepareInstance( enity );
            glDrawElements( GL_TRIANGLES, model.first->getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0 );
        }
        unbindModel( *model.first );
    }
}

void Renderer :: prepareModel ( const Textured_Model& model )
{
    const auto& rawModel  = model.getRawModel ();
    glBindVertexArray ( rawModel.getVaoID() );

    const Model_Texture& t = model.getTexture();
    m_shader->loadShineVariables( t.getShineDamper(), t.getReflectivity() );

    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, model.getTexture().getID() );
}

void Renderer :: unbindModel ( const Textured_Model& model )
{
    glBindVertexArray ( 0 );
}

void Renderer :: prepareInstance ( const Entity& entity )
{
    Matrix4 transformation = Maths::createTransforrmationMatrix( entity.getPosition(),
                                                                 entity.getRotation(),
                                                                 entity.getScale() );
    m_shader->loadTransformationMatrix( transformation );
}
