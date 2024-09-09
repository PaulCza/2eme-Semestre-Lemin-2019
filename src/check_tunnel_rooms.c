/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check_tunnel_rooms
*/

#include <stdlib.h>
#include "lemin.h"

static char **split_alloc_tunnel(char **str, int i)
{
    char **split;
    int j = 0;

    for (int k = i; str[k] != NULL; k++, j++);
    j *= 2;
    split = malloc(sizeof(char *) * (j + 1));
    for (int k = 0; k != j; k++) {
        split[k] = malloc(sizeof(char) * my_strlen(str[i]));
        if (k % 2 == 1)
            i++;
    }
    return (split);
}

static char **split_tunnel(char **str, int i, int n)
{
    char **split = split_alloc_tunnel(str, i);

    for (int k = i; str[k] != NULL; k++) {
        for (int m = 0, j = 0; str[k][m] != '\0'; m++, j++) {
            if (str[k][m] == '-') {
                split[n][j] = '\0';
                n++;
                m++;
                j = 0;
            }
            if (str[k][m + 1] == '\0') {
                split[n][j] = str[k][m];
                split[n][j + 1] = '\0';
                n++;
                break;
            }
            split[n][j] = str[k][m];
        }
    }
    split[n] = NULL;
    return (split);
}

static void cmp_str(values_t *v, char **split, int i)
{
    char **splitbis = split_tunnel(v->str, i, 0);
    int *tab_tn;
    int *tab_r;

    tab_tn = atoi_parsing(splitbis);
    tab_r = atoi_parsing(split);
    for (int k = 0; splitbis[k] != NULL; k++) {
        if (k % 2 == 1)
            i++;
        if (cmp_value(tab_tn[k], tab_r, split)) {
            v->str[i] = NULL;
            v->err_lines = ERROR;
            break;
        }
    }
    free(tab_tn);
    free(tab_r);
    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    for (int i = 0; splitbis[i] != NULL; i++)
        free(splitbis[i]);
}

static char *my_split_special(char *str)
{
    int i = 0;
    char *temp;

    for (i = 0; str[i] != ' '; i++);
    temp = malloc(sizeof(char) * i + 2);
    for (i = 0; str[i] != ' '; i++)
        temp[i] = str[i];
    temp[i] = '\0';
    return (temp);
}

void check_tunnel_rooms(values_t *v)
{
    int i = 1;
    int j = 0;
    char **split;

    for (; j != v->pos_tunnel; j++);
    split = malloc(sizeof(char *) * j);
    for (j = 0; i != v->pos_tunnel; i++, j++) {
        if (v->str[i][0] == '#')
            i++;
        split[j] = my_split_special(v->str[i]);
    }
    split[j] = NULL;
    cmp_str(v, split, v->pos_tunnel);
}
