#include "Master_Renderer.h"


#include "Light.h"
#include "Camera.h"

Master_Renderer :: Master_Renderer()
:   m_renderer ( m_shader )
{

}


void Master_Renderer :: render ( const Light& light, const Camera& camera )
{
    m_shader.start();
    m_shader.loadLight( light );
    m_shader.loadViewMatrix( camera );

    m_renderer.render( m_entities );

    m_shader.stop();
    m_entities.clear();
}

void Master_Renderer :: processEntity ( const Entity& entity )
{
    auto model = &entity.getModel();

    if ( m_entities.count( model ) ) {
        m_entities[model].push_back( entity );
    } else {
        std::vector<Entity> newBatch;
        newBatch.push_back( entity );
        m_entities[ model ] = newBatch;
    }
}
