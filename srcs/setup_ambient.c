/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:27:57 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/18 20:28:47 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	setup_ambient(char **split, t_map *map)
{
	char	**rgb;

	printf("inside setup_ambient\n");
	map->ambient = malloc(sizeof(t_ambient));
	if (map->ambient == NULL)
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
