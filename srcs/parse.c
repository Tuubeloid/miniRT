/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/11 20:24:45 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../parsing.h"

/*	First create reading and validation of element data, if file is valid we create linked list
	nodes for all individual elements and that data will be accessible from a main struct which
	holds pointers to all elements and element lists. */

int ft_atof(char *str)
{
    int i;
    int sign;
    int res;
    int dec;

    i = 0;
    sign = 1;
    res = 0;
    dec = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (str[i] == '.')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        dec++;
        i++;
    }
    while (dec > 0)
    {
        res = res / 10;
        dec--;
    }
    return (res * sign);
}

// index 1 is ratio which should be in range of 0,0 and 1,0
// index 2 is RGB colors which should be in range [0-255]: 255, 255, 255

int a_rgb_check(char *rgb)
{
	char **split;

	split = ft_split(rgb, ',');
	if (split[0] == NULL)
		return (0);
	if (split[1] == NULL)
		return (0);
	if (split[2] == NULL)
		return (0);
	if (ft_atof(split[0]) < 0 || ft_atof(split[0]) > 255)
		return (0);
	if (ft_atof(split[1]) < 0 || ft_atof(split[1]) > 255)
		return (0);
	if (ft_atof(split[2]) < 0 || ft_atof(split[2]) > 255)
		return (0);
	return (1);
}

int decimal_check(char *str)
{
	char **split;

	split = ft_split(str, '.');
	if (split[0] == NULL)
		return (0);
	if (split[1] == NULL)
		return (0);
	if (ft_atof(split[0]) < 0 || ft_atof(split[0]) > 1)
		return (0);
	if (ft_atof(split[1]) < 0 || ft_atof(split[1]) > 0)
		return (0);
	return (1);
}

int parse_ambient(char *line)
{
	char **split;

	split = ft_split(line, ' ');
	printf("%s\n", "test0");
	if (split[0][0] != 'A')
		return (0);
	if (split[1] == NULL)
		return (0);
	if (split[2] == NULL)
		return (0);
	if (split[3] != NULL)
		return (0);
	if (decimal_check(split[1]) == 0)
		return (0);
	if (a_rgb_check(split[2]) == 0)
		return (0);
	return (1);
}

int parse_file(char *line)
{
	if (ft_strncmp(line, "\n", 1) == 0)
		return (1);
    if (ft_strncmp(line, "A", 1) == 0)
        return (parse_ambient(line));
        // func to parse ambient
    if (ft_strncmp(line, "C", 1) == 0)
        return (1);
        // func to parse camera
    if (ft_strncmp(line, "L", 1) == 0)
        return (1);
        // func to parse lightning
    if (ft_strncmp(line, "sp", 2) == 0)
        return (1);
        // func to parse shapes
    if (ft_strncmp(line, "pl", 2) == 0)
        return (1);
        // func to parse shapes
    if (ft_strncmp(line, "cy", 2) == 0)
        return (1);
        // func to parse shapes
    else
        return (0);
}

int main(void)
{
    char *line;
    int     fd;

    fd = open("/home/tvalimak/miniRTparsing/srcs/test.rt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        return (0);
    }
    printf("%d\n", fd);
    line = get_next_line(fd);
    while (line)
    {
        if (parse_file(line) == 0)
        {
            printf("Invalid file\n");
            return (0);
        }
        line = get_next_line(fd);
    }
    printf("File was valid\n");
    return (0);
}
