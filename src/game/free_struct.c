/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** free_struct
*/

#include "my_defender.h"
#include <stdlib.h>

void free_board(game_t *game)
{
    for_tile_in_board {
        sfSprite_destroy(tile(x, y).sprite);
        if (tile(x, y).type != empty) {
            sfClock_destroy(tile(x, y).attack_delay);
            sfClock_destroy(tile(x, y).defence_delay);
        }
    }
    free(game->board);
}

void free_game(all_t *all)
{
    free_board(all->game);
    free_display(all->game->display);
    free(all->game->difficulty);
    free(all->game->defences);
    free(all->game);
}