/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** ennemi
*/

#include "my_defender.h"
#include <stdlib.h>

static int move_ennemi_rect(ennemi_t *ennemi, int state)
{
    sfIntRect rect = sfSprite_getTextureRect(ennemi->sprite);

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(ennemi->clock)) > 200) {
        switch_anim(ennemi->sprite, state * 32);
        if (ennemi->type == troll || ennemi->type == chest || \
            ennemi->type == helmet || ennemi->type == armor) {
            switch_anim(ennemi->sprite, state * 64);
            move_rect(ennemi->sprite, 64, ennemi->doc[ennemi->type][state]);
        } else
            move_rect(ennemi->sprite, 32, ennemi->doc[ennemi->type][state]);
        sfClock_restart(ennemi->clock);
        if (state == 2 && rect.left >= ennemi->doc[ennemi->type][state])
            return -1;
    }
    return 0;
}

static int test_ennemi(ennemi_t *ennemi, tile_t **board)
{
    if (ennemi->pv <= 0) {
        if (move_ennemi_rect(ennemi, 2) == -1) {
            free(ennemi);
            return -1;
        }
        return 3;
    }
    if (ennemi->pos.x < 0)
        return -2;
    if (ennemi->pos.x < 9 && \
    board[ennemi->pos.y][ennemi->pos.x].type != empty) {
        move_ennemi_rect(ennemi, 1);
        return 0;
    }
    return 1;
}

int move_ennemi(ennemi_t *ennemi, tile_t **board)
{
    sfVector2f vector = sfSprite_getPosition(ennemi->sprite);
    int test;

    if (!ennemi)
        return -1;
    ennemi->pos = (sfVector2i) {(vector.x - Boardx) / (Tile_size + 3.5), \
                                (vector.y - Boardy) / Tile_size};
    if ((test = test_ennemi(ennemi, board)) != 1)
        return test;
    move_ennemi_rect(ennemi, 0);
    sfSprite_move(ennemi->sprite, (sfVector2f) {0 - ennemi->speed, 0});
    return 1;
}

void ennemi_spawn(all_t *all)
{
    e_type type;

    if (get_Milliseconds(DIFFICULTY->last_spawn) - \
    sfTime_asMilliseconds(DIFFICULTY->pause_error) > DIFFICULTY->next_spawn) {
        DIFFICULTY->pause_error.microseconds = 0;
        for (int i = 0; i < DIFFICULTY->spawn_rate; i++) {
            if ((type = rdm(0, DIFFICULTY->power + 1)) > 5)
                type = 5;
            if (type > (e_type) DIFFICULTY->level)
                type = (e_type) DIFFICULTY->level;
            add_nod(&all->game->ennemis, create_ennemi(e_getpos, type));
            DIFFICULTY->power = DIFFICULTY->power - type;
            if (DIFFICULTY->power < 0)
                DIFFICULTY->power = 0;
        }
        update_difficulty(all);
    }
}