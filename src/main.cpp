#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char **argv) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *bg = NULL;

    al_init();
    al_init_image_addon();

    display = al_create_display(WIDTH, HEIGHT);

    bg = al_load_bitmap("res/images/earth.jpg");
    int bg_width = al_get_bitmap_width(bg);
    int bg_height = al_get_bitmap_height(bg);

    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_draw_scaled_bitmap(bg, 0, 0, bg_width, bg_height, 0, 0, WIDTH, HEIGHT, 0);

    al_flip_display();
    al_rest(20);

    al_destroy_display(display);
    al_destroy_bitmap(bg);

    return 0;
}
