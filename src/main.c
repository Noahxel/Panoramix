/*
** EPITECH PROJECT, 2021
** DevPack
** File description:
** main
*/

#include "panoramix.h"

void print_help(char *error)
{
    if (!error) {
        printf("USAGE: ./panoramix <nb_villagers>");
        printf(" <pot_size> <nb_fights> <nb_refills>\n");
        exit (0);
    } else {
        write(2, HELP_MSG, strlen(HELP_MSG));
        write(2, error, strlen(error));
        exit (84);
    }
}

void check_args(char **argv)
{
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 ||
        atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0)
        print_help("Values must be > 0.\n");
}

void error_handeling(int argc, char **argv)
{
    if (argc == 2 && (strcmp(argv[1], "-h") == 0))
        print_help(NULL);
    if (argc > 5)
        print_help("Too many arguments.\n");
    if (argc < 5)
        print_help("Not enougth arguments.\n");
    check_args(argv);
}

int main(int argc, char **argv)
{
    panoramix_t pano;

    error_handeling(argc, argv);
    init_panoramix_struct(argv, &pano);
    panoramix(&pano);
    free(pano.villagers);
    return (0);
}
