#ifndef MATHS_H
#define MATHS_H

#include <cmath>

#include "../OpenGL/GLM/glm_transformations.h"

#include "Camera.h"

namespace Maths
{
    Matrix4 createTransforrmationMatrix ( const Vector3& translation,
                                          const Vector3& rotation,
                                          const Vector3& scale );


    Matrix4 createViewMatrix ( const Camera& camera );


}

#endif // MATHS_H
