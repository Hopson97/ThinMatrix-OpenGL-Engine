#include "Light.h"

Light :: Light ( const Vector3& position, const Vector3& colour )
:   m_position  ( position )
,   m_colour    ( colour)
{ }

const Vector3& Light :: getPosition () const
{
    return m_position;
}

const Vector3& Light :: getColour () const
{
    return m_colour;
}
