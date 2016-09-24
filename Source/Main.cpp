

#include <SFML/Graphics.hpp>
#include "OpenGL/GLEW/glew.h"

#include "Render_Engine/Display_Manager.h"
#include "Render_Engine/Loader.h"
#include "Render_Engine/Renderer.h"
#include "Render_Engine/Raw_Model.h"

void checkForClose  ( sf::RenderWindow& window );
void clearWindow    ();

int main()
{
    Display_Manager::create();

    Loader      loader;
    Renderer    renderer;

    std::vector<GLfloat> vertices =
    {
        //Bottom Left Triangle
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,

        //Bottom right triangle
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    Raw_Model model = loader.loadToVAO( vertices );

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear();

        renderer.render( model );





        Display_Manager::update();
        Display_Manager::checkForClose();
    }


    return 0;
}


