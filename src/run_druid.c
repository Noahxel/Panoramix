/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** run_druid
*/

#include "panoramix.h"
#include <errno.h>

bool is_everyone_sleeping(panoramix_t *pano)
{
    int sleep_count = 0;

    for (int i = 0; i < pano->nb_villagers; i++) {
        if (pano->villagers[i].state == SLEEPY)
            sleep_count++;
    }
    if (sleep_count == pano->nb_villagers)
        return (true);
    return (false);
}

bool is_druid_pinged(panoramix_t *pano)
{
    struct timespec timeout;
    int sem_wait_result = 0;

    clock_gettime(CLOCK_REALTIME, &timeout);
    timeout.tv_sec += 0;
    timeout.tv_nsec += 100000000;
    sem_wait_result = sem_timedwait(&pano->shared.cook_semaphore, &timeout);
    if (sem_wait_result == -1 && errno == ETIMEDOUT)
        return (false);
    return (true);
}

void *run_druid(panoramix_t *pano)
{
    while (pano->shared.refills > 0 && !is_everyone_sleeping(pano)) {
        if (!is_druid_pinged(pano))
            continue;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
        printf("Beware I can only make %d more refills after this one.\n",
        pano->shared.refills - 1);
        pano->shared.refills--;
        pano->shared.pot = pano->potSize - 1;
        pano->shared.is_druid_cookin = false;
        pthread_mutex_unlock(&pano->shared.mutex);
        sem_post(&pano->shared.vivi_semaphore);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
