/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** init_sprite
*/

#include "my_defender.h"
#include <stdlib.h>

void init_text(display_t *display)
{
    display->texts = malloc(sizeof(sfText *) * 8);
    display->texts[0] = create_text((sfVector2f) \
        {5, 20}, "0", 40, "textures/Alphakind.ttf");
    display->texts[1] = create_text((sfVector2f) \
        {windowx / 2 - 270, windowy / 2 - 60}, "", 60,
        "textures/Alphakind.ttf");
    display->texts[2] = create_text((sfVector2f) \
        {50 + Tile_size * 1, 50}, "50", 25, "textures/Alphakind.ttf");
    display->texts[3] = create_text((sfVector2f) \
        {50 + Tile_size * 2, 50}, "25", 25, "textures/Alphakind.ttf");
    display->texts[4] = create_text((sfVector2f) \
        {50 + Tile_size * 3, 50}, "100", 25, "textures/Alphakind.ttf");
    display->texts[5] = create_text((sfVector2f) \
        {50 + Tile_size * 4, 50}, "50", 25, "textures/Alphakind.ttf");
    display->texts[6] = create_text((sfVector2f) \
        {50 + Tile_size * 5, 50}, "100", 25, "textures/Alphakind.ttf");
    display->texts[7] = NULL;
}

static void init_sprite_2(sfSprite **sprites)
{
    sprites[4] = create_sprite((sfVector2f) {40 + Tile_size * 4, 10}, \
        (sfVector2f) {Tile_size * 16, Tile_size * 2}, "textures/shield.png");
    sfSprite_setTextureRect(sprites[4], (sfIntRect) {0, 0, 64, 64});
    sfSprite_setScale(sprites[4], (sfVector2f) {1, 1});
    sprites[5] = create_sprite((sfVector2f) {40 + Tile_size * 5, 10}, \
                        (sfVector2f) {Tile_size * 82, Tile_size * 6}, \
                                    "textures/magician_kamikaze.png");
    sfSprite_setTextureRect(sprites[5], (sfIntRect) {0, 0, 64, 64});
    sfSprite_setScale(sprites[5], (sfVector2f) {1, 1});
    sprites[6] = NULL;
}

sfSprite **init_display_sprite(void)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 8);

    sprites[0] = create_sprite((sfVector2f) {0, 0}, (sfVector2f) \
                                {windowx, windowy}, "textures/background.png");
    sprites[1] = create_sprite((sfVector2f) {40 + Tile_size * 1, 10}, \
            (sfVector2f) {Tile_size * 15, Tile_size}, "textures/miner.png");
    sfSprite_setTextureRect(sprites[1], (sfIntRect) {224, 0, 32, 32});
    sprites[2] = create_sprite((sfVector2f) {40 + Tile_size * 2, 10}, \
        (sfVector2f) {Tile_size * 7, Tile_size * 3}, "textures/dwarf.png");
    sfSprite_setTextureRect(sprites[2], (sfIntRect) {0, 0, 32, 32});
    sprites[3] = create_sprite((sfVector2f) {40 + Tile_size * 3, 10}, \
    (sfVector2f) {Tile_size * 20, Tile_size * 6}, "textures/Archer.png");
    sfSprite_setTextureRect(sprites[3], (sfIntRect) {0, 0, 64, 64});
    sfSprite_setScale(sprites[3], (sfVector2f) {1, 1});
    init_sprite_2(sprites);
    return sprites;
}