#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#include "Shader_Program.h"

class Light;
class Camera;

class Static_Shader : public Shader_Program
{
    public:
        Static_Shader();

        void loadTransformationMatrix   ( const Matrix4& matrix ) const;
        void loadViewMatrix             ( const Camera&  camera ) const;
        void loadProjectionMatrix       ( const Matrix4& matrix ) const;

        void loadLight                  ( const Light& light ) const;

    protected:
        void bindAttributes         () override;
        void getAllUniformLocations () override;

    private:
        GLuint locationTransformMatrix;
        GLuint locationProjectionMatrix;
        GLuint locationViewMatrix;

        GLuint locationLightPosition;
        GLuint locationLightColour;

        const std::string m_vertexFile      = "Data/Shaders/Vertex.glsl";
        const std::string m_fragmentFile    = "Data/Shaders/Fragment.glsl";
};

#endif // STATIC_SHADER_H
