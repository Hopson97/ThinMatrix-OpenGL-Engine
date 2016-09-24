#ifndef SHADER_LOADER_H_INCLUDED
#define SHADER_LOADER_H_INCLUDED

#include <string>

#include "../OpenGL/GLEW/glew.h"
#include "Shader_Program.h"


void  loadShader( const std::string& vertexFilePath,
                  const std::string& fragmentFilePath,
                  GLuint& id, GLuint& vertexId, GLuint& fragmentId );


#endif // SHADER_LOADER_H_INCLUDED
