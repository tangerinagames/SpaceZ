#include "Ship.h"

#define WIDTH 78
#define HEIGHT 72

#define for_in_sprites for (int i = 0; i < SPRITES; ++i)

Ship::Ship(): current_sprite(CENTER), x(100), y(100) {
    ALLEGRO_BITMAP *bitmap = al_load_bitmap("res/images/spaceship.png");
    
    for_in_sprites {
        sprites[i] = al_create_bitmap(WIDTH, HEIGHT);
        al_set_target_bitmap(sprites[i]);
        al_draw_bitmap_region(bitmap, i * WIDTH, 0, WIDTH, HEIGHT, 0, 0, 0);
        al_convert_mask_to_alpha(sprites[i], al_map_rgb(255, 0, 255));
    }
    
    al_destroy_bitmap(bitmap);
    al_set_target_backbuffer(al_get_current_display());
}

Ship::~Ship() {
    for_in_sprites {
        al_destroy_bitmap(sprites[i]);
    }
}

void Ship::draw() {
    al_draw_bitmap(sprites[current_sprite], x, y, 0); 
}

void Ship::move(int x, int y) {
    this->x += x;
    this->y += y;
}

void Ship::left() {
    current_sprite = LEFT;
}

void Ship::right() {
    current_sprite = RIGHT;
}

void Ship::center() {
    current_sprite = CENTER;
}
