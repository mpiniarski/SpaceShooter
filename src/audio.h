/* Moduł zawierający obsługę ładowania i usuwania dźwięków  */

#ifndef _AUDIO
#define _AUDIO

// Dźwięki wykorzystywane w grze:
    ALLEGRO_SAMPLE *SMPL_menu_music;

    ALLEGRO_SAMPLE *SMPL_gameplay_music;
    ALLEGRO_SAMPLE *SMPL_friendly_shot;
    ALLEGRO_SAMPLE *SMPL_hostile_shot;
    ALLEGRO_SAMPLE *SMPL_explosion;

// Funkcja ładująca dźwięki potrzebne w gameplay
void load_gameplay_audio();
// Funkcja usuwająca dźwięki potrzebne w gameplay
void clear_gameplay_audio();

// Funkcja ładująca dźwięki potrzebne w menu
void load_menu_audio();
// Funkcja usuwająca dźwięki potrzebne w menu
void clear_menu_audio();

#endif
