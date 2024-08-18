/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:05:48 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/18 21:18:02 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static t_camera	*setup_camera_helper(t_map *map)
{
	t_camera	*temp;

	if (!map->camera->next)
	{
		map->camera = malloc(sizeof(t_camera));
		map->camera->next = NULL;
		if (map->camera == NULL)
			return (NULL);
	}
	else
	{
		temp = map->camera;
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_camera));
		if (temp->next == NULL)
			return (NULL);
		map->camera = temp->next;
	}
	if (map->camera == NULL)
		return (NULL);
	return (map->camera);
}

int	setup_camera(char **split, t_map *map)
{
	char	**rgb;

	printf("inside setup_camera\n");
	map->camera = setup_camera_helper(map);
	if (map->camera == NULL)
		return (0);
	map->camera->x = ft_atof(split[1]);
	map->camera->y = ft_atof(split[2]);
	map->camera->z = ft_atof(split[3]);
	map->camera->nx = ft_atof(split[4]);
	map->camera->ny = ft_atof(split[5]);
	map->camera->nz = ft_atof(split[6]);
	map->camera->fov = ft_atoi(split[7]);
	map->camera->next = NULL;
	printf("end of setup_camera\n");
	return (1);
}
