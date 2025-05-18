/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix
*/

#include "panoramix.h"

void run_actions(panoramix_t *pano)
{
    for (int i = 0; i < pano->nb_villagers; i++) {
        pthread_create(&pano->villagers[i].thread_id, NULL,
        (void *(*)(void *))run_villager, &pano->villagers[i]);
    }
    pthread_create(&pano->shared.druid_thread_id, NULL,
    (void *(*)(void *))run_druid, pano);
}

void panoramix(panoramix_t *pano)
{
    pthread_mutex_init(&pano->shared.mutex, NULL);

    run_actions(pano);
    for (int i = 0; i < pano->nb_villagers; i++)
        pthread_join(pano->villagers[i].thread_id, NULL);
    pthread_join(pano->shared.druid_thread_id, NULL);
    pthread_mutex_destroy(&pano->shared.mutex);
    sem_destroy(&pano->shared.cook_semaphore);
    sem_destroy(&pano->shared.vivi_semaphore);
}
