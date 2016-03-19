/*Moduł zawierający funkcje potrzebne do wyświetlania menu/ekranu końca gry*/

#ifndef _MENU_FUNC
#define _MENU_FUNC

//Zmienna odpowiadająca za wyjście z menu (gdy =1 następuje wyjście)
bool Exit_menu;

//Opcje jakie mogą być wskazane przez użytkownika
enum options {
    New_Game, Exit, options_size
};
int Option;

//Funckcja odpowiadająca za wyświetlanie obrazu menu (napisów, bitmap itd.)
void show_menu();

//Funckcja odpowiadająca za wyświetlanie obrazu ekranu końca gry (napisów, bitmap itd.)
void show_after_gameplay();

#endif
