#include "Master_Renderer.h"

#include "Light.h"
#include "Camera.h"

#include "Display_Manager.h"

Master_Renderer :: Master_Renderer()
:   m_projectionMatrix  ( getProjectionMatrix() )
,   m_entityRenderer    ( m_shader,         m_projectionMatrix )
,   m_terrainRenderer   ( m_terrainShader,  m_projectionMatrix )
{ }


void Master_Renderer :: render ( const Light& light, const Camera& camera )
{
    m_shader.start();
    m_shader.loadLight( light );
    m_shader.loadViewMatrix( camera );
    m_entityRenderer.render( m_entities );
    m_shader.stop();

    m_terrainShader.start           ();
    m_terrainShader.loadLight       ( light );
    m_terrainShader.loadViewMatrix  ( camera );
    m_terrainRenderer.render( m_terrains );
    m_terrainShader.stop();

    m_entities.clear();
    m_terrains.clear();
}

void Master_Renderer :: processTerrain ( const Terrain& terrian )
{
    m_terrains.push_back( &terrian );
}



void Master_Renderer :: processEntity ( const Entity& entity )
{
    auto model = &entity.getModel();

    if ( m_entities.count( model ) ) {
        m_entities[model].push_back( &entity );
    } else {
        std::vector< const Entity* > newBatch;
        newBatch.push_back( &entity );
        m_entities[ model ] = newBatch;
    }
}

Matrix4 Master_Renderer :: getProjectionMatrix ()
{
    return glm::perspective( glm::radians( FOV ), (float)Display_Manager::WIDTH / Display_Manager::HEIGHT, NEAR_PLANE, FAR_PLANE );
}
