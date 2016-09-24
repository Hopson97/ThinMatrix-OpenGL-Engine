

#include <SFML/Graphics.hpp>
#include "OpenGL/GLEW/glew.h"

#include "Render_Engine/Display_Manager.h"
#include "Render_Engine/Loader.h"
#include "Render_Engine/Renderer.h"

#include "Shaders/Static_Shader.h"

#include "Models/Raw_Model.h"
#include "Models/Textured_Model.h"

#include "Model_Texture.h"

void checkForClose  ( sf::RenderWindow& window );
void clearWindow    ();

int main()
{
    Display_Manager::create();

    Loader          loader;
    Renderer        renderer;
    Static_Shader   shader;

    std::vector<GLfloat> vertices =
    {
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };

    std::vector<GLuint> indices =
    {
        0, 1, 3,
        3, 1, 2
    };

    std::vector<GLfloat> texture =
    {
        0, 0,
        0, 1,
        1, 1,
        1, 0
    };

    Raw_Model model = loader.loadToVAO( vertices, indices, texture );

    Model_Texture modelTexture ( loader.loadTexture( "cow" ) );
    Textured_Model textureModel ( model, modelTexture );

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear();

        shader.start();
        renderer.render( textureModel );
        shader.stop();




        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


