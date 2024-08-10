/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/10 11:48:57 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int parse_file(char *line)
{
    if (ft_strncmp(line, "A", 1) == 0)
        return (1);
        // func to parse ambiient
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
    return (0);
}

int main(void)
{
    char *line;
    int     fd;

    fd = open("/home/tvalimak/Hive/miniRTParse/test.rt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        if (parse_file(line) == 0)
            printf("Invalid file");
        line = get_next_line(fd);
    }
    printf("File was valid");
    return (0);
}