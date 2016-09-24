

#include <SFML/Graphics.hpp>
#include "OpenGL/GLEW/glew.h"

#include "Render_Engine/Display_Manager.h"
#include "Render_Engine/Loader.h"
#include "Render_Engine/Renderer.h"
#include "Render_Engine/Raw_Model.h"
#include "Shaders/Static_Shader.h"

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

    Raw_Model model = loader.loadToVAO( vertices, indices );

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear();

        shader.start();
        renderer.render( model );
        shader.stop();




        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


