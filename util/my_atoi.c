/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** bistro
*/

int my_getnbr2(char const *str, int j, int s)
{
    long i = 0;

    while (str[j] >= '0' && str[j] <= '9') {
        i = (i * 10) + (str[j] - '0');
        if ((i > 2147483648 && s % 2 == 1) || (i >= 2147483648 && s % 2 == 0))
            return (0);
        j++;
    }
    if (s % 2 == 1)
        return (-i);
    return (i);
}

int my_atoi(char const *str)
{
    int j = 0;
    int s = 0;

    while (str[j] == '+' || str[j] == '-') {
        if (str[j] == '-')
            s++;
        j++;
    }
    return (my_getnbr2(str, j, s));
}
