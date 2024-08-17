/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:26:47 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/17 23:46:16 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

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

int	setup_ambient(t_map *map, char *line)
{
	char	**split;
	char	**rgb;

	printf("inside setup_ambient\n");
	map->ambient = malloc(sizeof(t_ambient));
	if (map->ambient == NULL)
		return (0);
	split = ft_split(line, ' ');
	if (split == NULL)
		return (0);
	rgb = ft_split(split[2], ',');
	if (rgb == NULL)
	{
		free(split);
		return (0);
	}
	map->ambient->ratio = ft_atof(split[1]);
	map->ambient->r = ft_atoi(rgb[0]);
	map->ambient->g = ft_atoi(rgb[1]);
	map->ambient->b = ft_atoi(rgb[2]);
	free(rgb);
	free(split);
	printf("%f\n%d\n%d\n%d\n", map->ambient->ratio, map->ambient->r, map->ambient->g, map->ambient->b);
	printf("end of setup_ambient\n");
	return (1);
}

int	setup_camera(t_map *map, char *line)
{
	t_camera	*new_camera;
	char		**split;

	new_camera = malloc(sizeof(t_camera));
	if (new_camera == NULL)
		return (0);
	if (map->camera == NULL)
		map->camera = new_camera;
	else
	{
		while (map->camera->next != NULL)
			map->camera = map->camera->next;
		map->camera->next = new_camera;
		map->camera = new_camera;
	}
	split = ft_split(line, ' ');
	map->camera->split = split;
	map->camera->x = ft_atof(split[1]);
	map->camera->y = ft_atof(split[2]);
	map->camera->z = ft_atof(split[3]);
	map->camera->nx = ft_atof(split[4]);
	map->camera->ny = ft_atof(split[5]);
	map->camera->nz = ft_atof(split[6]);
	map->camera->fov = ft_atoi(split[7]);
	map->camera->next = NULL;
	return (1);
}

int	setup_lists(t_map *map)
{
	printf("inside setup_lists\n");
	while (map->raw_data)
	{
		printf("inside while loop in setup_lists\n");
		printf("%s\n", map->raw_data->line);
		if (ft_strncmp(map->raw_data->line, "A", 1) == 0)
			return (setup_ambient(map, map->raw_data->line));
		else if (ft_strncmp(map->raw_data->line, "C", 1) == 0)
			return (setup_camera(map, map->raw_data->line));
		printf("end of while loop in setup_lists\n");
		map->raw_data = map->raw_data->next;
	}
	printf("end of setup_lists\n");
	return (1);
}

int	setup_data(t_element_count *element_count, t_raw_data *raw_data, t_map *map)
{
	printf("inside setup_data\n");
	map->element_count = element_count;
	map->raw_data = raw_data;
	if (setup_lists(map) == 0)
		return (0);
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
    if (!raw_data)
    {
        printf("Error in malloc (raw_data)\n");
        return (0);
    }
    raw_data->line = NULL;
    raw_data->next = NULL;
    if (read_to_parse(&element_count, raw_data) == 0)
        return (0);
    print_raw_data(raw_data);
	map = malloc(sizeof(t_map));
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
