#include "OBJLoader.h"

#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

#include "Loader.h"
#include "../OpenGL/GLM/glm_transformations.h"
#include "../OpenGL/GLEW/glew.h"

typedef std::array<GLfloat, 3> vector3f;
typedef std::array<float, 2> vector2f;
typedef std::array<std::string, 3> faceArray;

namespace OBJ_Loader
{
    /*
    void split ( const std::string &s, char delim, std::vector<std::string> &elems )
    {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    std::vector<std::string> split ( const std::string &s, char delim )
    {
        std::vector<std::string> elems;
        split( s, delim, elems );
        return elems;
    }

    void processVertex ( const  std::vector<std::string>&   vertexData,
                         const  std::vector<Vector3> &      normals,
                         const  std::vector<Vector2> &      textures,
                                std::vector<GLuint>  &      indices,
                                std::vector<GLfloat> &      textureArray,
                                std::vector<GLfloat> &      normalArray )
    {
        GLuint currentVertexPointer = std::stoi ( vertexData.at( 0 ) ) - 1;
        indices.push_back( currentVertexPointer );

        Vector2 currentTexture = textures.at( std::stoi ( vertexData.at( 1 ) ) - 1 );
        textureArray[currentVertexPointer * 2 ]     = currentTexture.x;
        textureArray[currentVertexPointer * 2 + 1 ] = 1 - currentTexture.y;

        Vector3 currentNorm = normals.at( std::stoi ( vertexData.at( 2 ) ) - 1 );
        normalArray[currentVertexPointer * 3 ]      = currentNorm.x;
        normalArray[currentVertexPointer * 3 + 1 ]  = currentNorm.y;
        normalArray[currentVertexPointer * 3 + 2 ]  = currentNorm.z;
    }

    Raw_Model loadModel(const std::string fileName, Loader& loader)
    {
        std::ifstream inFile ( "Data/Models/" + fileName + ".obj");

        if ( !inFile.is_open() ) {
            throw std::runtime_error ( "Could not open model file " + fileName + ".obj!" );
        }

        std::vector<Vector3>    vertices;
        std::vector<Vector3>    normals;
        std::vector<Vector2>    textures;
        std::vector<GLuint>     indices;

        std::vector<GLfloat> vertexArray;
        std::vector<GLfloat> normalArray;
        std::vector<GLfloat> textureArray;

        std::string line;
        while ( std::getline( inFile, line ) ) {
            std::vector<std::string> splitline = split( line, ' ');

            if ( splitline.at( 0 ) == "v" ) {
                Vector3 vertex;
                vertex.x = std::stof ( splitline.at( 1 ) );
                vertex.y = std::stof ( splitline.at( 2 ) );
                vertex.z = std::stof ( splitline.at( 3 ) );
                vertices.push_back( vertex );
            }
            else if ( splitline.at( 0 ) == "vt" ) {
                Vector2 texture;
                texture.x = std::stof ( splitline.at( 1 ) );
                texture.y = std::stof ( splitline.at( 2 ) );
                textures.push_back( texture );
            }
            else if ( splitline.at( 0 ) == "vn" ) {
                Vector3 normal;
                normal.x = std::stof ( splitline.at( 1 ) );
                normal.y = std::stof ( splitline.at( 2 ) );
                normal.z = std::stof ( splitline.at( 3 ) );
                normals.push_back( normal );
            }
            else if ( splitline.at( 0 ) == "f" ) {
                normalArray = std::vector<GLfloat>  ( normals.size() * 3 );
                textureArray = std::vector<GLfloat> ( textures.size() * 2 );
                break;
            }
        }

        while ( true ) {
            std::vector<std::string> splitline = split( line, ' ');
            for ( auto& word : splitline) {
                std::cout << word << " ";
            }
            std::cout << "\n";

            std::vector<std::string> vertex1 = split( splitline.at( 1 ), '/');
            std::vector<std::string> vertex2 = split( splitline.at( 2 ), '/');
            std::vector<std::string> vertex3 = split( splitline.at( 3 ), '/');

            processVertex( vertex1, normals, textures, indices, textureArray, normalArray );
            processVertex( vertex2, normals, textures, indices, textureArray, normalArray );
            processVertex( vertex3, normals, textures, indices, textureArray, normalArray );

            if (!std::getline( inFile, line ) ) {
                break;
            }
        }
        inFile.close();

        vertexArray = std::vector<GLfloat>( vertices.size() * 3 );

        int p = 0;
        for ( auto& vertex : vertices ) {
            vertexArray[p++] = vertex.x;
            vertexArray[p++] = vertex.y;
            vertexArray[p++] = vertex.z;
        }



        return loader.loadToVAO( vertexArray, indices, textureArray );
    }
    */

    //The code below this comment was not written by me, so all credit goes to github use Ruixel
template<typename T>
void insertIntoFloatVector(std::vector<T>* vec, std::istringstream* ss,
                                      size_t arraySize)
 {
    std::array<std::string, 3> x;
    ss->seekg(2);

    if (arraySize == 2)
        *ss >> x[0] >> x[1];
    else
        *ss >> x[0] >> x[1] >> x[2];

    T tArray;
    for(size_t i = 0; i<arraySize; i++)
        tArray[i] = stof(x[i]);
    vec->push_back(tArray);

}

void insertIntoStringVector(std::vector<std::string>* vec, std::istringstream* ss)
{
    std::array<std::string, 3> x;
    ss->seekg(2);

    *ss >> x[0] >> x[1] >> x[2];

    for(int i = 0; i<3; i++)
        vec->push_back(x[i]);
}

Raw_Model loadModel(const std::string& fileName, Loader& loader)
{
    // OBJ File Vectors
    std::vector<vector3f> vertices, normals;
    std::vector<vector2f> textureCoordinates;
    std::vector<std::string> faces;

    // VBO Arrays
    std::vector<GLfloat> a_vertices, a_texCoords, a_normals;
    std::vector<GLuint>  a_indices;

    // File Buffer Objects
    std::ifstream objFile;
    std::stringstream obj;
    objFile.exceptions( std::ifstream::badbit );

    // Attempt to read file, if error occurs it returns a nullptr
    try{
        objFile.open("Data/Models/" + fileName + ".obj");
        obj << objFile.rdbuf();
        objFile.close();

    } catch (std::ios_base::failure e) {
        //cout << "Error loading " << fileName << endl;
        //return nullptr;
    }

    // Read the buffer and place into separate vectors to process later
    std::string line;
    while (std::getline(obj, line))
    {
        std::istringstream ss(line);

        if (ss.peek() == 'v')
        {
            ss.seekg(1);

            // Vertex
            if (ss.peek() == ' ')
                insertIntoFloatVector(&vertices, &ss, 3);
            else if (ss.peek() == 't')
                insertIntoFloatVector(&textureCoordinates, &ss, 2);
            else if (ss.peek() == 'n')
                insertIntoFloatVector(&normals, &ss, 3);
        }

        if (ss.peek() == 'f')
            insertIntoStringVector(&faces, &ss);
    }

    // From vector<array>s into single <arrays>
    faceArray a;
    GLfloat glf[3];
    int pointAt, indexCount = 0;
    std::string str;
    for (auto& i : faces)
    {
        std::istringstream ss(i);

        pointAt = 0;
        while (getline(ss, str, '/')) {
                glf[pointAt] = stoi(str);
                pointAt++;
        }

        //cout << vertices.at(glf[pointAt]-1).at(0) << endl;
        //cout << textureCoordinates.at(glf[1]-1).at(v) << endl;

        // VBO
        for (int v = 0; v < 3; v++)
            a_vertices.push_back(vertices.at(glf[0]-1).at(v));

        for (int v = 0; v < 2; v++)
            a_texCoords.push_back(textureCoordinates.at(glf[1]-1).at(v));

        for (int v = 0; v < 3; v++)
            a_normals.push_back(normals.at(glf[2]-1).at(v));

        for (int v = 0; v < 3; v++) {
            a_indices.push_back(indexCount);
            indexCount++;
        }

    }

    return loader.loadToVAO( a_vertices, a_indices, a_texCoords );
}

}










































