/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** set_ennemi
*/

#include "my_defender.h"
#include <stdlib.h>

static const char *get_filename(e_type type)
{
    switch (type) {
    case goblin:
        return ("textures/simple_goblin.png");
    case helmet:
        return ("textures/goblin_swordman.png");
    case armor:
        return ("textures/grub.png");
    case rider:
        return ("textures/goblin_rider.png");
    case troll:
        return ("textures/golem.png");
    case chest:
        return ("textures/Chest.png");
    }
    return NULL;
}

static void set_stat_2(ennemi_t *ennemi, sfVector2i pos, e_type type)
{
    switch (type) {
    case rider:
        ennemi->sprite = new_ennemi(get_filename(type), 8, 2);
        ennemi->speed = 7;
        ennemi->damage = 5;
        ennemi->pv = 3;
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 32, 32});
        break;
    case troll:
        ennemi->sprite = new_ennemi(get_filename(type), 36, 6);
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 64, 64});
        sfSprite_setOrigin(ennemi->sprite, (sfVector2f) {0, 32});
        ennemi->damage = 10;
        break;
    default:
        ennemi->sprite = new_ennemi(get_filename(type), 16.5, 4.5);
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 64, 64});
        sfSprite_setOrigin(ennemi->sprite, (sfVector2f) {0, 32});
        ennemi->damage = 5;
        ennemi->speed = 4;
    }
}

static void set_stat_1(ennemi_t *ennemi, sfVector2i pos, e_type type)
{
    switch (type) {
    case goblin:
        ennemi->sprite = new_ennemi(get_filename(type), 8, 3);
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 32, 32});
        ennemi->speed = 3;
        break;
    case helmet:
        ennemi->sprite = new_ennemi(get_filename(type), 18, 6);
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 64, 64});
        sfSprite_setOrigin(ennemi->sprite, (sfVector2f) {0, 32});
        break;
    case armor:
        ennemi->sprite = new_ennemi(get_filename(type), 42, 6);
        sfSprite_setTextureRect(ennemi->sprite, (sfIntRect) {0, 0, 64, 64});
        sfSprite_setOrigin(ennemi->sprite, (sfVector2f) {0, 32});
        break;
    default:
        set_stat_2(ennemi, pos, type);
    }
}

ennemi_t *create_ennemi(sfVector2i pos, e_type type)
{
    ennemi_t *ennemi = malloc(sizeof(ennemi_t));

    if (!ennemi)
        return NULL;
    ennemi->pos = pos;
    ennemi->type = type;
    ennemi->clock = sfClock_create();
    ennemi->pv = (ennemi->type + 1) * 2;
    ennemi->speed = 2;
    ennemi->damage = 1;
    set_stat_1(ennemi, pos, type);
    get_ennemi_doc(ennemi);
    return ennemi;
}