#include "Camera.h"

#include <SFML/Graphics.hpp>

void Camera :: move ()
{
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
    {
        m_position.z -= 0.2;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        m_position.x += 0.2;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        m_position.x -= 0.2;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
    {
        m_position.z += 0.2;
    }

    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
    {
        m_rotation.y -= 5;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
    {
        m_rotation.y += 5;
    }

    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
    {
        m_rotation.x -= 5;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
    {
        m_rotation.x += 5;
    }

    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
    {
        m_position.y += 1;
    }
    if  ( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) )
    {
        m_position.y -= 1;
    }
}

const Vector3& Camera :: getPosition() const
{
    return m_position;
}

const Vector3& Camera :: getRotation() const
{
    return m_rotation;
}
