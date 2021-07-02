/*
** EPITECH PROJECT, 2021
** my deffender
** File description:
** main fonctions
*/

#include "my_defender.h"

int my_defender(void)
{
    sfRenderWindow *window = create_window();
    all_t all;

    all.menu = init_menu();
    all.settings = init_settings();
    all.pause = init_pause();
    all.game = init_game();
    all.map = init_map();
    all.clock = sfClock_create();
    all.clock_error.microseconds = 0;
    all.volume = 100;
    all.game->difficulty->level = -1;
    menu(&all, window);
    free_display(all.menu);
    free_display(all.map);
    free_display(all.pause);
    free_display(all.settings);
    sfRenderWindow_destroy(window);
    return 0;
}