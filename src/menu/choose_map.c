/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** choose_map
*/

#include "my_defender.h"

static void display_all(all_t *all, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    for (size_t i = 0; all->map->sprites[i]; i++)
        sfRenderWindow_drawSprite(window, all->map->sprites[i], NULL);
    for (size_t i = 0; all->map->texts[i]; i++)
        sfRenderWindow_drawText(window, all->map->texts[i], NULL);
    RenderWindow_drawAllButtons(window, all->map->buttons);
    sfRenderWindow_display(window);
}

static int select_dificulty(all_t *all, sfRenderWindow *window)
{
    switch (get_button(all->map->buttons, window)) {
    case 0:
        return -1;
    case 1:
        DIFFICULTY->level = 1;
        return 0;
    case 2:
        DIFFICULTY->level = 10;
        return 0;
    case 3:
        DIFFICULTY->level = 20;
        return 0;
    case 4:
        DIFFICULTY->level = 39;
        return 0;
    default:
        return 0;
    }
}

int select_level(all_t *all, sfRenderWindow *window)
{
    while (!is_having_to_close(window)) {
        if (select_dificulty(all, window))
            return 0;
        if (DIFFICULTY->level != -1)
            return 1;
        display_all(all, window);
    }
    return 0;
}