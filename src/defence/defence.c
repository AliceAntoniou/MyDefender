/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** defence
*/

#include "my_defender.h"
#include <stdlib.h>

void mine(game_t *game)
{
    ennemi_t *ennemi;

    for_tile_in_board {
        check_state(game, (sfVector2i) {x, y});
        if (tile(x, y).type != empty && \
            get_Milliseconds(tile(x, y).anim) >= 80) {
            anim_defence(&tile(x, y));
        } if (tile(x, y).state == 37)
            parse_list(game->ennemis) {
                ennemi = tmp->data;
                if (KAMI_RANGE)
                    ennemi->pv -= 2;
            }
        if (tile(x, y).type == miner && \
            get_Second(tile(x, y).attack_delay) >= 10) {
            game->money += 25;
            sfClock_restart(tile(x, y).attack_delay);
        }
    } if (get_Second(game->incomes) >= 10) {
        game->money += 25;
        sfClock_restart(game->incomes);
    }
}

void distance_attack(game_t *game, ennemi_t *ennemi)
{
    int limit = ennemi->pos.x;

    if (limit > 9)
        limit = 9;
    for (int i = 0; i < limit; i++) {
        if (tile(i, ennemi->pos.y).type == archer) {
            tile(i, ennemi->pos.y).state = 1;
            if (get_Second(tile(i, ennemi->pos.y).attack_delay) > 2) {
                add_nod(&game->projectile, create_projectile((sfVector2i) \
                    {i, ennemi->pos.y}));
                sfClock_restart(tile(i, ennemi->pos.y).attack_delay);
            }
        }
    }
}

static int defence_effect(game_t *game, sfVector2i pos)
{
    switch (BOARD[pos.y][pos.x].type) {
    case sword:
        return 1;
    default:
        return 0;
    }
}

void attack(game_t *game, ennemi_t *ennemi)
{
    if (get_Second(BOARD[ennemi->pos.y][ennemi->pos.x].defence_delay) >= 2 ||
get_Milliseconds(BOARD[ennemi->pos.y][ennemi->pos.x].defence_delay) <= 1) {
        BOARD[ennemi->pos.y][ennemi->pos.x].pv -= ennemi->damage;
        sfClock_restart(BOARD[ennemi->pos.y][ennemi->pos.x].defence_delay);
    }
    if (get_Second(BOARD[ennemi->pos.y][ennemi->pos.x].attack_delay) < 2)
        return;
    BOARD[ennemi->pos.y][ennemi->pos.x].state = 1;
    ennemi->pv -= defence_effect(game, (sfVector2i) \
                                {ennemi->pos.x, ennemi->pos.y});
    sfClock_restart(BOARD[ennemi->pos.y][ennemi->pos.x].attack_delay);
}

void defence(game_t *game)
{
    int index = 0;

    mine(game);
    parse_list(game->ennemis) {
        switch (move_ennemi(tmp->data, game->board)) {
        case -1:
            tmp->data = NULL;
            delete_node(&game->ennemis, index);
            return;
        case 0:
            distance_attack(game, tmp->data);
            attack(game, tmp->data);
            break;
        case 1:
            distance_attack(game, tmp->data);
            break;
        case -2:
            game->end = 2;
        }
        index++;
    } else {
        delete_node(&game->ennemis, index);
        return;
    }
}