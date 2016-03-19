/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/* Imported modules */
#include "main.h"
/*Exported module */
#include "texts.h"


void load_menu_fonts() {
    menu_title_font = al_load_ttf_font("data/fonts/dc_s.ttf", 80, 0);
    menu_option_font = al_load_ttf_font("data/fonts/AnyTakers-Regular.ttf", 75, 0);
    menu_credits_font = al_load_ttf_font("data/fonts/Shehroz khalid.ttf", 20, 0);
    if (!menu_title_font || !menu_option_font || !menu_credits_font) {
        al_show_native_message_box(display.view, "Error", "Error", "Could not load font.", NULL,
                                   ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
}


void clear_menu_fonts() {
    al_destroy_font(menu_title_font);
    al_destroy_font(menu_option_font);
    al_destroy_font(menu_credits_font);
}

void load_gameplay_fonts() {
    gameplay_title_font = al_load_ttf_font("data/fonts/dc_s.ttf", 25, 0);
    gameplay_level_font_1 = al_load_ttf_font("data/fonts/Iron&Brine.ttf", 30, 0);
    gameplay_timer_font = al_load_ttf_font("data/fonts/Shehroz khalid.ttf", 30, 0);
    gameplay_points_font = al_load_ttf_font("data/fonts/Iron&Brine.ttf", 40, 0);
    gameplay_level_font_2 = al_load_ttf_font("data/fonts/Iron&Brine.ttf", 50, 0);
    if (    !gameplay_title_font || !gameplay_level_font_1 || !gameplay_timer_font
            || !gameplay_points_font || !gameplay_level_font_2  ) {
        al_show_native_message_box(display.view, "Error", "Error", "Could not load font.", NULL,
                                   ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
}


void clear_gameplay_fonts() {
    al_destroy_font(gameplay_title_font);
    al_destroy_font(gameplay_level_font_1);
    al_destroy_font(gameplay_timer_font);
    al_destroy_font(gameplay_level_font_2);
}
