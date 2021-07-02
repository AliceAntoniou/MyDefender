/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** anim
*/

#include "my_defender.h"

void check_state(game_t *game, sfVector2i pos)
{
    ennemi_t *ennemi = NULL;
    int limit;

    for_tile_in_board {
        if (tile(pos.x, pos.y).type != kamikaze)
            tile(pos.x, pos.y).state = 0;
        if (tile(pos.x, pos.y).type != empty && tile(pos.x, pos.y).pv <= 0) {
            tile(pos.x, pos.y).type = empty;
            sfSprite_setTexture(tile(pos.x, pos.y).sprite, \
                            game->display->textures[0], 0);
        }
    }
    parse_list(game->ennemis) {
        ennemi = tmp->data;
        limit = ennemi->pos.x;
        if (limit > 9)
            limit = 9;
        if (ennemi->pos.x == pos.x && ennemi->pos.y == pos.y)
            tile(pos.x, pos.y).state = 1;
        for (int i = 0; i < limit; i++)
            if (tile(i, pos.y).type == archer && i == pos.x &&
                ennemi->pos.y == pos.y)
                tile(i, pos.y).state = 1;
    }
}

static void anim_kamikaze(tile_t *tile)
{
    if (tile->state == 0)
        switch_anim(tile->sprite, 64);
    if (tile->state == 40)
        switch_anim(tile->sprite, 128);
    if (tile->state <= 40)
        move_rect(tile->sprite, 64, 2560);
    if (tile->state > 40)
        move_rect(tile->sprite, 64, 786);
    if (tile->state > 51)
        tile->pv = 0;
    tile->state += 1;
}

void anim_defence(tile_t *tile)
{
    switch (tile->type) {
    case miner:
        move_rect(tile->sprite, 32, 448);
        break;
    case sword:
        switch_anim(tile->sprite, 32 * tile->state);
        if (tile->state == 0)
            move_rect(tile->sprite, 32, 128);
        if (tile->state == 1)
            move_rect(tile->sprite, 32, 192);
        break;
    case archer:
        switch_anim(tile->sprite, 64 * tile->state);
        if (tile->state == 0)
            move_rect(tile->sprite, 64, 64);
        if (tile->state == 1)
            move_rect(tile->sprite, 64, 320);
        break;
    case kamikaze:
        anim_kamikaze(tile);
        break;
    case shield:
        move_rect(tile->sprite, 64, 448);
        break;
    default:
        return;
    }
    sfClock_restart(tile->anim);
}