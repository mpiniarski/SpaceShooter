/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
/* Imported modules */
#include "main.h"
/*Exported module */
#include "bitmaps.h"


void load_gameplay_bitmaps() {
    BTMP_background1 = al_load_bitmap("data/img/background1.jpg");
    BTMP_background2 = al_load_bitmap("data/img/background2.jpg");
    BTMP_background3 = al_load_bitmap("data/img/background3.jpg");
    BTMP_player = al_load_bitmap("data/img/player.png");
    BTMP_enemy_flyer = al_load_bitmap("data/img/enemy_flyer.png");
    BTMP_enemy_shooter = al_load_bitmap("data/img/enemy_shooter.png");
    BTMP_friendly_shot = al_load_bitmap("data/img/friendly_shot.png");
    BTMP_hostile_shot = al_load_bitmap("data/img/hostile_shot.png");
    BTMP_explosion1 = al_load_bitmap("data/img/explosion1.png");
    BTMP_explosion2 = al_load_bitmap("data/img/explosion2.png");
    BTMP_explosion3 = al_load_bitmap("data/img/explosion3.png");
    BTMP_flame = al_load_bitmap("data/img/flame.png");

    if ( !BTMP_background1 ||     !BTMP_background2 ||     !BTMP_background3 ||
            !BTMP_player ||     !BTMP_enemy_flyer ||     !BTMP_enemy_shooter ||
            !BTMP_friendly_shot ||     !BTMP_hostile_shot ||
            !BTMP_explosion1 ||     !BTMP_explosion2 ||     !BTMP_explosion3 ||
            !BTMP_flame)  {
        al_show_native_message_box(display.view, "Error", "Error", "Could not load bitmap.", NULL,
                                   ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
}

void clear_gameplay_bitmaps() {
    al_destroy_bitmap(BTMP_background1);
    al_destroy_bitmap(BTMP_background2);
    al_destroy_bitmap(BTMP_background3);
    al_destroy_bitmap(BTMP_player);
    al_destroy_bitmap(BTMP_enemy_flyer);
    al_destroy_bitmap(BTMP_enemy_shooter);
    al_destroy_bitmap(BTMP_friendly_shot);
    al_destroy_bitmap(BTMP_hostile_shot);
    al_destroy_bitmap(BTMP_explosion1);
    al_destroy_bitmap(BTMP_explosion2);
    al_destroy_bitmap(BTMP_explosion3);
    al_destroy_bitmap(BTMP_flame);
}

void load_menu_bitmaps() {
    BTMP_menu_background = al_load_bitmap("data/img/menu_background.png");

    if ( !BTMP_menu_background ) {
        al_show_native_message_box(display.view, "Error", "Error", "Could not load bitmap.", NULL,
                                   ALLEGRO_MESSAGEBOX_ERROR);
        return;
    }
}

void clear_menu_bitmaps() {
    al_destroy_bitmap(BTMP_menu_background);
}
