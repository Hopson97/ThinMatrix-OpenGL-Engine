#ifndef RENDERER_H
#define RENDERER_H


#include "../OpenGL/GLM/glm_transformations.h"

#include "Static_Shader.h"

#include <vector>
#include <map>

class Entity;
class Textured_Model;


class Renderer
{
    public:
        Renderer    ( Static_Shader& shader );

        void render ( const std::map< const Textured_Model*, std::vector<Entity>>& entities );

    private:
        void prepareModel      ( const Textured_Model& model );
        void unbindModel        ( const Textured_Model& model );
        void prepareInstance    ( const Entity& entity );

        constexpr static float FIELD_OF_VIEW = 90;
        constexpr static float NEAR_PLANE    = 0.01;
        constexpr static float FAR_PLANE     = 1000;

        Matrix4 projectionMatrix;

        Static_Shader* m_shader;
};

#endif // RENDERER_H
