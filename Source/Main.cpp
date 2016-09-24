

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
    Raw_Model model = OBJ_Loader::loadModel( "stall", loader );

    Model_Texture modelTexture ( loader.loadTexture( "stall" ) );
    Textured_Model textureModel ( model, modelTexture );

    Entity entity ( textureModel, { 0, -3, -25 } );

    Camera camera;

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear();

        entity.rotate( { 0, 1, 0 } );

        camera.move();

        shader.start();
        shader.loadViewMatrix( camera );


        renderer.render( entity, shader );
        shader.stop();




        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


