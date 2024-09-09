/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat concatenate two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int nbr = 0;
    char *end = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (; dest[nbr] != '\0'; nbr++)
        end[nbr] = dest[nbr];
    for (int i = 0; src[i] != '\0'; i++, nbr++)
        end[nbr] = src[i];
    end[nbr] = '\0';
    return (end);
}
