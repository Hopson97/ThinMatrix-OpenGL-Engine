#ifndef LIGHT_H
#define LIGHT_H

#include "../OpenGL/GLM/glm_transformations.h"

class Light
{
    public:
        Light( const Vector3& position, const Vector3& colour );


        const Vector3& getPosition() const;
        const Vector3& getColour  () const;

    private:
        Vector3 m_position;
        Vector3 m_colour;
};

#endif // LIGHT_H
