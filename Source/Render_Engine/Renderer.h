#ifndef RENDERER_H
#define RENDERER_H

#include "Raw_Model.h"

class Renderer
{
    public:
        void prepare ();

        void render ( const Raw_Model& model );

    protected:

    private:
};

#endif // RENDERER_H
