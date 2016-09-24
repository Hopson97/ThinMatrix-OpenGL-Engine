#ifndef STATIC_SHADER_H
#define STATIC_SHADER_H

#include "Shader_Program.h"

class Static_Shader : public Shader_Program
{
    public:
        Static_Shader();

    protected:
        void bindAttributes ();

    private:
        const std::string m_vertexFile      = "Data/Shaders/Vertex.glsl";
        const std::string m_fragmentFile    = "Data/Shaders/Fragment.glsl";
};

#endif // STATIC_SHADER_H
