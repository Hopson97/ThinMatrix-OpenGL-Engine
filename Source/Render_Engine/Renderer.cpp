#include "Renderer.h"

void Renderer :: prepare()
{

}

void Renderer :: render( const Raw_Model& model )
{
    glBindVertexArray ( model.getVaoID() );

    glDrawElements( GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0 );

    glBindVertexArray ( 0 );
}
