/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
/* Imported modules */
#include "main.h"
#include "list.h"
#include "clock.h"
#include "collision.h"
#include "gameplay_func.h"
#include "texts.h"
#include "audio.h"
#include "bitmaps.h"
/*Exported module */
#include "gameplay.h"

void gameplay() {
    Redraw = true;
    srand((unsigned int) time(NULL));
    Exit_gameplay = false;
    int i; for (i=0; i<keys_size; i++) Key[i]=0;

    load_gameplay_fonts();
    load_gameplay_bitmaps();
    load_gameplay_audio();
    create_clocks();
    reset_lists();

    //KOLEJKA EVENT
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(main_timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    Player = spawn_player();
    LEVEL = 0;
    POINTS = 0;
    al_play_sample(SMPL_gameplay_music, (float) (0.6 *VOLUME/100.00), 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    while (!Exit_gameplay) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER) {
            Redraw = true;

            level_handle();
            clock_tick(&Main_clock);
            clock_untick(&Level_clock);

            spawn_enemies();
            move_player();
            move_shoots();
            move_enemies();
            move_explosions();
            destroy_objects_in_collision();

        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    Key[UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    Key[DOWN] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    Key[LEFT] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    Key[RIGHT] = true;
                    break;
                case ALLEGRO_KEY_SPACE:
                    spawn_shot(Player,FRIENDLY);
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    Exit_gameplay = true;
                    Exit_game = true;
                    break;
                default:
                    break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    Key[UP] = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    Key[DOWN] = false;
                    break;
                case ALLEGRO_KEY_LEFT:
                    Key[LEFT] = false;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    Key[RIGHT] = false;
                    break;
                default:
                    break;
            }
        }

        if (Redraw && al_is_event_queue_empty(event_queue)) {
            Redraw = false;
            show_gameplay();
        }
    }
    clear_lists();
    clear_gameplay_fonts();
    clear_gameplay_bitmaps();
    clear_gameplay_audio();
    clear_clocks();
    al_destroy_event_queue(event_queue);
    return;
}

