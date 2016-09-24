#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "../OpenGL/GLEW/glew.h"

#include <string>

class Shader_Program
{
    public:
        Shader_Program  ( const std::string& vertexFile, const std::string& fragmentString );
        Shader_Program  ( GLuint id, GLuint vertexId, GLuint fragmentId );

        ~Shader_Program ();

        void start  ();
        void stop   ();

    protected:
        virtual void bindAttributes () = 0;

        void bindAttribute          ( GLuint location, const std::string& name );

    private:
        GLuint m_id;
        GLuint m_vertexId;
        GLuint m_fragmentId;

};

#endif // SHADER_PROGRAM_H
