/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/18 21:16:14 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int read_to_parse(t_element_count *element_count, t_map *map)
{
	int		fd;
	char	*line;

	//fd = open("/home/tvalimak/Hive/miniRTParse/srcs/test.rt", O_RDONLY);
	fd = open("/home/tvalimak/miniRTparsing/srcs/test.rt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error in fd\n");
		return (0);
	}
	printf("%d\n", fd);
	line = get_next_line(fd);
	while (line)
	{
		if (validate_lines(line, element_count, map) == 0)
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
	close(fd);
	return (1);
}

int terminate_data(t_map *map, char *error)
{
    printf("%s", error);
    if (map->ambient)
        free(map->ambient);
    if (map->camera)
        free(map->camera);
    if (map->light)
        free(map->light);
    if (map->sphere)
        free(map->sphere);
    if (map->plane)
        free(map->plane);
    if (map->cylinder)
        free(map->cylinder);
    if (map)
        free(map);
    return (0);
}

int print_raw_data(t_raw_data *raw_data)
{
    printf("Printing raw data\n");
    while (raw_data)
    {
        printf("%s\n", raw_data->line);
        raw_data = raw_data->next;
    }
    printf("End of raw data\n");
    return (1);
}

int	terminate_raw_data(t_raw_data *raw_data)
{
	t_raw_data	*temp;

	while (raw_data)
	{
		temp = raw_data->next;
		free(raw_data->line);
		free(raw_data);
		raw_data = temp;
	}
	return (1);
}

int	setup_data(t_element_count *element_count, t_raw_data *raw_data, t_map *map)
{
	printf("inside setup_data\n");
	map->element_count = element_count;
	map->raw_data = raw_data;
	printf("end of setup_data\n");
	return (1);
}

int main(void)
{
	t_element_count		element_count;
	t_raw_data			*raw_data;
	t_map				*map;

	ft_memset(&element_count, 0, sizeof(t_element_count));
	raw_data = malloc(sizeof(t_raw_data));
	map = malloc(sizeof(t_map));
    if (!raw_data)
    {
        printf("Error in malloc (raw_data)\n");
        return (0);
    }
    raw_data->line = NULL;
    raw_data->next = NULL;
    if (read_to_parse(&element_count, map) == 0)
        return (0);
    print_raw_data(raw_data);
	if (!map)
	{
		printf("Error in malloc (map)\n");
		return (0);
	}
    if (setup_data(&element_count, raw_data, map) == 0)
    {
        printf("Error in setup_data\n");
        return (0);
    }
    if (terminate_raw_data(raw_data) == 0)
        return (0);
    return (0);
}
