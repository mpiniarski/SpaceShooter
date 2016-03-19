cmake_minimum_required(VERSION 3.2)
project(Space_shooter)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES
    src/gameplay.c
    src/gameplay.h
    src/gameplay_func.c
    src/gameplay_func.h
    src/list.c
    src/list.h
    src/main.c
    src/main.h
    src/main_func.c
    src/main_func.h
    src/menu.c
    src/menu.h
    src/menu_func.c
    src/menu_func.h
    src/clock.h
    src/clock.c
    src/collision.h
    src/collision.c
    src/texts.h
    src/texts.c
    src/bitmaps.h
    src/bitmaps.c
    src/audio.h
    src/audio.c
)

add_executable(Space_shooter ${SOURCE_FILES} )

set(game_LIBS liballegro.so liballegro_dialog.so liballegro_image.so liballegro_font.so liballegro_ttf.so liballegro_primitives.so liballegro_audio.so liballegro_acodec.so)

target_link_libraries(Space_shooter ${game_LIBS})