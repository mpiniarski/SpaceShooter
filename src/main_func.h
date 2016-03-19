/*Moduł zawierający funkcje potrzebne do doczytu pliku konfiguracyjnego*/

#ifndef _MAIN_FUNC
#define _MAIN_FUNC

//Funckja wczytująca opcje z pliku konfiguracyjnego "configuration"
void load_configuration_file();

//Strutkura stosu
struct stack
{
    struct stack *next;
    char *name;
    char *value;
};
struct stack *options_stack;

#endif
