/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** first display
*/

#include <stdlib.h>
#include "lemin.h"

static void display_null(values_t *v)
{
    for (int i = 1; v->str[i] != NULL; i++) {
        my_putstr(v->str[i]);
        my_putchar('\n');
    }
}

static void display_next(values_t *v)
{
    if (found_pos_tunnel(v) == SUCCESS) {
        for (int i = 1; i != v->pos_tunnel; i++) {
            my_putstr(v->str[i]);
            my_putchar('\n');
        }
        my_putstr("#tunnels\n");
        check_negative_tunnel(v);
        check_tunnel_rooms(v);
        for (int i = v->pos_tunnel; v->str[i] != NULL; i++) {
            my_putstr(v->str[i]);
            my_putchar('\n');
        }
        if (v->err_lines != ERROR) {
            my_putstr("#move\n");
        }
    }
}

int first_display(values_t *v)
{
    if (check_nbr(v->str[0]))
        return (ERROR);
    my_putstr(v->str[0]);
    my_putchar('\n');
    my_putstr("#rooms\n");
    check_wrong_cmd(v);
    check_other_lines(v);
    if (v->err_lines == ERROR) {
        display_null(v);
        return (v->err_lines);
    }
    check_tunnels(v);
    check_cmd(v);
    if (v->err_lines == ERROR) {
        display_null(v);
        return (v->err_lines);
    }
    display_next(v);
    return (v->err_lines);
}
