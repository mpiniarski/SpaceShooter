/*
 * Moduł zawierający funkcje potrzebne do wyświetlania gameplay
 * oraz obsługi gameplay (dodawania nowych obiektów, zdarzeń, przemieszeń obiektów itd.)
 * */
#ifndef _GAMEPLAY_FUNC
#define _GAMEPLAY_FUNC

//Zmienna odpowiadająca za wyjście z gameplay (gdy =1 następuje wyjście)
bool Exit_gameplay;

//Zmienna odpowiadająca za odświeżanie ekranu (gdy =1 następuje odświężenie)
bool Redraw;

//Funckcja odpowiadająca za wyświetlanie obrazu gameplay
void show_gameplay();

//Funckja odpowiadająca za zmianę poziomu w odpowiednim czasie
void level_handle();

//Klawisze klawiatury
enum keys {
    UP, DOWN, LEFT, RIGHT, keys_size
};
//Tablica przechowująca stan klawisza (czy jest wciśniety)
bool Key[keys_size];

//Struktura opisująca każdy obiekt widoczny w grze
    // (gracz, przecinik, strzały itd.) oraz zawiejąca wskaźnik na bitmapę
struct object {
    ALLEGRO_BITMAP *img;
    int width; int height;          //wielkość
    int x; int y;                   // położenie
    int dx; int dy;                 // przesuwanie
    bool attitude;                  // nastawinie z enum attitudes (kolizja między przeciwnymi)
    int ENEMY_TYPE;                 // typ przeciwnika
    int x_ignore; int y_ignore;     // przestrzeń ignorowna przy kolizji
    int animation_state;            // zmienna potrzeban, gdy bitmapa obiektu ma byc animacją
};
enum attitudes {FRIENDLY, HOSTILE};
enum enemy_types {FLYER, SHOOTER};
struct object *Player;
struct object *Flame1; struct object *Flame2;

// Funkcja generująca obiekt struktury definiujący gracza, zwraca wskaźnik na ten obiekt
struct object *spawn_player();
// Funkcja generująca obiekt struktury definiujący płomień, zwraca wskaźnik na ten obiekt
struct object *spawn_flame();

// Funkcja generująca obiekt struktury definiujący strzał, działa względem innego obiektu (Shooter)
    // wygrenerowany obiekt dodaje do listy (shot_list)
void spawn_shot(struct object *Shooter, int Shot_type);

// Funkcja generująca przeciwników,sprawdza czy upłynął wystarczający czas
    // od generacji poprzedniego przeciwnika, by wygenerować następnego
void spawn_enemies();

// Funkcja generująca obiekt struktury definiujący przeciwinka, o określonym typie
    // wygrenerowanegy obiekt dodaje do listy (enemy_list)
void spawn_enemy(int Enemy_type);

// Funkcja generująca obiekt struktury definiujący ekspolzję, działa względem innego obiektu (Destroyed)
    // wygrenerowany obiekt dodaje do listy ekplozji (explosion_list)
void spawn_explosion(struct object *Destroyed);


// Funckja obsługująca przemieszczanie się gracza (oraz płomieni i ich animację)
void move_player();

// Funckja obsługująca przemieszanie się strzałów (wszstkich na liście shoot_list)
void move_shoots();

// Funckja obsługująca przemieszanie się przeciwników (wszstkich na liście enemy_list)
void move_enemies();

// Funckja obsługująca przemieszanie się i animację ekplozji (wszstkich na liście explosion_list)
void move_explosions();

#endif
