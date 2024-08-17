/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/17 22:38:02 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	First create reading and validation of element data, if file is valid we create linked list
	nodes for all individual elements and that data will be accessible from a main struct which
	holds pointers to all elements and element lists. */

// index 1 is ratio which should be in range of 0,0 and 1,0
// index 2 is RGB colors which should be in range [0-255]: 255, 255, 255

int read_to_parse(t_element_count *element_count, t_raw_data *raw_data)
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
		if (validate_lines(line, element_count, raw_data) == 0)
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

int setup_structs(t_element_count *element_count, t_map *map)
{
    map->ambient = ft_calloc(element_count->ambient, sizeof(t_ambient *));
    if (!map->ambient)
        return (terminate_data(map, "Error in malloc (ambient)\n"));
    map->camera = ft_calloc(element_count->camera, sizeof(t_camera *));
    if (!map->camera)
        return (terminate_data(map, "Error in malloc (camera)\n"));
    map->light = ft_calloc(element_count->light, sizeof(t_light *));
    if (!map->light)
        return (terminate_data(map, "Error in malloc (light)\n"));
    map->sphere = ft_calloc(element_count->sphere, sizeof(t_sphere *));
    if (!map->sphere)
        return (terminate_data(map, "Error in malloc (sphere)\n"));
    map->plane = ft_calloc(element_count->plane, sizeof(t_plane *));
    if (!map->plane)
        return (terminate_data(map, "Error in malloc (plane)\n"));
    map->cylinder = ft_calloc(element_count->cylinder, sizeof(t_cylinder *));
    if (!map->cylinder)
        return (terminate_data(map, "Error in malloc (cylinder)\n"));
    return (1);
}

int	setup_data(t_element_count *element_count, t_raw_data *raw_data, t_map *map)
{
	(void)raw_data;
	if (check_element_count(element_count, 1) == 0)
	{
		printf("Error in element count\n");
		return (0);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		printf("Error in malloc (map)\n");
		return (0);
	}
	if (setup_structs(element_count, map) == 0)
		return (0);
	return (1);
}

int main(void)
{
	t_element_count		element_count;
	t_raw_data			*raw_data;
	t_map				*map;

	ft_memset(&element_count, 0, sizeof(t_element_count));
	raw_data = malloc(sizeof(t_raw_data));
    if (!raw_data)
    {
        printf("Error in malloc (raw_data)\n");
        return (0);
    }
	map = malloc(sizeof(t_map));
	if (!map)
	{
		printf("Error in malloc (map)\n");
		return (0);
	}
    raw_data->line = NULL;
    raw_data->next = NULL;
    if (read_to_parse(&element_count, raw_data) == 0)
        return (0);
    if (print_raw_data(raw_data) == 0)
        return (0);
    if (setup_data(&element_count, raw_data, map) == 0)
    {
        printf("Error in setup_data\n");
        return (0);
    }
    if (terminate_raw_data(raw_data) == 0)
        return (0);
    return (0);
}
