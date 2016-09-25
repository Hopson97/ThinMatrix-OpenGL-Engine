

#include <SFML/Graphics.hpp>
#include "OpenGL/GLEW/glew.h"

#include "Render_Engine/Display_Manager.h"
#include "Render_Engine/Loader.h"
#include "Render_Engine/Renderer.h"

#include "Shaders/Static_Shader.h"

#include "Models/Raw_Model.h"
#include "Models/Textured_Model.h"

#include "Model_Texture.h"

#include "Entity.h"
#include "Camera.h"
#include "Light.h"

#include "OBJLoader.h"

void checkForClose  ( sf::RenderWindow& window );
void clearWindow    ();

int main()
{
    Display_Manager::create();

    Loader          loader;
    Static_Shader   shader;

    Renderer        renderer ( shader );

    //Raw_Model model = loader.loadToVAO( vertices, indices, texture );
    Raw_Model       stallModelRaw = OBJ_Loader::loadModel( "stall", loader );
    Model_Texture   stallTexture    ( loader.loadTexture( "stall" ) );
    Textured_Model  stallModel      ( stallModelRaw, stallTexture );
    Entity          stall           ( stallModel, { -5, -4, -10 } );


    Raw_Model       dragonModelRaw = OBJ_Loader::loadModel( "dragon", loader );
    Model_Texture   dragonTexture   ( loader.loadTexture( "cow" ) );
    Textured_Model  dragonModel     ( dragonModelRaw, dragonTexture );
    Entity          dragon          ( dragonModel, { 10, -5, -10 }, { 0, 0, 0 }, { 3, 3, 3 } );

    Light light ( { 1.0f, 1.0f, -5.0f }, { 1, 1, 1 } );

    Camera camera;

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear( 0.3, 0.13, 0.7 );

        stall.rotate( { 0, 0.1, 0 } );
        camera.move();

        shader.start();
        shader.loadViewMatrix( camera );
        shader.loadLight( light );

        renderer.render ( stall, shader );
        renderer.render ( dragon, shader );
        shader.stop();




        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


