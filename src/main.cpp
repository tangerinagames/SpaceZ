#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

#define WIDTH 640
#define HEIGHT 480
#define FPS 60

int main(int argc, char **argv) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_BITMAP *bg = NULL;

    bool redraw = false;

    al_init();
    al_install_keyboard();
    al_init_image_addon();

    display = al_create_display(WIDTH, HEIGHT);
    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();

    bg = al_load_bitmap("res/images/earth.jpg");
    int bg_width = al_get_bitmap_width(bg);
    int bg_height = al_get_bitmap_height(bg);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    while (1) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_scaled_bitmap(bg, 0, 0, bg_width, bg_height, 0, 0, WIDTH, HEIGHT, 0);
            al_flip_display();
        }
    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(bg);

    return 0;
}
