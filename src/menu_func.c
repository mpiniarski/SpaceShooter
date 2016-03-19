/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
/* Imported modules */
#include "main.h"
#include "texts.h"
#include "bitmaps.h"
/*Exported module */
#include "menu_func.h"

void show_menu(){
    al_clear_to_color(al_map_rgb(0, 9, 1));
    al_draw_bitmap(BTMP_menu_background,0,0,0);
    al_draw_text(menu_title_font, al_map_rgb(255, 255, 255),
                 display.width / 2, display.height / 5, ALLEGRO_ALIGN_CENTRE,
                 "SPACE SHOOTER");

    switch (Option) {
        case New_Game:
            al_draw_text(menu_option_font, al_map_rgb(255, 40, 40),
                         display.width - display.width/3, display.height / 2, ALLEGRO_ALIGN_CENTRE,
                         "New Game");
            al_draw_text(menu_option_font, al_map_rgb(255, 255, 255),
                         display.width - display.width/3, display.height / 2 + 100, ALLEGRO_ALIGN_CENTRE,
                         "Exit");
            break;
        case Exit:
            al_draw_text(menu_option_font, al_map_rgb(255, 255, 255),
                         display.width - display.width/3, display.height / 2, ALLEGRO_ALIGN_CENTRE,
                         "New Game");
            al_draw_text(menu_option_font, al_map_rgb(255, 40, 40),
                         display.width - display.width/3, display.height / 2 + 100, ALLEGRO_ALIGN_CENTRE,
                         "Exit");
            break;
        default:
            break;
    }
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 display.width -150 , display.height -40 , ALLEGRO_ALIGN_CENTRE,
                 "made by Marcin Piniarski");

    al_flip_display();
}

void show_after_gameplay(){
    al_clear_to_color(al_map_rgb(0, 9, 1));
    al_draw_bitmap(BTMP_menu_background,0,0,0);
    al_draw_text(menu_title_font, al_map_rgb(255, 255, 255),
                 display.width / 2, display.height / 5, ALLEGRO_ALIGN_CENTRE,
                 "SPACE SHOOTER");
    al_draw_text(menu_option_font, al_map_rgb(255, 255, 255),
                 display.width - display.width/3, display.height / 2 -100, ALLEGRO_ALIGN_CENTRE,
                 "Your score");
    char pts[10]=""; sprintf(pts, "%d", POINTS*10);
    al_draw_text(menu_option_font, al_map_rgb(255, 40, 40),
                 display.width - display.width/3, display.height / 2 -50, ALLEGRO_ALIGN_CENTRE,
                 pts);

    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2 +40, ALLEGRO_ALIGN_CENTRE,
                 "Credits");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+25 +40, ALLEGRO_ALIGN_CENTRE,
                 "Author, Producer, Programmer: Marcin Piniarski");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+50 +40, ALLEGRO_ALIGN_CENTRE,
                 "2D Art: C-toy, dorkster, Rawdanitsu,");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+75 +40, ALLEGRO_ALIGN_CENTRE,
                 "MillionthVector (http://millionthvector.blogspot.de) ");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+100 +40, ALLEGRO_ALIGN_CENTRE,
                 "Includes graphics from JS WARS by Jonas Wagner - http://29a.ch/");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+125 +40, ALLEGRO_ALIGN_CENTRE,
                 "Backgrounds: Rawdanitsu, ac3raven");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+150 +40, ALLEGRO_ALIGN_CENTRE,
                 "Music: yd, clearside");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+175 +40, ALLEGRO_ALIGN_CENTRE,
                 "Sound effects: dklon, Michel Baradari");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 300 , display.height/2+210 +40, ALLEGRO_ALIGN_CENTRE,
                 "Special thanks for: Joanna Solomiewicz, Marcin Mrugas");
    al_draw_text(menu_credits_font, al_map_rgb(255, 255, 255),
                 display.width -150 , display.height -40 , ALLEGRO_ALIGN_CENTRE,
                 "made by Marcin Piniarski");
    al_flip_display();
}
