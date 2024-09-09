/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** .h
*/

#ifndef _LEMIN_H_
#define _LEMIN_H_

//////////////////////
//    STRUCTURES    //
//////////////////////
typedef struct values_s
{
    int lines;
    int err_lines;
    int err_cmd;
    int ct;
    int pos_tunnel;
    char **str;
} values_t;

//////////////////////
//  OPEN AND READ   //
//////////////////////
char **read_file(values_t *v);
int first_display(values_t *v);
void check_wrong_cmd(values_t *v);
int check_nbr(char *str);
void check_other_lines(values_t *v);
void check_tunnels(values_t *v);
void del_com(values_t *v);
int found_pos_tunnel(values_t *v);
int multi_cmp(char *str);
void check_cmd(values_t *v);
void check_negative_tunnel(values_t *v);
void check_tunnel_rooms(values_t *v);
int cmp_value(int value, int *room, char **split);
int *atoi_parsing(char **str);

//////////////////////
//  UTIL FUNCTIONS  //
//////////////////////
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_atoi(char const *str);

//////////////////////
//  ERROR MESSAGES  //
//////////////////////
static const char STR_ERROR_ARG[] = "this program takes no arguments\n";

//////////////////////
//  RETURN VALUES   //
//////////////////////
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

#endif
