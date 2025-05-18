/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** run_villager
*/

#include "panoramix.h"

void villager_drink(villager_t *vi)
{
    pthread_mutex_lock(&vi->shared->mutex);
    if (vi->shared->pot >= 0) {
        printf("Villager %d: I need a drink... I see %d servings left.\n",
        vi->id, vi->shared->pot);
        vi->shared->pot--;
        vi->state = FIGHTING;
    }
    if (vi->shared->pot == -1 && vi->shared->refills > 0) {
        if (vi->shared->is_druid_cookin == false) {
            vi->shared->is_druid_cookin = true;
            printf("Villager %d: Hey Pano wake up! We need more potion.\n",
            vi->id);
            vi->state = FIGHTING;
            pthread_mutex_unlock(&vi->shared->mutex);
            sem_post(&vi->shared->cook_semaphore);
            sem_wait(&vi->shared->vivi_semaphore);
        }
        return;
    }
    pthread_mutex_unlock(&vi->shared->mutex);
}

void villager_fight(villager_t *vi)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    vi->id, vi->nb_fight - 1);
    vi->nb_fight--;
    vi->state = THIRSTY;
}

void asleep_villager(villager_t *vi)
{
    pthread_mutex_lock(&vi->shared->mutex);
    if ((vi->nb_fight == 0 || (vi->shared->refills <= 0 &&
        vi->shared->pot <= -1)) && vi->state != FIGHTING) {
        printf("Villager %d: I'm going to sleep now.\n", vi->id);
        vi->state = SLEEPY;
    }
    pthread_mutex_unlock(&vi->shared->mutex);
}

void *run_villager(villager_t *vi)
{
    while (vi->state != SLEEPY) {
        asleep_villager(vi);
        if (vi->state == THIRSTY) {
            villager_drink(vi);
            continue;
        }
        if (vi->state == FIGHTING)
            villager_fight(vi);
    }
    return (NULL);
}
