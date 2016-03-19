/* Moduł zawierający obsługę ładowania i usuwania bitmap */

#ifndef _BITMAPS
#define _BITMAPS

// Bitmapy wykorzystywane w grze:
    ALLEGRO_BITMAP *BTMP_menu_background;

    ALLEGRO_BITMAP *BTMP_background;
    ALLEGRO_BITMAP *BTMP_background1;
    ALLEGRO_BITMAP *BTMP_background2;
    ALLEGRO_BITMAP *BTMP_background3;
    ALLEGRO_BITMAP *BTMP_player;
    ALLEGRO_BITMAP *BTMP_enemy_flyer;
    ALLEGRO_BITMAP *BTMP_enemy_shooter;
    ALLEGRO_BITMAP *BTMP_friendly_shot;
    ALLEGRO_BITMAP *BTMP_hostile_shot;
    ALLEGRO_BITMAP *BTMP_explosion1;
    ALLEGRO_BITMAP *BTMP_explosion2;
    ALLEGRO_BITMAP *BTMP_explosion3;
    ALLEGRO_BITMAP *BTMP_flame;

// Funkcja ładująca bitmapy potrzebne w gameplay
void load_gameplay_bitmaps();
// Funkcja usuwająca bitmapy potrzebne w gameplay
void clear_gameplay_bitmaps();

// Funkcja ładująca bitmapy potrzebne w menu
void load_menu_bitmaps();
// Funkcja usuwająca bitmapy potrzebne w menu
void clear_menu_bitmaps();

#endif

