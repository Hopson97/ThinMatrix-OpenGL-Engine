#ifndef MASTER_RENDERER_H
#define MASTER_RENDERER_H

#include <vector>
#include <map>

#include "Static_Shader.h"
#include "Renderer.h"
#include "Entity.h"

#include "Textured_Model.h"

class Light;
class Camera;

class Master_Renderer
{
    public:
        Master_Renderer();

        void render ( const Light& light, const Camera& camera );

        void processEntity ( const Entity& entity );

    private:
        std::map< const Textured_Model*, std::vector<Entity>> m_entities;

        Static_Shader m_shader;
        Renderer      m_renderer;
};

#endif // MASTER_RENDERER_H
