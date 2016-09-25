#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"

class Camera
{
    public:
        void move ();

        const Vector3& getPosition () const;
        const Vector3& getRotation () const;

    private:
        Vector3 m_position = { 0, 1, 0 };
        Vector3 m_rotation;
};

#endif // CAMERA_H
