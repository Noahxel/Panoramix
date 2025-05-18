/*
** EPITECH PROJECT, 2021
** DevPack
** File description:
** project
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <pthread.h>
    #include <semaphore.h>
    #define HELP_MSG "USAGE: ./panoramix <nb_villagers> " \
"<pot_size> <nb_fights> <nb_refills>\n"

typedef enum {
    FIGHTING,
    THIRSTY,
    SLEEPY
} vivi_state_e;

typedef struct common_s {
    int refills;
    pthread_t druid_thread_id;
    sem_t cook_semaphore;
    sem_t vivi_semaphore;
    int pot;
    pthread_mutex_t mutex;
    int is_druid_cookin;
} common_t;

typedef struct villager_s {
    int id;
    int nb_fight;
    vivi_state_e state;
    pthread_t thread_id;
    common_t *shared;
} villager_t;

typedef struct panoramix_s {
    common_t shared;
    villager_t *villagers;
    int potSize;
    int nb_villagers;
    int nb_fights;
} panoramix_t;

void init_panoramix_struct(char **argv, panoramix_t *pano);
void panoramix(panoramix_t *pano);
void *run_villager(villager_t *vivi);
void *run_druid(panoramix_t *pano);

#endif /* !PROJECT_H_ */
