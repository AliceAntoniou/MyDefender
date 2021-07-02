/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** window
*/

#include "my_defender.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {windowx, windowy, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                    "My_defender", sfClose, NULL);
    sfVector2i mpos = {1440, 10};

    if (window == NULL)
        return NULL;
    sfRenderWindow_setPosition(window, mpos);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

int is_having_to_close(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}