/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/14 16:58:36 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	First create reading and validation of element data, if file is valid we create linked list
	nodes for all individual elements and that data will be accessible from a main struct which
	holds pointers to all elements and element lists. */

// index 1 is ratio which should be in range of 0,0 and 1,0
// index 2 is RGB colors which should be in range [0-255]: 255, 255, 255

int main(void)
{
	char				*line;
	int					fd;
	t_element_count		element_count;

	ft_memset(&element_count, 0, sizeof(t_element_count));
    // fd = open("/home/tvalimak/miniRTparsing/srcs/test.rt", O_RDONLY);
    fd = open("/home/tvalimak/Hive/miniRTParse/srcs/test.rt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        return (0);
    }
    printf("%d\n", fd);
    line = get_next_line(fd);
    while (line)
    {
        if (validate_lines(line, &element_count) == 0)
        {
			free(line);
            printf("Invalid file\n");
            return (0);
        }
		free(line);
        line = get_next_line(fd);
    }
	free(line);
    printf("File was valid\n");
    return (0);
}
