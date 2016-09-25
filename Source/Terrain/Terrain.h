#ifndef TERRAIN_H
#define TERRAIN_H

#include "../OpenGL/GLEW/glew.h"

#include "Raw_Model.h"

class Loader;
class Model_Texture;

class Terrain
{
    public:
        Terrain( int gridX, int gridZ, Loader& loader, const Model_Texture& texture );

        const Raw_Model&        getModel    () const;
        const Model_Texture&    getTexture  () const;

        float getX () const;
        float getZ () const;

    private:
        Raw_Model generateTerrain ( Loader& loader );

        static constexpr float SIZE = 800;
        static constexpr float VERTEX_COUNT = 128;

        Raw_Model               m_model;
        const Model_Texture*    m_texture;

        float m_x;
        float m_z;
};

#endif // TERRAIN_H
