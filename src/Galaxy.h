#ifndef __GALAXY_H__
#define __GALAXY_H__

#include <allegro5/allegro.h>
#include <list>

class Galaxy {
private:
    struct Star {
        ALLEGRO_COLOR color;
        float x, y;
        float velocity;
    };
    std::list<Star> stars;
    ALLEGRO_BITMAP *background;
    int display_width;
    void createNewStar();
public:
    Galaxy();
    ~Galaxy();
    void draw();    
};

#endif
 
