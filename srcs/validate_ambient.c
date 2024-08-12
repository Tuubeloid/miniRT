/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:31 by tvalimak          #+#    #+#             */
/*   Updated: 2024/08/12 19:50:26 by tvalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	validate_ambient(char *line, int i, t_element_count *element_count)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split[0][0] != 'A' || split[0][1] != '\0')
		return (free_split(split));
	while (i < 3)
	{
		if (split[i] == NULL)
			return (free_split(split));
		i++;
	}
	if (split[3] != NULL)
		return (free_split(split));
	if (pos_decimal_check(split[1], 0, 0) == 0)
		return (free_split(split));
	if (rgb_check(split[2], 0, 255) == 0)
		return (free_split(split));
	free_split(split);
	element_count->ambient++;
	return (1);
}