/* Moduł zawierający obsługę zegarów  */

#ifndef _CLOCK
#define _CLOCK

//Strutkra zegara
struct clock{
    int tick;
    int sec;
    int min;
};
struct clock *Main_clock;
struct clock *Level_clock;
struct clock *Flyer_respawn;
struct clock *Shooter_respawn;

// Funcja tworząca obiekt struktury definijący zegar (wyzerowany), zwraca wskaźnik na utworzony obiekt
struct clock *create_clock();
// Funcja wywołująca tworzenie zegarów używanych w grze
void create_clocks();
// Funckcja nastawiająca zegar na określoną wartość
void set_clock(struct clock **Clock, int tick, int sec, int min);
// Funckja powoduje jedno tyknięcie zegara w przód (tyknięcie = 1/FPS sekundny)
void clock_tick(struct clock **Clock);
// Funckja powoduje jedno tyknięcie zegara w tył (tyknięcie = 1/FPS sekundny)
void clock_untick(struct clock **Clock);

// Funcja sprawdzająca czy zegar jest wyzerowany
bool check_clock_if_zero(struct clock *Clock);

// Funcja sprawdzająca czy zegar w danym momecie "pokrywa" się
    // z zegarem głównym gry (czyli czy upłynął odpowiedni okres czasu)
bool check_with_main_clock(struct clock *Clock);

// Funcja zwracająca odczyt z zegara w postaci tablicy znaków
char *get_clock_string(struct clock *Clock);


// Funcja usuwająca zegary używane w grze
void clear_clocks();

#endif
