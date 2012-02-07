#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Ship.h"
#include "Galaxy.h"

#define WIDTH 640
#define HEIGHT 480
#define FPS 60

enum Keys { KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN };

int main(int argc, char **argv) {
    bool key[4] = {false, false, false, false};

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    bool doexit = false;
    bool redraw = false;

    al_init();
    al_install_keyboard();
    al_init_image_addon();
  
    display = al_create_display(WIDTH, HEIGHT);
    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();
  
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    Ship ship;
    Galaxy galaxy;

    while (!doexit) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
            if (key[KEY_UP]) ship.move(0, -4);
            if (key[KEY_DOWN]) ship.move(0, 4);
            if (key[KEY_LEFT]) {
                ship.move(-4, 0);
                ship.left();
            }
            if (key[KEY_RIGHT]) {
                ship.move(4, 0);
                ship.right();
            }
        } else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            doexit = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;
                case ALLEGRO_KEY_LEFT: 
                    key[KEY_LEFT] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
            }
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            ship.center();
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                   key[KEY_UP] = false;
                   break;
                case ALLEGRO_KEY_DOWN:
                   key[KEY_DOWN] = false;
                   break;
                case ALLEGRO_KEY_LEFT: 
                   key[KEY_LEFT] = false;
                   break;
                case ALLEGRO_KEY_RIGHT:
                   key[KEY_RIGHT] = false;
                   break;
                case ALLEGRO_KEY_ESCAPE:
                   doexit = true;
                   break;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            
            al_clear_to_color(al_map_rgb(0, 0, 0));
            galaxy.draw();
            ship.draw();
            al_flip_display();
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}
