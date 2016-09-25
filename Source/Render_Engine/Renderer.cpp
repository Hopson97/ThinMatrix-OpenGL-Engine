#include "Renderer.h"

#include "Entity.h"
#include "Textured_Model.h"
#include "Model_Texture.h"
#include "Raw_Model.h"

#include "Maths.h"
#include "Display_Manager.h"

#include "Static_Shader.h"

Renderer :: Renderer ( Static_Shader& shader )
{
    projectionMatrix = glm::perspective( FIELD_OF_VIEW, (float)Display_Manager::WIDTH / Display_Manager::HEIGHT, NEAR_PLANE, FAR_PLANE );
    shader.start();
    shader.loadProjectionMatrix( projectionMatrix );
    shader.stop();
}

void Renderer :: render( const Entity& entity, Static_Shader& shader )
{
    const Textured_Model& model     = entity.getModel   ();
    const Raw_Model&      rawModel  = model.getRawModel ();

    glBindVertexArray ( rawModel.getVaoID() );


    Matrix4 transformation = Maths::createTransforrmationMatrix( entity.getPosition(),
                                                                 entity.getRotation(),
                                                                 entity.getScale() );

    shader.loadTransformationMatrix( transformation );

    const Model_Texture& t = model.getTexture();
    shader.loadShineVariables( t.getShineDamper(), t.getReflectivity() );

    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, model.getTexture().getID() );

    glDrawElements( GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0 );

    glBindVertexArray ( 0 );
}
