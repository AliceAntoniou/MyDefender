/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** free_struct
*/

#include "my_defender.h"
#include <stdlib.h>

void free_display(display_t *display)
{
    if (display->buttons) {
        parse_list(display->buttons)
            free_button(tmp->data);
    }
    if (display->sprites) {
        for (size_t i = 0; display->sprites[i]; i++)
            sfSprite_destroy(display->sprites[i]);
        free(display->sprites);
    }
    if (display->texts) {
        for (size_t i = 0; display->texts[i]; i++)
            sfText_destroy(display->texts[i]);
        free(display->texts);
    }
    free(display);
}