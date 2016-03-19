/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
/* Imported modules */
/*Exported module */
#include "audio.h"


void load_gameplay_audio() {
    SMPL_gameplay_music = al_load_sample("data/audio/Clearside - Assimilator.wav");
    SMPL_friendly_shot = al_load_sample("data/audio/friendly_shot.wav");
    SMPL_hostile_shot = al_load_sample("data/audio/hostile_shot.wav");
    SMPL_explosion = al_load_sample("data/audio/explosion.wav");
}

void clear_gameplay_audio() {
    al_destroy_sample(SMPL_gameplay_music);
    al_destroy_sample(SMPL_friendly_shot);
    al_destroy_sample(SMPL_hostile_shot);
    al_destroy_sample(SMPL_explosion);
}

void load_menu_audio() {
    SMPL_menu_music = al_load_sample("data/audio/Clearside - Assimilator.wav");
}

void clear_menu_audio() {
    al_destroy_sample(SMPL_menu_music);
}
