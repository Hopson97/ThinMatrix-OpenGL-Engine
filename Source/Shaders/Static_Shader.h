#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#include "Shader_Program.h"

class Camera;

class Static_Shader : public Shader_Program
{
    public:
        Static_Shader();

        void loadTransformationMatrix   ( const Matrix4& matrix );
        void loadViewMatrix             ( const Camera&  camera );
        void loadProjectionMatrix       ( const Matrix4& matrix );

    protected:
        void bindAttributes         () override;
        void getAllUniformLocations () override;

    private:
        GLuint locationTransformMatrix;
        GLuint locationProjectionMatrix;
        GLuint locationViewMatrix;

        const std::string m_vertexFile      = "Data/Shaders/Vertex.glsl";
        const std::string m_fragmentFile    = "Data/Shaders/Fragment.glsl";
};

#endif // STATIC_SHADER_H
