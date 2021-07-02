/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** game
*/

#include "my_defender.h"
#include "param.h"
#include <stdlib.h>

void display_all_game(sfRenderWindow *window, game_t *main)
{
    sfRenderWindow_drawSprite(window, main->display->sprites[0], NULL);
    RenderWindow_drawBoard(window, main->board);
    RenderWindow_drawAllButtons(window, main->display->buttons);
    RenderWindow_drawAllEnnemis(window, main->ennemis);
    RenderWindow_drawSprites(window, main->display->sprites);
    RenderWindow_drawAllProjectiles(window, main->projectile);
    RenderWindow_drawTexts(window, main->display->texts);
    sfRenderWindow_display(window);
}

int use_buttons(all_t *all, sfRenderWindow *window, int button_index)
{
    sfVector2i pos;

    if (button_index == 0)
        return -1;
    if (button_index > 0 && all->game->money >= get_price(
            all->game->defences[button_index - 1])) {
        pos = sfMouse_getPositionRenderWindow(window);
        sfSprite_setPosition(DISPLAY->sprites[button_index],
            (sfVector2f) {pos.x, pos.y});
    }
    if (button_index != -1 && !sfMouse_isButtonPressed(sfMouseLeft)) {
        if (button_index > 0)
            place_defence(all->game, window, button_index);
        return -1;
    }
    return button_index;
}

void update_all(all_t *all, sfRenderWindow *window,
                int *button_index, sfMusic *music)
{
    if (*button_index == -1)
        *button_index = get_button(DISPLAY->buttons, window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) || *button_index == 0) {
        freese_time(all->tmp);
        if (pause(window, all, music) == -1) {
            all->game->end = -1;
            return;
        }
        defreese_time(all->clock_error, all->tmp);
        DIFFICULTY->pause_error = all->clock_error;
    }
    *button_index = use_buttons(all, window, *button_index);
    if (music)
        sfMusic_setVolume(music, all->volume);
    sfText_setString(DISPLAY->texts[0], my_get_unsigned_str(all->game->money));
    ennemi_spawn(all);
    update_projectiles(all->game);
    defence(all->game);
    if (game_end && all->game->ennemis == NULL)
        all->game->end = 1;
}

int game(all_t *all, sfRenderWindow *window, sfMusic *music)
{
    int button_index = -1;
    sfInt64 time = 33000;

    all->game->difficulty->last_spawn = sfClock_create();
    while (sfRenderWindow_isOpen(window) && all->game->end == 0) {
        is_having_to_close(window);
        all->time.microseconds = get_time;
        srand(all->time.microseconds);
        while (all->time.microseconds > time) {
            update_all(all, window, &button_index, music);
            time += 33000;
        }
        display_all_game(window, all->game);
    }
    if (music) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
    return all->game->end;
}