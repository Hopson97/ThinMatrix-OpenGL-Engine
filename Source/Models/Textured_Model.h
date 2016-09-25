#ifndef TEXTURED_MODEL_H
#define TEXTURED_MODEL_H

class Raw_Model;
class Model_Texture;

class Textured_Model
{
    public:
        Textured_Model( Raw_Model& model, Model_Texture& texture );

        const Raw_Model&        getRawModel () const;
        const Model_Texture&    getTexture  () const;

    private:
        Raw_Model*       m_rawModel;
        Model_Texture*   m_modelTexture;
};

#endif // TEXTURED_MODEL_H
