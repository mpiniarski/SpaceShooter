/* Libraries */
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <stdio.h>
/* Imported modules */
#include "main.h"
#include "list.h"
#include "clock.h"
#include "bitmaps.h"
#include "texts.h"
#include "audio.h"
/*Exported module */
#include "gameplay_func.h"

// Funkcja REKURENCYJNIE wyjświetlająca na ekranie każdy element listy view_list
void show_view_list( struct obj_list *tmp ) {
    if (tmp){
        show_view_list(tmp->Next);
        if (tmp->Val->img) al_draw_bitmap(tmp->Val->img, tmp->Val->x, tmp->Val->y, 0);
    }
}

//Funkcja obsługująca efekt "rozjaśnienia" na początku każdego poziomu
bool Change_lvl;
void fade() {
    static int alpha = 255;
    ALLEGRO_BITMAP *Fade;
    Fade = al_create_bitmap(display.width, display.height);
    al_set_target_bitmap(Fade);
    al_clear_to_color(al_map_rgba(0,0,0, (unsigned char) alpha));
    al_set_target_bitmap(al_get_backbuffer(display.view));
    al_draw_bitmap(Fade,0,0,0);
    alpha-=3;
    if (alpha <= 0 ) { alpha = 255; Change_lvl = false;}
    al_destroy_bitmap(Fade);
}

//Funkcja wyświetla napisy w gameplay
void show_gameplay_texts() {
    char lvl[2]; sprintf(lvl, "%d", LEVEL);
    char level[] = "LEVEL ";
    strcat(level,lvl);
    al_draw_text(gameplay_title_font, al_map_rgb(255, 255, 255),
                 130 , 20, ALLEGRO_ALIGN_CENTRE,
                 "SPACE SHOOTER");
    al_draw_text(gameplay_level_font_1, al_map_rgb(255, 255, 255),
                 130 , 45, ALLEGRO_ALIGN_CENTRE,
                 level);
    al_draw_text(gameplay_timer_font, al_map_rgb(255, 255, 255),
                 130 , 80, ALLEGRO_ALIGN_CENTRE,
                 get_clock_string(Level_clock) );

    char pts[10]=""; sprintf(pts, "%d", POINTS*10);

    al_draw_text(gameplay_points_font, al_map_rgb(255, 40, 40),
                 display.width/2  , 30, ALLEGRO_ALIGN_CENTRE,
                 pts);
    if (Change_lvl) {
        al_draw_text(gameplay_level_font_2, al_map_rgb(255, 40, 40),
                     display.width / 2, display.height / 2, ALLEGRO_ALIGN_CENTRE,
                     level);
    }
}

void show_gameplay() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(BTMP_background,0,0,1600,900,0,0,display.width,display.height,0);
    if (Change_lvl) fade();
    show_view_list(view_list);
    show_gameplay_texts();
    al_flip_display();
    return;
}

struct object *spawn_player() {
    struct object *Player = NULL;
    Player = malloc(sizeof(struct object));
    Player->img = BTMP_player;
    Player->width = al_get_bitmap_width(Player->img);
    Player->height = al_get_bitmap_height(Player->img);
    Player->x = display.width / 2;
    Player->y = display.height / 2;
    Player->dx = 6;
    Player->dy = 4;
    Player->attitude = FRIENDLY;
    Player->ENEMY_TYPE = -1;
    Player->x_ignore = 100;
    Player->y_ignore = 30;
    add_to_list(&view_list, Player);
    Flame1 = spawn_flame();
    Flame2 = spawn_flame();
    Flame2->animation_state=3;
    return Player;
}

struct object *spawn_flame() {
    struct object *Flame = NULL;
    Flame = malloc(sizeof(struct object));
    Flame->width = 120;
    Flame->height = 60;
    Flame->animation_state = 0;
    Flame->img = al_create_sub_bitmap(BTMP_flame,
                                       0,Flame->animation_state*Flame->height,
                                       Flame->width,Flame->height);
    add_to_list(&view_list, Flame);
    return Flame;
}

void spawn_shot(struct object *Shooter, int Shot_type) {
    struct object *Shot = NULL;
    Shot = malloc(sizeof(struct object));
    Shot->ENEMY_TYPE = -1;
    if (Shot_type == FRIENDLY){
        Shot->img = BTMP_friendly_shot;
        Shot->width = al_get_bitmap_width(Shot->img);
        Shot->height = al_get_bitmap_height(Shot->img);
        Shot->x = Shooter->x + Shooter->width + 1;
        Shot->y = Shooter->y + Shooter->height / 2 - Shot->height / 2;
        Shot->dx = 8;
        Shot->attitude = FRIENDLY;
        Shot->x_ignore = 10;
        Shot->y_ignore = 30;
        al_play_sample(SMPL_friendly_shot, 0.5 *VOLUME/100, 0.0,1.1,ALLEGRO_PLAYMODE_ONCE,NULL);
    }
    else if (Shot_type == HOSTILE){
        Shot->img = BTMP_hostile_shot;
        Shot->width = al_get_bitmap_width(Shot->img);
        Shot->height = al_get_bitmap_height(Shot->img);
        Shot->x = Shooter->x - 1;
        Shot->y = Shooter->y + Shooter->height / 2 - Shot->height / 2;
        Shot->dx = -8;
        Shot->attitude = HOSTILE;
        Shot->x_ignore = 15;
        Shot->y_ignore = 50;
        al_play_sample(SMPL_hostile_shot, 1.0 *VOLUME/100, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
    }
    add_to_list(&shot_list, Shot);
    add_to_list(&view_list, Shot);
}

void spawn_enemies() {
    if ( check_with_main_clock(Flyer_respawn) ) spawn_enemy(FLYER);
    if ( check_with_main_clock(Shooter_respawn) ) spawn_enemy(SHOOTER);
}

void spawn_enemy(int Enemy_type) {
    struct object *Enemy = NULL;
    Enemy = malloc(sizeof(struct object));
    if (Enemy_type == FLYER){
        Enemy->img = BTMP_enemy_flyer;
        Enemy->width = al_get_bitmap_width(Enemy->img);
        Enemy->height = al_get_bitmap_height(Enemy->img);
        Enemy->x = display.width;
        Enemy->y = rand() % (display.height - Enemy->height);
        Enemy->dx = -4;
        Enemy->dy = 0;
        Enemy->attitude = HOSTILE;
        Enemy->ENEMY_TYPE=FLYER;
    }
    else if (Enemy_type == SHOOTER){
        Enemy->img = BTMP_enemy_shooter;
        Enemy->width = al_get_bitmap_width(Enemy->img);
        Enemy->height = al_get_bitmap_height(Enemy->img);
        Enemy->x = display.width;
        Enemy->y = rand() % (display.height - Enemy->height);
        Enemy->dx = -2;
        Enemy->dy = 0;
        Enemy->attitude = HOSTILE;
        Enemy->ENEMY_TYPE=SHOOTER;
        spawn_shot(Enemy, HOSTILE);
    }
    Enemy->x_ignore = 10;
    Enemy->y_ignore = 10;
    add_to_list(&view_list, Enemy);
    add_to_list(&enemy_list, Enemy);
}

void spawn_explosion(struct object *Destroyed) {
    struct object *Explosion = NULL;
    Explosion = malloc(sizeof(struct object));
    Explosion->width = 128;
    Explosion->height = 128 ;
    Explosion->animation_state = 0;
    int i = rand()%3;
    ALLEGRO_BITMAP *expl = NULL;
    if (i==0) expl = BTMP_explosion1;
    else if (i==1) expl = BTMP_explosion2;
    else if (i==2) expl = BTMP_explosion3;
    Explosion->img = al_create_sub_bitmap(expl,
                                          Explosion->animation_state*Explosion->width,0,
                                          Explosion->width,Explosion->height);
    Explosion->x = Destroyed->x-25;
    Explosion->y = Destroyed->y-10;
    Explosion->dx = 0;
    Explosion->dy = 0;
    Explosion->attitude = HOSTILE;
    Explosion->ENEMY_TYPE=-1;
    Explosion->x_ignore = 0;
    Explosion->y_ignore = 0;
    add_to_list(&view_list, Explosion);
    add_to_list(&explosion_list, Explosion);
    float speed = (rand()%6 + 10)/10;
    al_play_sample(SMPL_explosion, (float) (0.6 *VOLUME/100.0), 0.0, speed ,ALLEGRO_PLAYMODE_ONCE,NULL);
}

void move_player() {
    if (Key[UP] && Player->y >= Player->dy) { Player->y -= Player->dy; }
    if (Key[DOWN] && Player->y <= display.height - Player->height - Player->dy) { Player->y += Player->dy; }
    if (Key[LEFT] && Player->x >= Player->dx) { Player->x -= Player->dx; }
    if (Key[RIGHT] && Player->x <= display.width - Player->width - Player->dx) { Player->x += Player->dx; }
    Flame1->x=Player->x-90;
    Flame1->y=Player->y-15;
    Flame2->x=Player->x-90;
    Flame2->y=Player->y-40 + Player->height;
    if (Main_clock->tick % 5 == 0){
        Flame1->animation_state = (Flame1->animation_state+1)%9;//rand()%9;
        Flame2->animation_state = (Flame2->animation_state+1)%9;//rand()%9;
        al_destroy_bitmap(Flame1->img);
        al_destroy_bitmap(Flame2->img);
        Flame1->img = al_create_sub_bitmap(BTMP_flame,
                                           0,Flame1->animation_state*Flame1->height,
                                           Flame1->width,Flame1->height);
        Flame2->img = al_create_sub_bitmap(BTMP_flame,
                                           0,Flame2->animation_state*Flame2->height,
                                           Flame2->width,Flame2->height);
    }
}

void move_shoots() {
    struct obj_list *shoot_tmp = shot_list;
    while (shoot_tmp) {
        if (shoot_tmp->Val->x >= display.width && shoot_tmp->Val->x <= 0 - shoot_tmp->Val->width ) {
            struct object *del = shoot_tmp->Val;
            shoot_tmp = shoot_tmp->Next;
            delete_from_list(&view_list, del);
            delete_from_list(&shot_list, del);
            free(del);
        }
        else {
            shoot_tmp->Val->x += shoot_tmp->Val->dx;
            shoot_tmp = shoot_tmp->Next;
        }
    }
}

void move_enemies() {
    struct obj_list *enemy_tmp = enemy_list;
    while (enemy_tmp) {
        if (enemy_tmp->Val->x <= 0-enemy_tmp->Val->width) {
            struct object *del = enemy_tmp->Val;
            enemy_tmp = enemy_tmp->Next;
            delete_from_list(&view_list, del);
            delete_from_list(&enemy_list, del);
            free(del);
        }
        else {
            if (enemy_tmp->Val->ENEMY_TYPE == SHOOTER){
                if (rand()%200== 1) spawn_shot(enemy_tmp->Val, HOSTILE);
            }
            enemy_tmp->Val->x += enemy_tmp->Val->dx;
            enemy_tmp = enemy_tmp->Next;
        }
    }
}

void move_explosions() {
    struct obj_list *explosion_tmp = explosion_list;
    while (explosion_tmp) {
        if (explosion_tmp->Val->animation_state == 17) {
            struct object *del = explosion_tmp->Val;
            explosion_tmp= explosion_tmp->Next;
            delete_from_list(&view_list, del);
            delete_from_list(&explosion_list, del);
            al_destroy_bitmap(del->img);
            free(del);
        }
        else {
            explosion_tmp->Val->animation_state ++;
            ALLEGRO_BITMAP *expl = al_get_parent_bitmap(explosion_tmp->Val->img);
            al_destroy_bitmap(explosion_tmp->Val->img);
            explosion_tmp->Val->img = al_create_sub_bitmap(expl,
                                       explosion_tmp->Val->animation_state*explosion_tmp->Val->width,0,
                                       explosion_tmp->Val->width,explosion_tmp->Val->height);
            explosion_tmp = explosion_tmp->Next;
        }
    }
}

void level_handle() {
    switch (LEVEL){
        case 0:
            set_clock(&Level_clock,0,15,0);
            BTMP_background = BTMP_background1;
            set_clock(&Flyer_respawn,50,0,0);
            set_clock(&Shooter_respawn,0,0,0);
            Change_lvl = true;
            LEVEL++;
            break;
        case 1:
            if (check_clock_if_zero(Level_clock)){
                set_clock(&Level_clock,0,20,0);
                BTMP_background = BTMP_background2;
                set_clock(&Flyer_respawn,0,1,0);
                set_clock(&Shooter_respawn,0,2,0);
                Change_lvl = true;
                LEVEL++;
            }
            break;
        case 2:
            if (check_clock_if_zero(Level_clock)){
                set_clock(&Level_clock,0,30,0);
                BTMP_background = BTMP_background3;
                set_clock(&Flyer_respawn,40,0,0);
                set_clock(&Shooter_respawn,0,2,0);
                Change_lvl = true;
                LEVEL++;
            }
            break;
        case 3:
            if (check_clock_if_zero(Level_clock)){
                set_clock(&Level_clock,0,30,0);
                BTMP_background = BTMP_background1;
                set_clock(&Flyer_respawn,30,0,0);
                set_clock(&Shooter_respawn,30,1,0);
                Change_lvl = true;
                LEVEL++;
            }
            break;
        case 4:
            if (check_clock_if_zero(Level_clock)){
                set_clock(&Level_clock,0,40,0);
                BTMP_background = BTMP_background2;
                set_clock(&Flyer_respawn,20,0,0);
                set_clock(&Shooter_respawn,0,3,0);
                Change_lvl = true;
                LEVEL++;
            }
            break;
        case 5:
            if (check_clock_if_zero(Level_clock)){
                set_clock(&Level_clock,0,0,1);
                BTMP_background = BTMP_background3;
                set_clock(&Flyer_respawn,10,0,0);
                set_clock(&Shooter_respawn,0,3,0);
                Change_lvl = true;
                LEVEL++;
            }
            break;
        case 6:
            if (check_clock_if_zero(Level_clock)){
                LEVEL++;
            }
            break;
        default:
            Exit_gameplay = 1;
            GAME_MODE = MENU;
            break;
    }
}

