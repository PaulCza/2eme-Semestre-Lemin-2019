/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check cmd
*/

#include <stdlib.h>
#include "lemin.h"

static void check_next_cmd(values_t *v, int i, char *str)
{
    if (my_strcmp(v->str[i], str)) {
        v->str[i] = NULL;
        v->err_lines = ERROR;
    }
}

static void check_pos_start_end(values_t *v, int id)
{
    if (id == TRUE) {
        for (int i = 1; i != v->pos_tunnel; i++) {
            if (my_strcmp(v->str[i], "##start"))
                check_next_cmd(v, i + 1, "##end");
            if (my_strcmp(v->str[i], "##end"))
                check_next_cmd(v, i + 1, "##start");
                }
            }
    else if (id == FALSE) {
        for (int i = 1; v->str[i] != NULL; i++) {
            if (my_strcmp(v->str[i], "##start"))
                check_next_cmd(v, i + 1, "##end");
            if (my_strcmp(v->str[i], "##end"))
                check_next_cmd(v, i + 1, "##start");
        }
    }
}

static void next_check(values_t *v, int nb)
{
    if (nb != 2 && v->ct == TRUE) {
        v->str[v->pos_tunnel] = NULL;
        v->err_lines = ERROR;
    }
    if (nb == 2) {
        if (v->ct == TRUE)
            check_pos_start_end(v, TRUE);
        else
            check_pos_start_end(v, FALSE);
    }
}

void check_cmd(values_t *v)
{
    int nb = 0;

    if (v->ct == TRUE) {
        found_pos_tunnel(v);
        for (int i = 1; i != v->pos_tunnel; i++) {
            if (my_strcmp(v->str[i], "##start"))
                nb++;
            if (my_strcmp(v->str[i], "##end"))
                nb++;
        }
        next_check(v, nb);
    }
    else {
        for (int i = 1; v->str[i] != NULL; i++) {
            if (my_strcmp(v->str[i], "##start"))
                nb++;
            if (my_strcmp(v->str[i], "##end"))
                nb++;
        }
        next_check(v, nb);
    }
}

void check_wrong_cmd(values_t *v)
{
    for (int i = 0; v->str[i] != NULL; i++)
        if (v->str[i][0] == '#' && multi_cmp(v->str[i]) == FALSE) {
            v->str[i] = NULL;
            v->err_lines = ERROR;
            break;
        }
}
