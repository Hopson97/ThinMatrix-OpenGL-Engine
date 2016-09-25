#ifndef TERRAIN_RENDER_H
#define TERRAIN_RENDER_H

#include <vector>

#include "Terrain_Shader.h"
#include "Terrain.h"

#include "Textured_Model.h"

class Terrain_Render
{
    public:
        Terrain_Render( Terrain_Shader& shader, const Matrix4& projectionMatrix );

        void render ( std::vector< const Terrain* >& terrains );

    private:
        void prepareTerrain     ( const Terrain& terrain );
        void unbindModel        ();
        void loadModelMatrix    ( const Terrain& terrain );


        Terrain_Shader* m_shader;
};

#endif // TERRAIN_RENDER_H
