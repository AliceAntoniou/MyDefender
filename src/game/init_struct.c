/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** init_struct
*/

#include "my_defender.h"
#include "param.h"
#include <stdlib.h>

display_t *init_pause(void)
{
    display_t *pause = malloc(sizeof(display_t));

    pause->buttons = NULL;
    ADD_BUTTON(pause->buttons, 394, 200, 300, 50, ANIM_RED,
        "textures/button.png", "Continue");
    ADD_BUTTON(pause->buttons, 394, 260, 300, 50, ANIM_RED,
        "textures/button.png", "Back to menu");
    ADD_BUTTON(pause->buttons, 394, 320, 300, 50, ANIM_RED,
        "textures/button.png", "Settings");
    ADD_BUTTON(pause->buttons, 394, 380, 300, 50, ANIM_RED,
        "textures/button.png", "Quit game");
    pause->sprites = NULL;
    pause->texts = NULL;
    pause->textures = NULL;
    return pause;
}

static tile_t **create_board(void)
{
    tile_t **board = malloc(sizeof(tile_t *) * 6);

    for (int y = 0; y < 5; y++) {
        board[y] = malloc(sizeof(tile_t) * 10);
        for (int x = 0; x < 9; x++) {
            board[y][x].sprite = create_sprite((sfVector2f) \
            {Boardx + x * (Tile_size + 3.5), Boardy + y * Tile_size},
                (sfVector2f) {Tile_size, Tile_size}, \
            "textures/empty.png");
            board[y][x].type = empty;
            board[y][x].pv = -1;
            board[y][x].attack_delay = NULL;
            board[y][x].defence_delay = NULL;
            board[y][x].anim = NULL;
        }
        board[y][9] = (tile_t) {0};
    }
    board[5] = NULL;
    return board;
}

static display_t *init_game_display(void)
{
    display_t *display = malloc(sizeof(display_t));

    display->textures = malloc(sizeof(sfTexture *) * 2);
    display->textures[0] = sfTexture_createFromFile(
        "textures/empty.png", NULL);
    display->textures[1] = NULL;
    display->sprites = init_display_sprite();
    display->buttons = NULL;
    init_text(display);
    for (int i = 5; i > 0; i--)
        ADD_BUTTON(display->buttons, 40 + Tile_size * i, 10,
        Tile_size, Tile_size, NULL, "textures/tile.png", NULL);
    ADD_BUTTON(display->buttons, 960, 10, 64, 64, NULL,
            "textures/pause_button.png", NULL);
    return display;
}

static difficulty_t *init_difficulty(void)
{
    difficulty_t *difficulty = malloc(sizeof(difficulty_t));

    difficulty->next_spawn = first_spawn;
    difficulty->power = 0;
    difficulty->spawn_rate = 1;
    difficulty->factor = dificulty;
    difficulty->pause_error.microseconds = 0;
    return difficulty;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->board = create_board();
    game->display = init_game_display();
    game->difficulty = init_difficulty();
    game->ennemis = NULL;
    game->projectile = NULL;
    game->defences = fill_characters();
    game->money = start_money;
    game->incomes = sfClock_create();
    game->end = 0;
    game->money = start_money;
    return game;
}