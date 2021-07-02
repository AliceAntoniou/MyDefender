/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** difficulty
*/

#include "param.h"
#include <stdlib.h>

void wave(all_t *all)
{
    if (pre_wave_1 || pre_wave_2) {
        DIFFICULTY->spawn_rate = -1;
        DIFFICULTY->next_spawn = 500;
        sfText_setString(all->game->display->texts[1], "Une vague arrive");
    }
    if (wave_1 || wave_2) {
        DIFFICULTY->spawn_rate = wave_rate;
        DIFFICULTY->next_spawn = 500;
        DIFFICULTY->factor = DIFFICULTY->level + 1.5;
    }
    if (game_end)
        DIFFICULTY->spawn_rate = -1;
}

void update_difficulty(all_t *all)
{
    if (increase_difficulty == 1)
        DIFFICULTY->power++;
    sfClock_restart(DIFFICULTY->last_spawn);
    DIFFICULTY->next_spawn /= spawn_factor;
    if (DIFFICULTY->next_spawn < reset_next_spawn)
        DIFFICULTY->next_spawn = new_next_spawn;
    DIFFICULTY->spawn_rate = 1;
    if (up_rate)
        DIFFICULTY->spawn_rate = classic_rate;
    sfText_setString(all->game->display->texts[1], "");
    wave(all);
}