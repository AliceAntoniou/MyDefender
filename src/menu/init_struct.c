/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** init_struct
*/

#include "my_defender.h"
#include <stdlib.h>

display_t *init_menu(void)
{
    display_t *menu = malloc(sizeof(display_t));

    menu->buttons = NULL;
    ADD_BUTTON(menu->buttons, 0, 400, 270, 50, ANIM_RIGHT, \
                        "textures/button.png", "Select level");
    ADD_BUTTON(menu->buttons, 0, 460, 270, 50, ANIM_RIGHT, \
                        "textures/button.png", "Settings");
    ADD_BUTTON(menu->buttons, 0, 520, 270, 50, ANIM_RIGHT, \
                        "textures/button.png", "Quit game");
    menu->sprites = malloc(sizeof(sfSprite *) * 2);
    menu->sprites[0] = create_sprite((sfVector2f) {0, 0},
        (sfVector2f) {windowx, windowy}, "textures/menu_background.png");
    menu->sprites[1] = NULL;
    menu->texts = NULL;
    menu->textures = NULL;
    return menu;
}

static void init_button_setting(display_t *settings)
{
    ADD_BUTTON(settings->buttons, 300, 640, 424, 50, ANIM_RED, \
                                "textures/button.png", "Return");
    ADD_BUTTON(settings->buttons, 300, 200, 50, 50, ANIM_RED, \
                                    "textures/button.png", "15");
    ADD_BUTTON(settings->buttons, 400, 200, 50, 50, ANIM_RED, \
                                    "textures/button.png", "30");
    ADD_BUTTON(settings->buttons, 500, 200, 50, 50, ANIM_RED, \
                                    "textures/button.png", "60");
    ADD_BUTTON(settings->buttons, 565, 410, 10, 30, NULL, \
                                "textures/button.png", NULL);
}

display_t *init_settings(void)
{
    display_t *settings = malloc(sizeof(display_t));

    settings->buttons = NULL;
    settings->texts = malloc(sizeof(sfText *) * 3);
    settings->texts[0] = create_text((sfVector2f) {20, 200}, "Framerate:"\
                                            , 35, "textures/Alphakind.ttf");
    settings->texts[1] = create_text((sfVector2f) {20, 400}, "Volume:"\
                                            , 35, "textures/Alphakind.ttf");
    settings->texts[2] = NULL;
    settings->sprites = malloc(sizeof(sfSprite *) * 4);
    settings->sprites[0] = create_sprite((sfVector2f) {380, 160}, \
                            (sfVector2f) {110, 110}, "textures/check.png");
    settings->sprites[1] = create_sprite((sfVector2f) {270, 420}, \
                            (sfVector2f) {310, 10}, "textures/button.png");
    settings->sprites[2] = create_sprite((sfVector2f) {0, 0},
        (sfVector2f) {windowx, windowy}, "textures/menu_background.png");
    settings->sprites[3] = NULL;
    init_button_setting(settings);
    return settings;
}

display_t *init_map(void)
{
    display_t *map = malloc(sizeof(display_t));

    map->buttons = NULL;
    map->texts = malloc(sizeof(sfText *) * 1);
    map->texts[0] = NULL;
    map->sprites = malloc(sizeof(sfSprite *) * 2);
    map->sprites[0] = create_sprite((sfVector2f) {0, 0},
        (sfVector2f) {windowx, windowy}, "textures/menu_background.png");
    map->sprites[1] = NULL;
    ADD_BUTTON(map->buttons, 700, 100, 150, 50, ANIM_RED, \
                                "textures/button.png", "Diff 39");
    ADD_BUTTON(map->buttons, 500, 100, 150, 50, ANIM_RED, \
                                "textures/button.png", "Diff 20");
    ADD_BUTTON(map->buttons, 300, 100, 150, 50, ANIM_RED, \
                                "textures/button.png", "Diff 10");
    ADD_BUTTON(map->buttons, 100, 100, 150, 50, ANIM_RED, \
                                "textures/button.png", "Diff 1");
    ADD_BUTTON(map->buttons, 300, 640, 424, 50, ANIM_RED, \
                                "textures/button.png", "Return");
    return map;
}