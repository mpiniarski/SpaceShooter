/* Moduł zawierający głowną pętlę gry, oraz zmienne ogólnie dostępne w każdym innym module */

#ifndef _MAIN
#define _MAIN

//Zmienna odpowiadająca za wyjście z gry (gdy =1 następuje wyjście)
bool Exit_game;

//Timer sterujący odświeżaniem ekranu w całej grze
ALLEGRO_TIMER *main_timer;

//Struktura zawierajaca dane o oknie gry oraz wzsaznik na to okno
typedef struct {
    ALLEGRO_DISPLAY *view;
    int height;
    int width;
    int FPS;
} disp_data;
disp_data display;

//Tryby w jakich może znajdowac się gra (do sterowania między menu, grą i ekranem końca gry)
enum game_modes {
    MENU, GAMEPLAY, AFTER_GAMEPLAY
};
int GAME_MODE;

//Punkty zdobyte w trakcie gry
int POINTS;
//Głośność gry
int VOLUME;
//Obecnego poziomu
int LEVEL;

#endif
