/* Moduł zawierający obsługę ładowania i usuwania cznionek  */

#ifndef _TEXTS
#define _TEXTS

// Czcionki wykorzystywane w grze:
    ALLEGRO_FONT *menu_title_font;
    ALLEGRO_FONT *menu_option_font;
    ALLEGRO_FONT *menu_credits_font;

    ALLEGRO_FONT *gameplay_title_font;
    ALLEGRO_FONT *gameplay_level_font_1;
    ALLEGRO_FONT *gameplay_timer_font;
    ALLEGRO_FONT *gameplay_points_font;
    ALLEGRO_FONT *gameplay_level_font_2;

// Funkcja ładująca czcionki potrzebne w gameplay
void load_menu_fonts();
// Funkcja usuwająca czcionki potrzebne w gameplay
void clear_menu_fonts();

// Funkcja ładująca czcionki potrzebne w menu
void load_gameplay_fonts();
// Funkcja usuwająca czcionki potrzebne w menu
void clear_gameplay_fonts();

#endif
