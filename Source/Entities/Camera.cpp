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
}

const Vector3& Camera :: getPosition() const
{
    return m_position;
}

const Vector3& Camera :: getRotation() const
{
    return m_rotation;
}
