/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
/* Imported modules */
#include "main.h"
#include "menu_func.h"
#include "texts.h"
#include "bitmaps.h"
#include "audio.h"

/*Exported module */
#include "menu.h"

void menu() {
    bool Redraw = true;

    Exit_menu = false;
    Option = New_Game;

    load_menu_fonts();
    load_menu_bitmaps();
    load_menu_audio();
    //KOLEJKA EVENT

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(main_timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_play_sample(SMPL_menu_music, 0.6 *VOLUME/100, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    while (!Exit_menu) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (GAME_MODE == AFTER_GAMEPLAY){
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                Redraw = true;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                GAME_MODE=MENU;
            }

            if (Redraw && al_is_event_queue_empty(event_queue)) {
                Redraw = false;
                show_after_gameplay();
            }
        }
        else if (GAME_MODE == MENU){
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                Redraw = true;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch (ev.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                        Option = (Option + 1) % options_size;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        Option = (Option - 1);
                        if (Option < 0) Option = options_size - 1;
                        break;
                    case ALLEGRO_KEY_ENTER:
                        switch (Option) {
                            case New_Game:
                                GAME_MODE = GAMEPLAY;
                                Exit_menu = true;
                                break;
                            case Exit:
                                Exit_menu = true;
                                Exit_game = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

            if (Redraw && al_is_event_queue_empty(event_queue)) {
                Redraw = false;
                show_menu();
            }
        }
        }

    clear_menu_fonts();
    clear_menu_bitmaps();
    clear_menu_audio();
    al_destroy_event_queue(event_queue);
    return;
}

