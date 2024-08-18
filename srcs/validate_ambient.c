/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:31 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/18 20:30:59 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	validate_ambient(char *line, t_element_count *element_count, t_map *map)
{
	char	**split;

	split = ft_split(line, ' ');
	printf("%s\n%s\n%s", split[0], split[1], split[2]);
	if (split[0][0] != 'A' || split[0][1] != '\0')
		return (free_split(split));
	if (split[1] == NULL || split[2] == NULL || split[3] != NULL)
		return (free_split(split));
	if (pos_decimal_check(split[1]) == 0)
		return (free_split(split));
	if (rgb_check(split[2], 0, 255) == 0)
		return (free_split(split));
	if (setup_ambient(split, map) == 0)
		return (free_split(split));
	free_split(split);
	element_count->ambient++;
	printf("Returning 1 from validate_ambient\n");
	return (1);
}
