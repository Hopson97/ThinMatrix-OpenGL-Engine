#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>

#include "Raw_Model.h"

class Loader;

namespace OBJ_Loader
{
    Raw_Model loadModel ( const std::string fileName, Loader& loader );
}

#endif // OBJLOADER_H
