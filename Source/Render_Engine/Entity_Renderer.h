#ifndef RENDERER_H
#define RENDERER_H


#include "../OpenGL/GLM/glm_transformations.h"

#include "Static_Shader.h"

#include <vector>
#include <map>

class Entity;
class Textured_Model;


class Entity_Renderer
{
    public:
        Entity_Renderer ( Static_Shader& shader, const Matrix4& projectionMatrix );

        void render ( const std::map< const Textured_Model*, std::vector< const Entity* > >& entities );

    private:
        void prepareModel      ( const Textured_Model& model );
        void unbindModel        ( const Textured_Model& model );
        void prepareInstance    ( const Entity& entity );

        Static_Shader* m_shader;
};

#endif // RENDERER_H
