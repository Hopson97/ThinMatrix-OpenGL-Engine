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



    Raw_Model       dragonModelRaw = OBJ_Loader::loadModel( "cube", loader );
    Model_Texture   dragonTexture   ( loader.loadTexture( "grass" ), 1, 1 );
    Textured_Model  dragonModel     ( dragonModelRaw, dragonTexture );

    Light light ( { 1.0f, 100.0f, 50.0f }, { 1, 1, 1 } );

    Camera camera;

    Master_Renderer renderer;

    FPS fps;

    float size = 25;
    std::vector<Entity> dragons;
    for ( int x = 0 ; x < size ; x++ ) {
        for ( int y = -size ; y < 0 ; y++ ) {
            for ( int z = -size ; z < 0 ; z++ ) {
                dragons.emplace_back ( dragonModel, Vector3{ x * 2, y * 2, z * 2 } );
            }
        }
    }
    std::cout << dragons.size() << std::endl;

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear( 0.3, 0.13, 0.7 );

        for ( auto& dragon : dragons ) {
            renderer.processEntity( dragon );
        }

        renderer.render( light, camera );

        camera.move();

        fps.update();

        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


