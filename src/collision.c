/* Libraries */
#include <allegro5/allegro.h>
/* Imported modules */
#include "list.h"
#include "gameplay_func.h"
#include "main.h"
/*Exported module */
#include "collision.h"

// Funkcja usuwjąca obiekty o przeciwnym attitude będące w kolizji z Obj
bool collision(struct object *Obj1, struct object *Obj2) {
    if(Obj1->attitude != Obj2->attitude){
        int Obj1_v_middle = Obj1->x + Obj1->width/2;
        int Obj2_v_middle = Obj2->x + Obj2->width/2;
        int Obj1_h_middle = Obj1->y + Obj1->height/2;
        int Obj2_h_middle = Obj2->y + Obj2->height/2;

        if (abs(Obj1_v_middle - Obj2_v_middle) <= (Obj1->width -Obj1->x_ignore  +  Obj2->width - Obj2->x_ignore)/2
            && abs(Obj1_h_middle - Obj2_h_middle) <= (Obj1->height - Obj1->y_ignore  +  Obj2->height-Obj2->y_ignore)/2)
            return 1;
        else return 0;
    }
    else return 0;
}

// Funckja sprawdzająca czy dwa obiekty o przeciwnych attitude są w kolizji
bool destroy_oposite_if_collision(struct object *Obj) {
    struct obj_list *tmp = enemy_list;
    while(tmp) {
        if (collision(Obj, tmp->Val)){
            struct object *del = tmp->Val;
            spawn_explosion(del);
            delete_from_list(&view_list, del);
            delete_from_list(&enemy_list, del);
            if (del->ENEMY_TYPE==FLYER) POINTS++;
            else if (del->ENEMY_TYPE==SHOOTER)  POINTS+=2;
            free(del);
            return 1;
        }
        else {
            tmp = tmp->Next;
        }
    }
    if (Obj == Player){
        tmp = shot_list;
        while(tmp) {
            if (collision(Obj, tmp->Val)){
                struct object *del = tmp->Val;
                delete_from_list(&view_list, del);
                delete_from_list(&shot_list, del);
                free(del);
                return 1;
            }
            else {
                tmp = tmp->Next;
            }
        }
    }
    return 0;
}

void destroy_objects_in_collision() {
    struct obj_list *shoot_tmp = shot_list;
    while(shoot_tmp) {
        if ( destroy_oposite_if_collision(shoot_tmp->Val) ){
            struct object *del = shoot_tmp->Val;
            shoot_tmp = shoot_tmp->Next;
            delete_from_list(&view_list, del);
            delete_from_list(&shot_list, del);
            free(del);
        }
        else shoot_tmp = shoot_tmp->Next;
    }
    if ( destroy_oposite_if_collision(Player)){
        al_destroy_bitmap(Flame1->img);
        al_destroy_bitmap(Flame2->img);
        Exit_gameplay = true;
        GAME_MODE = AFTER_GAMEPLAY;
        Redraw = false;
    }
}

