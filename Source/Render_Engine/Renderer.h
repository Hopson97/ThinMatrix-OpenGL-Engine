#ifndef RENDERER_H
#define RENDERER_H


#include "../OpenGL/GLM/glm_transformations.h"

class Entity;
class Static_Shader;

class Renderer
{
    public:
        Renderer    ( Static_Shader& shader );

        void render ( const Entity& entity, Static_Shader& shader );

    private:

        constexpr static float FIELD_OF_VIEW = 90;
        constexpr static float NEAR_PLANE    = 0.01;
        constexpr static float FAR_PLANE     = 1000;

        Matrix4 projectionMatrix;
};

#endif // RENDERER_H
