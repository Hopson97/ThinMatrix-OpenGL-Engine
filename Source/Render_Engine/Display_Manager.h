#ifndef DISPLAY_MANAGER_H_INCLUDED
#define DISPLAY_MANAGER_H_INCLUDED

namespace Display_Manager
{
    void create ();
    void clear  ();
    void update ();
    void close  ();
    bool isOpen ();

    void checkForClose ();

    constexpr static int WIDTH  = 1280,
                         HEIGHT = 720;
}

#endif // DISPLAY_MANAGER_H_INCLUDED
