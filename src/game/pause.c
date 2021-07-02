/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** pause
*/

#include "my_defender.h"

static void display_all(sfRenderWindow *window, display_t *display)
{
    RenderWindow_drawAllButtons(window, display->buttons);
    sfRenderWindow_display(window);
}

static int buttons(all_t *all, sfRenderWindow *window, sfMusic *music)
{
    switch (get_button(all->pause->buttons, window)) {
    case 0:
        sfRenderWindow_close(window);
        return -1;
    case 1:
        settings(all, window);
        if (music)
            sfMusic_setVolume(music, all->volume);
        display_all_game(window, all->game);
        return 0;
    case 2:
        return -1;
    case 3:
        return 1;
    }
    return 0;
}

int pause(sfRenderWindow *window, all_t *all, sfMusic *music)
{
    int rtn = 0;

    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        rtn = buttons(all, window, music);
        if (rtn != 0)
            return rtn;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return 0;
        display_all(window, all->pause);
    }
    return -1;
}