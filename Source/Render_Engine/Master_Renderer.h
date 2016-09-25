#ifndef MASTER_RENDERER_H
#define MASTER_RENDERER_H

#include <vector>
#include <map>

#include "../OpenGL/GLEW/glew.h"

#include "Static_Shader.h"
#include "Entity_Renderer.h"
#include "Entity.h"

#include "Terrain_Render.h"
#include "Terrain_Shader.h"
#include "Terrain.h"

#include "Textured_Model.h"

class Light;
class Camera;

class Master_Renderer
{
    public:
        Master_Renderer();

        void render ( const Light& light, const Camera& camera );

        void processEntity ( const Entity& entity );
        void processTerrain ( const Terrain& terrian );

    private:
        Matrix4 getProjectionMatrix ();

        std::map< const Textured_Model*, std::vector< const Entity* > > m_entities;

        std::vector< const Terrain* > m_terrains;

        Matrix4 m_projectionMatrix;

        Static_Shader   m_shader;
        Entity_Renderer m_entityRenderer;

        Terrain_Render  m_terrainRenderer;
        Terrain_Shader  m_terrainShader;

        constexpr static float FOV          = 100;
        constexpr static float NEAR_PLANE   = 0.01;
        constexpr static float FAR_PLANE    = 1000;

};

#endif // MASTER_RENDERER_H
