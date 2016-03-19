/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
/* Imported modules */
#include "main_func.h"
#include "menu.h"
#include "gameplay.h"
/*Exported module */
#include "main.h"

int main() {
    load_configuration_file();

    // ŁADOWANIE BIBLIOTEK
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(100);

    // WYŚWTIETLANIE EKRANU
    display.view = NULL;
//	al_get_display_mode(al_get_num_display_modes() -3, &disp_data);
//	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    display.view = al_create_display(display.width, display.height);

    // TIMER
    main_timer = NULL;
    main_timer = al_create_timer(1.0 / display.FPS);

    GAME_MODE = MENU;
    Exit_game = false;

    al_start_timer(main_timer);
    while (!Exit_game) {
        switch (GAME_MODE) {
            case MENU:
                menu();
                break;
            case GAMEPLAY:
                gameplay();
                break;
            case AFTER_GAMEPLAY:
                menu();
                break;
            default:
                break;
        }
    }

    al_destroy_display(display.view);
    al_destroy_timer(main_timer);


    return 111;
}
