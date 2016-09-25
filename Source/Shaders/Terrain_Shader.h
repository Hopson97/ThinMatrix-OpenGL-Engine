#ifndef TERRAIN_SHADER_H
#define TERRAIN_SHADER_H

#include "Shader_Program.h"

class Light;
class Camera;

class Terrain_Shader : public Shader_Program
{
    public:
        Terrain_Shader();

        void loadTransformationMatrix   ( const Matrix4& matrix ) const;
        void loadViewMatrix             ( const Camera&  camera ) const;
        void loadProjectionMatrix       ( const Matrix4& matrix ) const;

        void loadLight                  ( const Light& light ) const;

        void loadShineVariables         ( float damper, float reflectivness );

    protected:
        void bindAttributes         () override;
        void getAllUniformLocations () override;

    private:
        GLuint locationTransformMatrix;
        GLuint locationProjectionMatrix;
        GLuint locationViewMatrix;

        GLuint locationLightPosition;
        GLuint locationLightColour;

        GLuint locationShineDamper;
        GLuint locationReflectivness;

        const std::string m_vertexFile      = "Data/Shaders/Vertex.glsl";
        const std::string m_fragmentFile    = "Data/Shaders/Fragment.glsl";
};

#endif // TERRAIN_SHADER_H
