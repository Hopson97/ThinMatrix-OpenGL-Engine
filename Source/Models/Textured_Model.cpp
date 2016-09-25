#include "Textured_Model.h"

#include "Raw_Model.h"
#include "Model_Texture.h"

Textured_Model :: Textured_Model( Raw_Model& model, Model_Texture& texture )
:   m_rawModel      ( &model )
,   m_modelTexture  ( &texture )
{ }

const Raw_Model& Textured_Model :: getRawModel () const
{
    return *m_rawModel;
}

const Model_Texture& Textured_Model :: getTexture () const
{
    return *m_modelTexture;
}
