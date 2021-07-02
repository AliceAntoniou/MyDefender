/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** doc
*/

#include "my_defender.h"
#include <stdlib.h>

void get_ennemi_doc(ennemi_t *ennemi)
{
    int doc[7][3] = {{224, 96, 224},\
                     {256, 128, 448},\
                     {256, 1280, 320},\
                     {224, 224, 224},\
                     {640, 1088, 704},\
                     {320, 640, 576}};
    ennemi->doc = malloc(sizeof(int *) * 8);
    for (size_t i = 0; i < 7; i++) {
        ennemi->doc[i] = malloc(sizeof(int *) * 3);
        for (size_t j = 0; j < 3; j++)
            ennemi->doc[i][j] = doc[i][j];
    }
}