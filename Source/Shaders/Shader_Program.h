#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "../OpenGL/GLEW/glew.h"
#include "../OpenGL/GLM/glm_transformations.h"

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
        GLuint getUniformLocation ( const std::string& name ) const;

        virtual void bindAttributes         () = 0;
        virtual void getAllUniformLocations () = 0;

        void createProgram ();

        void loadBool       ( GLuint location, bool  value ) const;
        void loadFloat      ( GLuint location, float value ) const;
        void loadVector3    ( GLuint location, const Vector3& value  ) const;
        void loadMatrix4    ( GLuint location, const Matrix4& matrix ) const;

        void bindAttribute  ( GLuint location, const std::string& name ) const;

    private:
        GLuint m_id;
        GLuint m_vertexId;
        GLuint m_fragmentId;

};

#endif // SHADER_PROGRAM_H
