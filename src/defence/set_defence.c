/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** set_defence
*/

#include "my_defender.h"
#include "param.h"
#include <stdlib.h>

int get_price(d_type type)
{
    switch (type) {
    case shield:
        return price_shield;
    case sword:
        return price_sword;
    case archer:
        return price_archer;
    case miner:
        return price_miner;
    case kamikaze:
        return price_kamikaze;
    default:
        return __INT32_MAX__;
    }
}

static void set_up_defences(game_t *game, tile_t *tile, int index)
{
    switch (game->defences[index - 1]) {
    case miner:
        sfSprite_setScale(tile->sprite, (sfVector2f) {2.1, 2.1});
        tile->pv = 2;
        break;
    case shield:
        tile->pv = 10;
        sfSprite_setScale(tile->sprite, (sfVector2f) {1, 1});
        break;
    case sword:
        tile->pv = 5;
        sfSprite_setScale(tile->sprite, (sfVector2f) {2.1, 2.1});
        break;
    default:
        tile->pv = 2;
        break;
    }
}

static void tile_to_defence(game_t *game, tile_t *tile, int index)
{
    const sfTexture *texture = sfSprite_getTexture(\
                                game->display->sprites[index]);
    sfVector2u size = sfTexture_getSize(texture);
    sfIntRect rect = sfSprite_getTextureRect(game->display->sprites[index]);

    sfSprite_setScale(tile->sprite, (sfVector2f) \
                    {Tile_size / size.x, Tile_size / size.y});
    set_up_defences(game, tile, index);
    sfSprite_setTexture(tile->sprite, texture, 1);
    sfSprite_setTextureRect(tile->sprite, rect);
    if (index == 3 || index == 5)
        sfSprite_setScale(tile->sprite, (sfVector2f) {1, 1});
    tile->type = game->defences[index - 1];
    tile->attack_delay = sfClock_create();
    tile->defence_delay = sfClock_create();
    tile->anim = sfClock_create();
    tile->state = 0;
}

void place_defence(game_t *game, sfRenderWindow *window, int index)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    sfSprite_setPosition(game->display->sprites[index], \
                        (sfVector2f) {40 + Tile_size * index, 10});
    pos.x = (pos.x - Boardx) / Tile_size;
    pos.y = (pos.y - Boardy) / Tile_size;
    if (pos.x < 0 || pos.x >= 9 || pos.y < 0 || pos.y >= 5)
        return;
    if (get_price(game->defences[index - 1]) > game->money)
        return;
    game->money -= get_price(game->defences[index - 1]);
    tile_to_defence(game, &game->board[pos.y][pos.x], index);
}

d_type *fill_characters(void)
{
    d_type *characters = malloc(sizeof(d_type) * 7);

    characters[0] = miner;
    characters[1] = sword;
    characters[2] = archer;
    characters[3] = shield;
    characters[4] = kamikaze;
    characters[5] = empty;
    characters[6] = -1;
    return characters;
}