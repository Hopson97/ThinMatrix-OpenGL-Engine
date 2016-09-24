

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

void checkForClose  ( sf::RenderWindow& window );
void clearWindow    ();

int main()
{
    Display_Manager::create();

    Loader          loader;
    Static_Shader   shader;

    Renderer        renderer ( shader );

    std::vector<GLfloat> vertices =
    {
				-0.5f,0.5f,-0.5f,
				-0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,-0.5f,
				0.5f,0.5f,-0.5f,

				-0.5f,0.5f,0.5f,
				-0.5f,-0.5f,0.5f,
				0.5f,-0.5f,0.5f,
				0.5f,0.5f,0.5f,

				0.5f,0.5f,-0.5f,
				0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,0.5f,
				0.5f,0.5f,0.5f,

				-0.5f,0.5f,-0.5f,
				-0.5f,-0.5f,-0.5f,
				-0.5f,-0.5f,0.5f,
				-0.5f,0.5f,0.5f,

				-0.5f,0.5f,0.5f,
				-0.5f,0.5f,-0.5f,
				0.5f,0.5f,-0.5f,
				0.5f,0.5f,0.5f,

				-0.5f,-0.5f,0.5f,
				-0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,-0.5f,
				0.5f,-0.5f,0.5f
    };

    std::vector<GLuint> indices =
    {
				0,1,3,
				3,1,2,
				4,5,7,
				7,5,6,
				8,9,11,
				11,9,10,
				12,13,15,
				15,13,14,
				16,17,19,
				19,17,18,
				20,21,23,
				23,21,22
    };

    std::vector<GLfloat> texture =
    {
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0,
				0,0,
				0,1,
				1,1,
				1,0
    };

    Raw_Model model = loader.loadToVAO( vertices, indices, texture );

    Model_Texture modelTexture ( loader.loadTexture( "cow" ) );
    Textured_Model textureModel ( model, modelTexture );

    Entity entity ( textureModel, { 0, 0, -5 } );

    Camera camera;

    while ( Display_Manager::isOpen() ) {
        Display_Manager::clear();

        entity.rotate( { 0.05, 0.05, 0.05 } );

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


