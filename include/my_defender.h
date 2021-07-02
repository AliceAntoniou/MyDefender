/*
** EPITECH PROJECT, 2021
** my deffender
** File description:
** my_deffender
*/

#ifndef DEFFENDER_H_
#define DEFFENDER_H_

#include "my_csfml.h"

#define Boardx      138
#define Boardy      264
#define Tile_size   66
#define windowx     1024
#define windowy     768

#define DIFFICULTY              all->game->difficulty
#define SETTINGS                all->settings
#define BOARD                   game->board
#define DISPLAY                 all->game->display
#define tile(x, y)              BOARD[y][x]
#define rdm(min, max)           min + rand() % (max - min)
#define freese_time(sftime)     sftime = sfClock_getElapsedTime(all->clock)
#define defreese_time(error, sftime)   (error).microseconds += \
        sfClock_getElapsedTime(all->clock).microseconds - (sftime).microseconds
#define get_time    (sfClock_getElapsedTime(all->clock)).microseconds \
                    - all->clock_error.microseconds
#define new_ennemi(filename, framex, framey) \
    create_sprite((sfVector2f) {pos.x * Tile_size + Boardx, pos.y * Tile_size \
    + Boardy}, (sfVector2f) {Tile_size * framex, Tile_size * framey}, filename)
#define e_LASTSPAWN   sfClock_getElapsedTime(DIFFICULTY->last_spawn)
#define e_getpos  (sfVector2i) {14, rand() % 5}

#define for_tile_in_board   \
    for (int y = 0; y < 5; y++)\
        for (int x = 0; x < 9; x++)
#define parse_list(head)  \
    for (list_l *tmp = head; tmp; tmp = tmp->next)\
        if (tmp->data)
#define KAMI_RANGE      ennemi->pos.x >= x - 1 && ennemi->pos.x <= x + 1 && \
                        ennemi->pos.y >= y - 1 && ennemi->pos.y <= y + 1

typedef enum defence_type
{
    empty,
    miner,
    shield,
    sword,
    archer,
    kamikaze
} d_type;

typedef enum ennemi_type
{
    goblin,
    helmet,
    armor,
    rider,
    troll,
    chest
} e_type;

typedef struct texures_to_display
{
    sfTexture **textures;
    list_l *buttons;
    sfSprite **sprites;
    sfText **texts;
} display_t;

typedef struct tile
{
    sfSprite *sprite;
    d_type type;
    sfClock *attack_delay;
    sfClock *defence_delay;
    int state;
    sfClock *anim;
    int pv;
} tile_t;

typedef struct difficulty
{
    int level;
    int factor;
    int spawn_rate;
    int power;
    int next_spawn;
    sfClock *last_spawn;
    sfTime pause_error;
} difficulty_t;

typedef struct ennemi
{
    sfSprite *sprite;
    sfVector2i pos;
    e_type type;
    sfClock *clock;
    int pv;
    int speed;
    int damage;
    int **doc;
} ennemi_t;

typedef struct projectile
{
    sfSprite *sprite;
    sfVector2i pos;
    int damage;
    int speed;
} projectile_t;

typedef struct main_game
{
    display_t *display;
    d_type *defences;
    tile_t **board;
    difficulty_t *difficulty;
    list_l *ennemis;
    list_l *projectile;
    sfClock *incomes;
    int money;
    int end;
} game_t;

typedef struct all_strucures
{
    display_t *menu;
    display_t *settings;
    display_t *pause;
    display_t *map;
    game_t *game;
    sfClock *clock;
    sfTime clock_error;
    sfTime tmp;
    sfTime time;
    float volume;
} all_t;

static inline void RenderWindow_drawProjectil(sfRenderWindow *window,
    projectile_t *proj) {
    sfRenderWindow_drawSprite(window, proj->sprite, NULL);
}

static inline void RenderWindow_drawEnnemi(sfRenderWindow *window,
    ennemi_t *ennemi) {
    sfRenderWindow_drawSprite(window, ennemi->sprite, NULL);
}

static inline void RenderWindow_drawAllEnnemis(sfRenderWindow* window,
    list_l *ennemis) {
    parse_list(ennemis) {
        RenderWindow_drawEnnemi(window, tmp->data);
    }
}

static inline void RenderWindow_drawAllProjectiles(sfRenderWindow* window,
    list_l *projectile) {
    parse_list(projectile) {
        RenderWindow_drawProjectil(window, tmp->data);
    }
}

static inline void RenderWindow_drawBoard(sfRenderWindow* window,
    tile_t **board) {
    for_tile_in_board {
        sfRenderWindow_drawSprite(window, (board)[y][x].sprite, NULL);
    }
}

static inline void RenderWindow_drawSprites(sfRenderWindow* window,
    sfSprite **sprites) {
    for (size_t i = 1; (sprites)[i]; i++)
        sfRenderWindow_drawSprite(window, (sprites)[i], NULL);
}

static inline void RenderWindow_drawTexts(sfRenderWindow* window,
    sfText **texts) {
    for (size_t i = 0; (texts)[i]; i++)
        sfRenderWindow_drawText(window, (texts)[i], NULL);
}

sfRenderWindow *create_window(void);
int is_having_to_close(sfRenderWindow *window);
int menu(all_t *all, sfRenderWindow *window);
int game(all_t *all, sfRenderWindow *window, sfMusic *);
display_t *init_menu(void);
display_t *init_settings(void);
display_t *init_pause(void);
game_t *init_game(void);
sfSprite **init_display_sprite(void);
void init_text(display_t *display);
void settings(all_t *all, sfRenderWindow *window);
int pause(sfRenderWindow *window, all_t *all, sfMusic *music);
void ennemi_spawn(all_t *all);
int move_ennemi(ennemi_t *ennemi, tile_t **board);
void update_difficulty(all_t *all);
void place_defence(game_t *game, sfRenderWindow *window, int index);
void RenderWindow_drawEnnemi(sfRenderWindow *window, ennemi_t *ennemi);
projectile_t *create_projectile(sfVector2i launch_pos);
void move_projectiles(game_t *game);
void defence(game_t *game);
void update_projectiles(game_t *game);
int get_price(d_type type);
d_type *fill_characters(void);
ennemi_t *create_ennemi(sfVector2i pos, e_type type);
void anim_defence(tile_t *tile);
void check_state(game_t *game, sfVector2i pos);
void free_game(all_t *all);
void free_display(display_t *display);
void get_ennemi_doc(ennemi_t *ennemi);
void display_all_game(sfRenderWindow *window, game_t *main);
void launch_game(all_t *all, sfRenderWindow *window, sfMusic *music);
display_t *init_map(void);
int select_level(all_t *all, sfRenderWindow *window);

#endif /* !DEFFENDER_H_ */
