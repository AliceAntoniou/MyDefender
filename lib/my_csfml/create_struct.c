/*
** EPITECH PROJECT, 2021
** my deffender
** File description:
** txt sprite
*/

#include "my_csfml.h"

sfText *create_text(const sfVector2f pos, const char *text, \
                    const unsigned int size, const char *font_filename)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile(font_filename);

    if (txt == NULL || font == NULL)
        return NULL;
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, size);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfText_setString(txt, text);
    return txt;
}

sfSprite *create_sprite(const sfVector2f pos, const sfVector2f size, \
                        const char *texture_filename)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(texture_filename, NULL);
    sfVector2u texture_size;

    if (sprite == NULL || texture == NULL)
        return NULL;
    texture_size = sfTexture_getSize(texture);
    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f) {size.x / texture_size.x, size.y / texture_size.y});
    return sprite;
}

void move_rect(sfSprite *sprite, int offset, int max_value)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.left += offset;
    if (rect.left > max_value) {
        rect.left = 0;
    }
    sfSprite_setTextureRect(sprite, rect);
}

void switch_anim(sfSprite *sprite, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = y;
    sfSprite_setTextureRect(sprite, rect);
}