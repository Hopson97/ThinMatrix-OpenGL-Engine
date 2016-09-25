#ifndef ENTITY_H
#define ENTITY_H

#include "../OpenGL/GLEW/glew.h"
#include "../OpenGL/GLM/glm_transformations.h"

class Textured_Model;

class Entity
{
    public:
        Entity( const Textured_Model& model, Vector3 position = { 0, 0, 0 },
                                             Vector3 rotation = { 0, 0, 0 },
                                             Vector3 scale    = { 1, 1, 1 } );

        const Vector3& getPosition  () const;
        const Vector3& getRotation  () const;
        const Vector3& getScale     () const;

        const Textured_Model& getModel () const;

        void move   ( const Vector3& amount );
        void rotate ( const Vector3& amount );
        void scale  ( const Vector3& amount );

    private:
        const Textured_Model* m_model;

        Vector3 m_position;
        Vector3 m_rotation;
        Vector3 m_scale;
};

#endif // ENTITY_H
