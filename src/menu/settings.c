/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** settings
*/

#include "my_defender.h"

static void display_all(sfRenderWindow *window, display_t *display)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, display->sprites[2], NULL);
    sfRenderWindow_drawSprite(window, display->sprites[1], NULL);
    RenderWindow_drawAllButtons(window, display->buttons);
    sfRenderWindow_drawText(window, display->texts[0], NULL);
    sfRenderWindow_drawText(window, display->texts[1], NULL);
    sfRenderWindow_drawSprite(window, display->sprites[0], NULL);
    sfRenderWindow_display(window);
}

static float move_cursor(display_t *settings, sfRenderWindow *window)
{
    sfVector2i mouse;
    sfVector2f pos;

    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (mouse.x > 565)
            mouse.x = 565;
        if (mouse.x < 275)
            mouse.x = 275;
        button_setPosition(settings->buttons->data, \
                            (sfVector2f) {mouse.x, 410});
        display_all(window, settings);
    }
    pos = button_getPosition(settings->buttons->data);
    return ((pos.x - 275) / 3);
}

static int framerate(all_t *all, sfRenderWindow *window)
{
    switch (get_button(SETTINGS->buttons, window)) {
    case 1:
        sfSprite_setPosition(SETTINGS->sprites[0], (sfVector2f) {480, 160});
        sfRenderWindow_setFramerateLimit(window, 60);
        break;
    case 2:
        sfSprite_setPosition(SETTINGS->sprites[0], (sfVector2f) {380, 160});
        sfRenderWindow_setFramerateLimit(window, 30);
        break;
    case 3:
        sfSprite_setPosition(SETTINGS->sprites[0], (sfVector2f) {280, 160});
        sfRenderWindow_setFramerateLimit(window, 15);
        break;
    case 4:
        return 1;
    case 0:
        all->volume = move_cursor(SETTINGS, window);
    }
    return 0;
}

void settings(all_t *all, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        if (framerate(all, window) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return;
        display_all(window, all->settings);
    }
}