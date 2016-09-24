#include "Entity.h"

#include "Textured_Model.h"

Entity :: Entity( const Textured_Model& model,  Vector3 position,
                                                Vector3 rotation,
                                                Vector3 scale    )
:   m_model ( model )
,   m_position ( position )
,   m_rotation ( rotation )
,   m_scale     ( scale )
{}


const Vector3& Entity :: getPosition() const
{
    return m_position;
}

const Vector3& Entity :: getRotation() const
{
    return m_rotation;
}

const Vector3& Entity :: getScale() const
{
    return m_scale;
}

const Textured_Model& Entity :: getModel() const
{
    return m_model;
}

void Entity :: move ( const Vector3& amount)
{
    m_position += amount;
}

void Entity :: rotate ( const Vector3& amount )
{
    m_rotation += amount;
}

void Entity :: scale ( const Vector3& amount )
{
    m_scale += amount;
}
