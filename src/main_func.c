/* Libraries */
#include <allegro5/allegro.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
/* Imported modules */
#include "main.h"
/*Exported module */
#include "main_func.h"

//Wrzucanie 2 napisów na stos
void push(char * a, char * b) {
    struct stack *new;
    new = malloc(sizeof(struct stack));
    new->next = options_stack;
    new->name = a;
    new->value = b;
    options_stack = new;
}

//Ściągnięcie ze stosu
struct stack *pull() {
    struct stack * val;
    val = options_stack;
    if (options_stack)
        options_stack  = options_stack->next;
    return val;
}

void load_configuration_file() {
    options_stack = 0;
    char bufor[30];
    char *nazwa=0, *wartosc=0;
    char znak;
    short i=0;
    short eq_found=0;

    FILE* plik;
    if ( !(plik = fopen("configuration", "r") ) ){
        plik = fopen("configuration", "w");
        fprintf(plik,"SCREEN.WIDTH=1280\n"); display.width=1280;
        fprintf(plik,"SCREEN.HEIGHT=720\n"); display.height=720;
        fprintf(plik,"FPS=60\n"); display.FPS = 60;
        fprintf(plik,"VOLUME=80\n"); VOLUME = 80;
        fclose(plik);
    }
    else
    {
        while ( ( znak = (char) fgetc(plik)) != EOF )
        {
            if (znak == '=')
            {
                nazwa = strndup(bufor, i);
                i=0;
                eq_found = 1;
                continue;
            }

            if (znak == '\n')
            {
                if (eq_found == 1)
                {
                    wartosc = strndup(bufor, i);
                    push (nazwa, wartosc);
                }
                else fprintf(stderr, "Błąd podczas wczytywania danych z pliku: %s.\n", strerror(errno));
                i=0;
                eq_found = 0;
                continue;
            }
            bufor[i] = znak;
            i++;
        }

        fclose(plik);

        struct stack *p;
        for (p=pull() ; p != 0; p=pull() )
        {
            if (!strcmp(p->name,"VOLUME")) VOLUME=atoi(p->value);
            else if (!strcmp(p->name,"FPS")) display.FPS=atoi(p->value);
            else if (!strcmp(p->name,"SCREEN.HEIGHT")) display.height=atoi(p->value);
            else if (!strcmp(p->name,"SCREEN.WIDTH")) display.width=atoi(p->value);
            free(p->name);
            free(p->value);
            free(p);
        }
    }

    return;
}
