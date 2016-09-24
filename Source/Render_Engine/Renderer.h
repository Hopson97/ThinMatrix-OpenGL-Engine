#ifndef RENDERER_H
#define RENDERER_H

#include "Textured_Model.h"

class Renderer
{
    public:
        void prepare ();

        void render ( const Textured_Model& model );

    protected:

    private:
};

#endif // RENDERER_H
