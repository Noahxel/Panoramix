/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** init_struct
*/

#include "panoramix.h"

void create_common(panoramix_t *pano, int nb_refills)
{
    pano->shared.refills = nb_refills;
    pano->shared.is_druid_cookin = false;
    sem_init(&pano->shared.cook_semaphore, 0, 0);
    sem_init(&pano->shared.vivi_semaphore, 0, 0);

    printf("Druid: I'm ready... but sleepy...\n");
}

void create_villagers(panoramix_t *pano, int nb_fights)
{
    pano->villagers = malloc(sizeof(villager_t) * (pano->nb_villagers + 1));
    for (int i = 0; i < pano->nb_villagers; i++) {
        pano->villagers[i].id = i;
        pano->villagers[i].nb_fight = nb_fights;
        pano->villagers[i].state = THIRSTY;
        pano->villagers[i].shared = &pano->shared;
        printf("Villager %d: Going into battle!\n", i);
    }
}

void init_panoramix_struct(char **argv, panoramix_t *pano)
{
    pano->potSize = atoi(argv[2]);
    pano->nb_villagers = atoi(argv[1]);
    create_common(pano, atoi(argv[4]));
    pano->shared.pot = atoi(argv[2]);
    create_villagers(pano, atoi(argv[3]));
}
