/* Libraries */
#include <allegro5/allegro.h>
#include <stdio.h>
/* Imported modules */
#include "main.h"
/*Exported module */
#include "clock.h"


struct clock *create_clock() {
    struct clock *tmp;
    tmp = malloc(sizeof(struct clock));
    tmp->tick = 0;
    tmp->sec = 0;
    tmp->min = 0;
    return tmp;
}

void create_clocks() {
    Main_clock=create_clock();
    Level_clock=create_clock();
    Flyer_respawn=create_clock();
    Shooter_respawn=create_clock();
}

void set_clock(struct clock **Clock, int tick, int sec, int min) {
    (*Clock)->tick = tick;
    (*Clock)->sec = sec;
    (*Clock)->min = min;
}

void clock_tick(struct clock **Clock){
    (*Clock)->tick ++;
    if ((*Clock)->tick == display.FPS) { (*Clock)->sec ++; (*Clock)->tick = 0;}
    if ((*Clock)->sec == 60) { (*Clock)->min++; (*Clock)->sec = 0;}
}

void clock_untick(struct clock **Clock) {
    (*Clock)->tick --;
    if ((*Clock)->tick < 0) { if((*Clock)->sec>0) (*Clock)->sec--; (*Clock)->tick = display.FPS;}
    if ((*Clock)->sec < 0) { if((*Clock)->min>0) (*Clock)->min--; (*Clock)->sec = 60;}
}

bool check_clock_if_zero(struct clock *Clock) {
    if (Clock->tick<=0 && Clock->sec<=0 && Clock->min<=0) return 1;
    return 0;
}

bool check_with_main_clock(struct clock *Clock) {
    int time1 = Main_clock->min*60*60 + Main_clock->sec*60 + Main_clock->tick;
    int time2 = Clock->min*60*60 + Clock->sec*60 + Clock->tick;

    if (time2 != 0 && time1 % time2 == 0) return 1;
    return 0;
}


char *get_clock_string(struct clock *Clock) {
    char mm[2], ss[2]; //tt[2];
    sprintf(mm, "%d", Clock->min);
    sprintf(ss, "%d", Clock->sec+1);
//    sprintf(tt, "%d", Clock->tick);
    char result[9]="";

    if (Clock->min>=10) strcat(result,mm);
    else { strcat(result,"0"); strcat(result,mm);}
    strcat(result,":");
    if (Clock->sec>=10) strcat(result,ss);
    else { strcat(result,"0"); strcat(result,ss);}
//    strcat(result,":");
//    if (Clock->tick>=10) strcat(result,tt);
//    else { strcat(result,"0"); strcat(result,tt);}


    return strndup( result, 8);
}

void clear_clocks() {
    free(Main_clock);
    free(Level_clock);
    free(Flyer_respawn);
    free(Shooter_respawn);
}
