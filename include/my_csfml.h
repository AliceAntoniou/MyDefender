/*
** EPITECH PROJECT, 2021
** my defender
** File description:
** buttons
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include "my_lib.h"
#include "SFML/Audio.h"
#include "SFML/System.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"

#define ANIM_RED        &red_anim
#define ANIM_RIGHT      &moveright_anim
#define ANIM_LEFT       &moveleft_anim

#define get_Second(clock)  sfTime_asSeconds(sfClock_getElapsedTime(clock))
#define get_Microseconds(clock)  \
                        sfTime_asMicroseconds(sfClock_getElapsedTime(clock))
#define get_Milliseconds(clock)  \
                        sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

////////////////////////////////////////////////////////////
/// \brief Add a new button_t to a list_l.
///
/// \param list             The head of a list_l (it can be NULL)
/// \param x                the x position of the button (float)
/// \param y                the y position of the button (float)
/// \param size_x           the width of the button (float)
/// \param size_y           the height of the button (float)
/// \param animation        A macro wich define the animation of
///                         the button when mouse pass over it (*f)
/// \param texture_filname  The path of the sprite texture (char *)
/// \param txt              The string wich will be displayed (char *)
///
/// \return A new button_t (NULL if failed)
///
////////////////////////////////////////////////////////////
#define ADD_BUTTON(list, x, y, size_x, size_y, anim, sprite, txt)\
    add_nod(&list, create_button((sfFloatRect) {x, y, size_x, size_y}\
    , anim, sprite, txt));

typedef struct button
{
    sfSprite *sprite;
    sfText *txt;
    sfVector2f pos;
    sfFloatRect box;
    void (*animation)(struct button *);
} button_t;

////////////////////////////////////////////////////////////
/// \brief Create a new sfText.
///
/// \param pos          x and y position of the text
/// \param text         The string wich will be displayed
/// \param size         The size of the text charactere
/// \param font_filname The path of the font
///
/// \return A new sfText (NULL if failed)
///
////////////////////////////////////////////////////////////
sfText *create_text(sfVector2f pos, const char *text, unsigned int size, \
                                    const char *font_filename);

////////////////////////////////////////////////////////////
/// \brief Create a new sfSprite.
///
/// \param pos              x and y position of the sprite (x, y)
/// \param size             The size of the sprite (width, height)
/// \param texture_filname  The path of the sprite texture
///
/// \return A new sfSprite (NULL if failed)
///
////////////////////////////////////////////////////////////
sfSprite *create_sprite(sfVector2f pos, sfVector2f size, \
                        const char *texture_filename);

////////////////////////////////////////////////////////////
/// \brief Create a new button_t.
///
/// \param rectangle        position and size of the button
///                         (x, y, width, height)
/// \param animation        A macro wich define the animation of
///                         the button when mouse pass over it
/// \param texture_filname  The path of the button texture
/// \param txt              The string wich will be displayed
///
/// \return A new button_t (NULL if failed)
///
////////////////////////////////////////////////////////////
button_t *create_button(sfFloatRect rectangle, void (*animation)(button_t *)\
                        , const char *texture_filename, const char *txt);

////////////////////////////////////////////////////////////
/// \brief Create a new sfSound.
///
/// \param sound_filename   The path of the audio file
/// \param volume           A float wich define the volume
///
/// \return A new sfSound (NULL if failed)
///
////////////////////////////////////////////////////////////
sfSound *create_sound(const char *sound_filename, float volume);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target.
///
/// \param renderWindow render window object
/// \param object       Object to draw
///
////////////////////////////////////////////////////////////
void RenderWindow_drawButton(sfRenderWindow *renderWindow, button_t *object);

////////////////////////////////////////////////////////////
/// \brief Draw all buttons to the render-target.
///
/// \param renderWindow render window object
/// \param head         head of a list_l of buttons
///
////////////////////////////////////////////////////////////
static inline void RenderWindow_drawAllButtons(sfRenderWindow *renderWindow, \
                                                list_l *head) {
    for (list_l *tmp = head; tmp; tmp = tmp->next)
        RenderWindow_drawButton(renderWindow, tmp->data);
}

////////////////////////////////////////////////////////////
/// \brief get the index of the pressed button.
///
/// The index will corespond to the last create button and
/// increase by 1 to the first button create
///
/// \param renderWindow render window object
/// \param object       Object to draw
///
/// \return A int superior to 0 (-1 if no button pressed)
///
////////////////////////////////////////////////////////////
int get_button(list_l *buttons, sfRenderWindow *window);

void move_rect(sfSprite *sprite, int offset, int max_value);
void switch_anim(sfSprite *sprite, int y);
void moveright_anim(button_t *button);
void moveleft_anim(button_t *button);
void red_anim(button_t *button);
void free_button(button_t *button);
void button_move(button_t *button, sfVector2f vector);
void button_setPosition(button_t *button, sfVector2f vector);
sfVector2f button_getPosition(button_t *button);
sfMusic *play_music(const char *sound_filename, const float volume, \
                    sfBool loop);

#endif /* !BUTTONS_H */
