#ifndef __SHIP_H__
#define __SHIP_H__

#include <allegro5/allegro.h>
#define SPRITES 3

class Ship {
private:
    ALLEGRO_BITMAP *sprites[SPRITES];
    int current_sprite;
    int x, y;
public:
    Ship();
    void draw();
    void move(int x, int y);
    void left();
    void right();
    void center();
};

#endif
 