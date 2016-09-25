#include <iostream>

#include <SFML/Graphics.hpp>
#include "OpenGL/GLEW/glew.h"

#include "Render_Engine/Display_Manager.h"
#include "Render_Engine/Loader.h"
#include "Master_Renderer.h"

#include "FPS.h"

#include "Shaders/Static_Shader.h"

#include "Models/Raw_Model.h"
#include "Models/Textured_Model.h"

#include "Model_Texture.h"

#include "Terrain.h"
#include "Terrain_Render.h"
#include "Terrain_Shader.h"

#include "Entity.h"
#include "Camera.h"
#include "Light.h"

#include "Random.h"

#include "OBJLoader.h"

void checkForClose  ( sf::RenderWindow& window );
void clearWindow    ();

int main()
{
    Display_Manager::create();

    Loader          loader;



    Raw_Model       dragonModelRaw = OBJ_Loader::loadModel( "dragon", loader );
    Model_Texture   dragonTexture   ( loader.loadTexture( "grass" ), 10, 1 );
    Textured_Model  dragonModel     ( dragonModelRaw, dragonTexture );
    Entity dragon ( dragonModel );

    Terrain terrain     ( 0, -1, loader, dragonTexture );
    Terrain terrain2    ( 1, -1, loader, dragonTexture );

    Light light ( { 1.0f, 100.0f, 50.0f }, { 1, 1, 1 } );
    Camera camera;
    Master_Renderer renderer;

    FPS fps;

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear( 0.3, 0.13, 0.7 );

        renderer.processTerrain ( terrain  );
        renderer.processTerrain ( terrain2 );

        renderer.processEntity( dragon );


        renderer.render( light, camera );

        camera.move();

        fps.update();

        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


