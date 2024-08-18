/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:26:31 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/18 21:26:54 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static t_light	*setup_light_helper(t_map *map)
{
	t_light	*temp;

	if (!map->light->next)
	{
		map->light = malloc(sizeof(t_light));
		map->light->next = NULL;
		if (map->light == NULL)
			return (NULL);
	}
	else
	{
		temp = map->light;
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_light));
		if (temp->next == NULL)
			return (NULL);
		map->light = temp->next;
	}
	if (map->light == NULL)
		return (NULL);
	return (map->light);
}

int	setup_light(char **split, t_map *map)
{
	char	**rgb;

	printf("inside setup_light\n");
	map->light = setup_light_helper(map);
	if (map->light == NULL)
		return (0);
	map->light->id = ft_strdup(split[1]);
	map->light->x = ft_atof(split[2]);
	map->light->y = ft_atof(split[3]);
	map->light->z = ft_atof(split[4]);
	map->light->ratio = ft_atof(split[5]);
	map->light->r = ft_atoi(split[6]);
	map->light->g = ft_atoi(split[7]);
	map->light->b = ft_atoi(split[8]);
	map->light->next = NULL;
	printf("end of setup_light\n");
	return (1);
}
