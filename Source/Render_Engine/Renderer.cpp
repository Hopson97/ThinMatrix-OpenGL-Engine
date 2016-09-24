#include "Renderer.h"

void Renderer :: prepare()
{

}

void Renderer :: render( const Textured_Model& model )
{
    const Raw_Model& rawModel = model.getRawModel();
    glBindVertexArray ( rawModel.getVaoID() );

    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, model.getTexture().getID() );

    glDrawElements( GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, 0 );

    glBindVertexArray ( 0 );
}
