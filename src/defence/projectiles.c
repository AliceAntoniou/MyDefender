/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** projectiles
*/

#include "my_defender.h"
#include <stdlib.h>

projectile_t *create_projectile(sfVector2i launch_pos)
{
    projectile_t *proj = malloc(sizeof(projectile_t));
    sfVector2f vector = {launch_pos.x * Tile_size + Boardx + 30, \
                        launch_pos.y * Tile_size + Boardy + 20};

    proj->pos = launch_pos;
    proj->sprite = create_sprite(vector , (sfVector2f) {32, 32}, \
                                            "textures/arrow.png");
    proj->speed = 10;
    proj->damage = 1;
    return proj;
}

int move_projectil(game_t *game, projectile_t *proj)
{
    ennemi_t *ennemi = NULL;
    sfVector2f pos;

    if (!proj)
        return 0;
    pos = sfSprite_getPosition(proj->sprite);
    sfSprite_move(proj->sprite, (sfVector2f) {proj->speed, 0});
    proj->pos.x = (pos.x - Boardx) / Tile_size;
    proj->pos.y = (pos.y - Boardy) / Tile_size;
    parse_list(game->ennemis) {
        ennemi = tmp->data;
        if (ennemi->pos.x == proj->pos.x && ennemi->pos.y == proj->pos.y) {
            ennemi->pv -= proj->damage;
            sfSprite_destroy(proj->sprite);
            free(proj);
            return 0;
        }
        if (proj->pos.x > 12) {
            sfSprite_destroy(proj->sprite);
            free(proj);
            return 0;
        }
    }
    return 1;
}

void update_projectiles(game_t *game)
{
    int index = 0;

    parse_list(game->projectile) {
        if (move_projectil(game, tmp->data) == 0) {
            tmp->data = NULL;
            delete_node(&game->projectile, index);
            return;
        }
        index++;
    } else {
        delete_node(&game->ennemis, index);
        return;
    }
}