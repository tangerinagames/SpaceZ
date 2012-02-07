#include "Galaxy.h"
#include <cstdlib>

#define foreach(i, l) for 

Galaxy::Galaxy() {
    display_width = al_get_display_width(al_get_current_display());
    background = al_load_bitmap("res/images/space.png"); 
}

Galaxy::~Galaxy() {
    al_destroy_bitmap(background);
}

void Galaxy::createNewStar() {
    int x = rand() % display_width;
    int velocity = rand() % 9 + 1;
    Star new_star = { al_map_rgb(255, 255, 255), x, 0, velocity };
    stars.push_back(new_star);
}

void Galaxy::draw() {
    al_draw_bitmap(background, 0, 0, 0);
    for (std::list<Star>::iterator star = stars.begin(); star != stars.end(); star++) {
        star->y += star->velocity;
        if (star->y > display_width) {
            star = stars.erase(star);
        } else {
            al_draw_pixel(star->x, star->y, star->color);
        }
    }
    createNewStar();
}

