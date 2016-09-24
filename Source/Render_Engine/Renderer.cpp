#include "Renderer.h"

void Renderer :: prepare()
{

}

void Renderer :: render( const Raw_Model& model )
{
    glBindVertexArray ( model.getVaoID() );

    glDrawArrays( GL_TRIANGLES, 0, model.getVertexCount() );

    glBindVertexArray ( 0 );
}
