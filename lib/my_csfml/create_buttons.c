/*
** EPITECH PROJECT, 2021
** my defender
** File description:
** create buttons
*/

#include "my_csfml.h"
#include <stdlib.h>

button_t *create_button(sfFloatRect rectangle, void (*animation)(button_t *), \
                        const char *texture_filename, const char *txt)
{
    button_t *button = malloc(sizeof(button_t));

    button->pos = (sfVector2f) {rectangle.left, rectangle.top};
    button->box = rectangle;
    button->sprite = NULL;
    button->txt = NULL;
    button->animation = animation;
    if (texture_filename)
        button->sprite = create_sprite(button->pos,\
        (sfVector2f) {rectangle.width, rectangle.height}, texture_filename);
    if (txt)
        button->txt = create_text((sfVector2f) {button->pos.x + (rectangle.width / 10), button->pos.y}, txt,\
        (unsigned int) rectangle.height - (rectangle.height / 5), "textures/Alphakind.ttf");
    return button;
}

void RenderWindow_drawButton(sfRenderWindow *window, button_t *button)
{
    if (button->sprite)
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    if (button->txt)
        sfRenderWindow_drawText(window, button->txt, NULL);
    return;
}

static void reset_button(button_t *button)
{
    if (button->sprite)
        sfSprite_setPosition(button->sprite, button->pos);
    if (button->txt) {
        sfText_setColor(button->txt, sfBlack);
        sfText_setPosition(button->txt, (sfVector2f) {button->pos.x + (button->box.width / 10)\
                                                    , button->pos.y});
    }
}

static int button_interact(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    reset_button(button);
    if (sfFloatRect_contains(&button->box, mouse.x, mouse.y)) {
        if (button->animation != NULL)
            button->animation(button);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return 1;
    }
    return 0;
}

int get_button(list_l *buttons, sfRenderWindow *window)
{
    int button_index = 0;

    for (list_l *tmp = buttons; tmp; tmp = tmp->next) {
        if (button_interact(tmp->data, window))
            return button_index;
        button_index++;
    }
    return -1;
}


