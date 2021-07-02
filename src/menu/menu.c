/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** menu
*/

#include "my_defender.h"

static void display_all(sfRenderWindow *window, display_t *display)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, *display->sprites, NULL);
    RenderWindow_drawAllButtons(window, display->buttons);
    sfRenderWindow_display(window);
}

static void button(all_t *all, sfRenderWindow *window, sfMusic *music)
{
    switch (get_button(all->menu->buttons, window)) {
    case 0:
        sfRenderWindow_close(window);
        break;
    case 1:
        settings(all, window);
        break;
    case 2:
        launch_game(all, window, music);
        break;
    }
}

int menu(all_t *all, sfRenderWindow *window)
{
    sfMusic *menu_music = play_music("textures/menu.wav", all->volume, 1);

    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        if (menu_music)
            sfMusic_setVolume(menu_music, all->volume);
        button(all, window, menu_music);
        display_all(window, all->menu);
    }
    free_game(all);
    if (menu_music) {
        sfMusic_stop(menu_music);
        sfMusic_destroy(menu_music);
    }
    return 0;
}