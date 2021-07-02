/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** difficulty
*/

#ifndef DIFFICULTY_H_
#define DIFFICULTY_H_

#include "my_defender.h"

#define price_miner     50
#define price_sword     25
#define price_archer    100
#define price_shield    50
#define price_kamikaze  100

#define first_spawn             15000
#define start_money             50
#define dificulty               1
#define increase_difficulty     1 + rdm(0, 40 / DIFFICULTY->factor)
#define reset_next_spawn        rdm(1000, 2000)
#define new_next_spawn          rdm(1000, 5000)
#define spawn_factor            1 + DIFFICULTY->factor / 20 
#define up_rate                 rdm(0, 5)
#define classic_rate            rdm(1, 3)
#define wave_rate               rdm(2, 5)
#define pre_wave_1              (sfTime_asSeconds(all->time) > 80 \
                                && sfTime_asSeconds(all->time) < 95)
#define wave_1                  (sfTime_asSeconds(all->time) >= 95 \
                                && sfTime_asSeconds(all->time) < 98)
#define pre_wave_2              (sfTime_asSeconds(all->time) > 160 \
                                && sfTime_asSeconds(all->time) < 175)
#define wave_2                  (sfTime_asSeconds(all->time) >= 175 \
                                && sfTime_asSeconds(all->time) < 180)
#define game_end                sfTime_asSeconds(all->time) >= 180

#endif /* !DIFFICULTY_H_ */
