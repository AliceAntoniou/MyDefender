/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** win_lose
*/

#include "my_defender.h"

void draw_and_display_all(sfRenderWindow *window, sfText *txt,
                            sfSprite *font, button_t *button)
{
    sfRenderWindow_drawSprite(window, font, NULL);
    sfRenderWindow_drawText(window, txt, NULL);
    RenderWindow_drawButton(window, button);
    sfRenderWindow_display(window);
}

void free_and_destroy_all(sfText *txt, sfSprite *font, button_t *button)
{
    sfText_destroy(txt);
    sfSprite_destroy(font);
    free_button(button);
}

void win_lose(all_t *all, sfRenderWindow *window)
{
    sfText *txt = create_text((sfVector2f) {430, 250}, "You lose", 40,
        "textures/Alphakind.ttf");
    sfSprite *font = create_sprite((sfVector2f) {0, 0},
        (sfVector2f) {windowx, windowy}, "textures/smooth_back_font.png");
    list_l *list = NULL;
    button_t *button;

    ADD_BUTTON(list, 400, 400, 224, 50, red_anim,
        "textures/button.png", "Retour");
    button = list->data;
    sfText_setColor(txt, sfRed);
    if (all->game->end == 1)
        sfText_setString(txt, "You win");
    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        if (get_button(list, window) == 0)
            return;
        draw_and_display_all(window, txt, font, button);
    }
    free_and_destroy_all(txt, font, button);
}

void launch_game(all_t *all, sfRenderWindow *window, sfMusic *menu_music)
{
    sfMusic *game_music;

    if (!select_level(all, window))
        return;
    DIFFICULTY->factor = DIFFICULTY->level;
    sfClock_restart(all->clock);
    all->clock_error.microseconds = 0;
    if (menu_music)
        sfMusic_stop(menu_music);
    game_music = play_music("textures/music.wav", all->volume, 0);
    if (game(all, window, game_music) != -1)
        win_lose(all, window);
    free_game(all);
    if (menu_music)
        sfMusic_play(menu_music);
    all->game = init_game();
    DIFFICULTY->level = -1;
}